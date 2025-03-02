#include "musicPlayer.h"
#include "ui_musicPlayer.h"

MusicPlayer::MusicPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);

    this->setObjectName("mainWindow");

    // 禁止改变窗口尺寸
    this->setFixedSize(this->geometry().size());

    // 去掉标题
    this->setWindowFlag(Qt::FramelessWindowHint);

    // 初始化播放器和音频输出
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // 初始化设置窗口
    settingsDialog = nullptr;

    // 设置初始音量
    ui->volumeSlider->setValue(30);
    audioOutput->setVolume(0.3);

    // 总时长
    connect(player, &QMediaPlayer::durationChanged, this, &MusicPlayer::updateDuration);

    // 初始化进度条
    ui->progressSlider->setMinimum(0);
    ui->progressSlider->setValue(0);
    // 更新进度条
    connect(player, &QMediaPlayer::durationChanged, this, &MusicPlayer::updateDuration);
    connect(player, &QMediaPlayer::positionChanged, this, &MusicPlayer::updateProgress);
    connect(ui->progressSlider, &QSlider::sliderPressed, this, &MusicPlayer::onSliderPressed);
    connect(ui->progressSlider, &QSlider::sliderReleased, this, &MusicPlayer::onSliderReleased);
    connect(ui->progressSlider, &QSlider::valueChanged, this, &MusicPlayer::onSliderValueChanged);

    //连接歌词进度
    initLyricStyle();
    connect(player, &QMediaPlayer::positionChanged, this, &MusicPlayer::updateLyric);
    // 更新背景
    connect(settingsDialog, &Settings::backgroundChanged, this, [this]() {
        update();
        repaint();
    });

    // 设置播放列表为不可编辑
    ui->musicList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 安装事件过滤器
    qApp->installEventFilter(this);
    // 本地歌曲路径
    musicListPath = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation)
                    + "/LocalMusic/musiclist.json";

    // 确保目录存在
    QDir dir(QFileInfo(musicListPath).path());
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    scrollTimer = new QTimer(this);
    connect(scrollTimer, &QTimer::timeout, this, &MusicPlayer::scrollText);
    scrollTimer->setInterval(SCROLL_INTERVAL);
    scrollPosition = 0;

    // 播放列表
    musicModel = new QStandardItemModel(this);
    ui->musicList->setModel(musicModel);

    // 设置主界面文字颜色
    QSettings settings("iyl", "MusicPlayer");
    QString textColor = settings.value("app/textColor", "white").toString();
    m_textColor = QColor(textColor);

    this->setStyleSheet(QString("#mainWindow, #mainWindow * { color: %1; }").arg(textColor));
}

MusicPlayer::~MusicPlayer()
{
    if (scrollTimer) {
        scrollTimer->stop();
    }
    delete ui;
}

void MusicPlayer::paintEvent(QPaintEvent *paint)
{
    QPainter painter(this);

    // 每次绘制时从设置中读取最新的背景图片路径
    QSettings settings;
    QString backgroundPath = settings.value("app/background", ":/images/prefix1/images/2.jpg").toString();

    // 绘制背景
    QPixmap backgroundPixmap(backgroundPath);
    if (!backgroundPixmap.isNull()) {
        painter.drawPixmap(0, 0, width(), height(), backgroundPixmap);
    } else {
        // 如果图片无效，使用默认背景
        painter.drawPixmap(0, 0, width(), height(), QPixmap(":/images/prefix1/images/2.jpg"));
    }
}

void MusicPlayer::on_closeButton_clicked()
{
    close();
}

// 鼠标拖动窗口实现移动
void MusicPlayer::mouseMoveEvent(QMouseEvent *event)
{
    if(ispressed)
    {
        QPoint movePos = event->globalPos(); // 窗口初始位置
        move(movePos - movepoint);
    }
}

// 按下
void MusicPlayer::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        ispressed = true;
        // 窗口移动距离
        movepoint = event->globalPos() - pos();
    }
}

// 释放
void MusicPlayer::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    ispressed = false;
}

// 最小化
void MusicPlayer::on_minButton_clicked()
{
    this->showMinimized();
}

// 播放/暂停
void MusicPlayer::on_playButton_clicked()
{
    if(!isplaying)
    {
        player->play();
        ui->playButton->setIcon(QIcon(":/images/prefix1/images/pause.png"));
        isplaying = true;
    }
    else
    {
        player->pause();
        ui->playButton->setIcon(QIcon(":/images/prefix1/images/play.png"));
        isplaying = false;
    }
}

// 音量
void MusicPlayer::on_volumeSlider_valueChanged(int volume)
{
    audioOutput->setVolume(volume / 100.0);
}

// 进度条
void MusicPlayer::onSliderPressed()
{
    userSeeking = true;
}

void MusicPlayer::onSliderReleased()
{
    userSeeking = false;
    player->setPosition(ui->progressSlider->value());
}

// 修改当前时间
void MusicPlayer::onSliderValueChanged(int value)
{
    if (userSeeking) {
        QTime currentTime(0, (value / 60000) % 60, (value / 1000) % 60);
        ui->currentTimeLabel->setText(currentTime.toString("mm:ss"));
    }
}

// 自动更新进度条
void MusicPlayer::updateProgress(qint64 position)
{
    if (!userSeeking) {  // 只有在用户不拖动时才更新进度条
        ui->progressSlider->setValue(position);
        QTime currentTime(0, (position / 60000) % 60, (position / 1000) % 60);
        ui->currentTimeLabel->setText(currentTime.toString("mm:ss"));
    }
}

// 更新总时长标签
void MusicPlayer::updateDuration(qint64 duration)
{
    ui->progressSlider->setMaximum(duration);

    // 更新总时间标签
    QTime totalTime(0, (duration / 60000) % 60, (duration / 1000) % 60);
    ui->totalTimeLabel->setText(totalTime.toString("mm:ss"));
}

// 开启/关闭静音
void MusicPlayer::on_volumeButton_clicked()
{
    if(!isMuted){
        preVolume = audioOutput->volume();
        isMuted = true;
        audioOutput->setVolume(0);
        ui->volumeButton->setIcon(QIcon(":/images/prefix1/images/columeOff.png"));
        ui->volumeSlider->setValue(0);
    }
    else{
        audioOutput->setVolume(preVolume);
        isMuted = false;
        ui->volumeButton->setIcon(QIcon(":/images/prefix1/images/colume.png"));
        ui->volumeSlider->setValue(preVolume * 100);
    }
}

void MusicPlayer::on_addButton_clicked()
{
    // 先隐藏列表，防止文件对话框被挡住
    listContainer->hide();
    isLocalMusicListVisible = false;

    // 打开文件选择对话框
    QStringList musicFiles = QFileDialog::getOpenFileNames(
        this,
        tr("选择音乐文件"),
        QDir::homePath(),  // 默认打开用户主目录
        tr("音频文件 (*.mp3 *.wav *.flac *.m4a);;所有文件 (*)")
        );

    // 如果用户选择了文件
    if (!musicFiles.isEmpty()) {
        for (const QString &filePath : musicFiles){
            // 获取文件信息
            QFileInfo fileInfo(filePath);
            QString fileName = fileInfo.fileName();  // 获取文件名

            // 添加到播放列表的 QListWidget 中
            QListWidgetItem *item = new QListWidgetItem(fileName);
            item->setData(Qt::UserRole, filePath);  // 存储完整路径
            localMusicList->addItem(item);
        }
    }
    // 保存
    saveMusicList();
    // 文件选择对话框关闭后，重新显示列表
    QPoint pos = ui->localMusicListButton->mapToGlobal(
        QPoint(-listContainer->width(), -listContainer->height())
        );

    // 检查是否会超出屏幕左边界
    if(pos.x() < 0) {
        pos.setX(ui->localMusicListButton->mapToGlobal(QPoint(0, 0)).x());
    }

    // 检查是否会超出屏幕顶部
    if(pos.y() < 0) {
        pos.setY(ui->localMusicListButton->mapToGlobal(
                                             QPoint(0, ui->localMusicListButton->height())).y());
    }

    listContainer->move(pos);
    listContainer->show();
    isLocalMusicListVisible = true;
}

void MusicPlayer::on_localMusicListButton_clicked()
{
    if(!listContainer){
        // 创建容器窗口
        container = new QWidget(this);
        container->setWindowFlags(Qt::Popup);

        // 创建垂直布局并设置边距和间距
        QVBoxLayout *layout = new QVBoxLayout(container);
        layout->setContentsMargins(10, 10, 10, 10);  // 设置边距
        layout->setSpacing(5);  // 设置部件之间的间距

        // 创建顶部水平布局
        QHBoxLayout *topLayout = new QHBoxLayout();
        topLayout->setContentsMargins(0, 0, 0, 0);  // 设置边距为0
        topLayout->setSpacing(5);  // 设置间距

        // 创建标题标签
        QLabel *titleLabel = new QLabel("本地歌曲", container);
        titleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);  // 设置左对齐且垂直居中

        // 创建添加按钮
        addButton = new QPushButton("+", container);
        addButton->setFixedSize(24, 24);
        addButton->setStyleSheet(
            "QPushButton {"
            "    color: lightblue;"
            "    font-size: 18px;"
            "    font-weight: 700;"
            "}"
            "QPushButton:hover {"
            "    color: #87CEFA;"
            "}"
            );

        // 将标题和按钮添加到顶部布局
        topLayout->addWidget(titleLabel, 1);  // 添加拉伸因子1
        topLayout->addWidget(addButton, 0);   // 添加拉伸因子0

        // 创建列表
        localMusicList = new QListWidget(container);

        // 播放本地音乐
        connect(localMusicList, &QListWidget::itemDoubleClicked, this, &MusicPlayer::onLocalMusicDoubleClicked);

        // 读取歌曲
        loadMusicList();

        // 将顶部布局和列表添加到主布局
        layout->addLayout(topLayout, 0);      // 添加拉伸因子0，保持最小高度
        layout->addWidget(localMusicList, 1);  // 添加拉伸因子1，允许拉伸

        // 设置容器大小
        container->setFixedSize(250, 350);  // 固定大小，防止大小改变

        // 连接添加按钮信号
        connect(addButton, &QPushButton::clicked, this, &MusicPlayer::on_addButton_clicked);

        listContainer = container;

        // 设置样式
        container->setStyleSheet(
            "QWidget { "
            "background-color: white;"
            "color: black;"
            "}"
            "QLabel { color: black; font-size: 14px; font-weight: bold; }"
            "QPushButton {"
            "    color: lightblue;"
            "    font-size: 18px;"
            "    font-weight: bold;"
            "    border: 1px solid grey;"
            "    border-radius: 12px"
            "}"
            "QPushButton:hover {"
            "    color: #87CEFA;"
            "}"
            "QListWidget { border: 1px solid gray; }"
            );
    }

    if(!isLocalMusicListVisible){
        QPoint pos = ui->localMusicListButton->mapToGlobal(
            QPoint(-listContainer->width(), -listContainer->height())
            );

        // 检查是否会超出屏幕左边界
        if(pos.x() < 0) {
            // 如果会超出左边界，就显示在按钮右边
            pos.setX(ui->localMusicListButton->mapToGlobal(QPoint(0, 0)).x());
        }

        // 检查是否会超出屏幕顶部
        if(pos.y() < 0) {
            pos.setY(ui->localMusicListButton->mapToGlobal(
                                                 QPoint(0, ui->localMusicListButton->height())).y());
        }
        listContainer->move(pos);
        listContainer->show();
        isLocalMusicListVisible = true;
    } else {
        listContainer->hide();
        isLocalMusicListVisible = false;
    }
}

// 点击其他区域关闭列表
bool MusicPlayer::eventFilter(QObject *watched, QEvent *event)
{
    if (isLocalMusicListVisible && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (!listContainer->geometry().contains(mouseEvent->globalPos())) {
            listContainer->hide();
            isLocalMusicListVisible = false;
        }
    }
    return QObject::eventFilter(watched, event);
}

// 保存本地歌曲
void MusicPlayer::saveMusicList()
{
    QJsonArray musicArray;

    // 遍历列表中的所有歌曲
    for(int i = 0; i < localMusicList->count(); i++) {
        QListWidgetItem *item = localMusicList->item(i);
        QJsonObject musicObject;
        musicObject["name"] = item->text();
        musicObject["path"] = item->data(Qt::UserRole).toString();
        musicArray.append(musicObject);
    }

    QJsonDocument document(musicArray);
    QFile file(musicListPath);

    if (file.open(QIODevice::WriteOnly)) {
        file.write(document.toJson());
        file.close();
    } else {
        QMessageBox::warning(this, tr("保存失败"),
                             tr("无法保存播放列表: %1").arg(file.errorString()));
        qDebug() << "Failed to save music list:" << file.errorString();
        return;
    }
}

// 加载保存的本地歌曲
void MusicPlayer::loadMusicList()
{
    QFile file(musicListPath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to load music list:" << file.errorString();
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(data);
    if (document.isArray()) {
        QJsonArray musicArray = document.array();

        for (const QJsonValue &value : musicArray) {
            QJsonObject musicObject = value.toObject();
            QString name = musicObject["name"].toString();
            QString path = musicObject["path"].toString();

            // 检查文件是否还存在
            if (QFile::exists(path)) {
                QListWidgetItem *item = new QListWidgetItem(name);
                item->setData(Qt::UserRole, path);
                localMusicList->addItem(item);
            }
        }
    }
}

// 双击播放本地音乐
void MusicPlayer::onLocalMusicDoubleClicked(QListWidgetItem *item)
{
    // 获取播放路径
    QString filepath = item->data(Qt::UserRole).toString();

    // 重置滚动相关的变量
    scrollPosition = 0;
    textWidth = 0;
    scrollOffset = 0;

    // 设置默认显示信息
    QFileInfo fileInfo(filepath);
    fullTitle = fileInfo.baseName();

    // 绘制标题和作者信息
    updatenonscrollText();
    drawAuthorLabel();

    // 连接元数据信号
    updateMetadata();

    // 播放
    player->setSource(QUrl::fromLocalFile(filepath));
    player->play();

    // 更改播放图标
    ui->playButton->setIcon(QIcon(":/images/prefix1/images/pause.png"));
    isplaying = true;

    // 添加到播放列表
    addToPlaylist(filepath);
}

// 双击播放 播放列表中的音乐
void MusicPlayer::on_musicList_doubleClicked(const QModelIndex &index)
{
    // 获取播放路径
    QString filepath = musicModel->data(index, Qt::UserRole).toString();

    // 重置滚动相关的变量
    scrollPosition = 0;
    textWidth = 0;
    scrollOffset = 0;

    // 设置默认显示信息
    QFileInfo fileInfo(filepath);
    fullTitle = fileInfo.baseName();

    // 绘制标题和作者信息
    updatenonscrollText();
    drawAuthorLabel();

    // 连接元数据信号
    updateMetadata();

    // 播放
    player->setSource(QUrl::fromLocalFile(filepath));
    player->play();

    // 更改播放图标
    ui->playButton->setIcon(QIcon(":/images/prefix1/images/pause.png"));
    isplaying = true;
}

// 连接信号并获取元数据
void MusicPlayer::updateMetadata()
{
    // 断开之前的信号连接，防止重复连接
    disconnect(player, &QMediaPlayer::metaDataChanged, nullptr, nullptr);
    // 连接元数据信号
    connect(player, &QMediaPlayer::metaDataChanged, this, [this]() {
        // 获取标题
        fullTitle = player->metaData().value(QMediaMetaData::Title).toString();
        if(fullTitle.isEmpty()) {
            fullTitle = "未知歌曲";
        }

        // 获取艺术家
        QString artist = player->metaData().value(QMediaMetaData::AlbumArtist).toString();
        if(artist.isEmpty()) {
            artist = player->metaData().value(QMediaMetaData::ContributingArtist).toString();
        }
        if(artist.isEmpty()) {
            artist = player->metaData().value(QMediaMetaData::Author).toString();
        }
        if(artist.isEmpty()) {
            artist = "未知歌手";
        }
        m_currentArtist = artist;

        updatenonscrollText();
        updateAuthorLabel();
        displayAlbumCover();

        // 计算是否需要滚动
        QFontMetrics fm(ui->titleLabel->font());
        textWidth = fm.horizontalAdvance(fullTitle);  // 直接给类成员变量赋值
        int labelWidth = ui->titleLabel->width();

        // 设置是否需要滚动的标志
        needScroll = (textWidth > labelWidth);

        // 根据标志决定是否启动滚动
        if (needScroll) {
            if (!scrollTimer->isActive()) {
                scrollTimer->start(SCROLL_INTERVAL);
            }
        } else {
            scrollTimer->stop();
        }
    });
}

// 绘制作者信息
void MusicPlayer::drawAuthorLabel()
{
    if (m_currentArtist.isEmpty()) return;

    int authorwidth = ui->authorLabel->width();
    QPixmap pixmap(authorwidth, ui->authorLabel->height());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setFont(ui->authorLabel->font());
    painter.setPen(m_textColor);
    painter.drawText(QRect(0, 0, authorwidth, ui->authorLabel->height()),
                     Qt::AlignLeft | Qt::AlignVCenter,
                     m_currentArtist);

    ui->authorLabel->setPixmap(pixmap);
}

// 更新作者信息
void MusicPlayer::updateAuthorLabel()
{
    updateMetadata();
    drawAuthorLabel();
}

// 非滚动标题的显示
void MusicPlayer::updatenonscrollText()
{
    int labelWidth = ui->titleLabel->width();
    QPixmap pixmap(labelWidth, ui->titleLabel->height());
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setFont(ui->titleLabel->font());
    painter.setPen(m_textColor);
    QRect textRect = QRect(0, 0, labelWidth, ui->titleLabel->height());
    painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, fullTitle);
    ui->titleLabel->setPixmap(pixmap);
}

// 标题滚动显示
void MusicPlayer::scrollText()
{
    if (fullTitle.isEmpty() || !needScroll) return;

    QFontMetrics fm(ui->titleLabel->font());

    // 滚动文本的处理
    QString displayText = fullTitle + "     " + fullTitle;
    int labelWidth = ui->titleLabel->width();

    QPixmap pixmap(labelWidth, ui->titleLabel->height());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setFont(ui->titleLabel->font());
    painter.setPen(m_textColor);

    int fullWidth = fm.horizontalAdvance(displayText);

    painter.drawText(QRect(-scrollOffset, 0, fullWidth, ui->titleLabel->height()),
                     Qt::AlignLeft | Qt::AlignVCenter,
                     displayText);

    ui->titleLabel->setPixmap(pixmap);

    scrollOffset = (scrollOffset + 1) % (textWidth + fm.horizontalAdvance("     "));
}

// 添加到播放列表
void MusicPlayer::addToPlaylist(const QString &songPath)
{
    // 检测重复添加
    QModelIndexList matches = musicModel->match(
        musicModel->index(0, 0),  // 从第一行第一列开始搜索
        Qt::UserRole,             // 搜索UserRole数据
        songPath,                 // 要匹配的值
        1,                        // 限制匹配数量为1个
        Qt::MatchExactly          // 精确匹配
        );

    if(matches.isEmpty()) {
        QStandardItem *item = new QStandardItem;
        QFileInfo fileinfo(songPath);
        item->setText(fileinfo.fileName());
        item->setData(songPath, Qt::UserRole);
        musicModel->insertRow(0, item);
    }
    else {
        int oldRow = matches.first().row();
        QStandardItem *item = musicModel->takeItem(oldRow);
        musicModel->removeRow(oldRow);
        musicModel->insertRow(0, item);
    }
}

// 播放列表中的下一首
void MusicPlayer::on_nextButton_clicked()
{
    // 获取当前播放歌曲路径
    QString currentPath = player->source().toLocalFile();
    QModelIndexList matches = musicModel->match(
        musicModel->index(0, 0),
        Qt::UserRole,
        currentPath,
        1,
        Qt::MatchExactly
        );
    if(!matches.empty()){
        // 获取当前播放歌曲位置
        int currentRow = matches.first().row();
        int nextRow = currentRow + 1;
        // 如果是最后一首歌，切换到第一首
        if(nextRow >= musicModel->rowCount()){
            nextRow = 0;
        }
        QStandardItem *nextItem = musicModel->item(nextRow);
        if(nextItem) {
            QString nextPath = nextItem->data(Qt::UserRole).toString();
            player->setSource(QUrl::fromLocalFile(nextPath));
            player->play();

            ui->playButton->setIcon(QIcon(":/images/prefix1/images/pause.png"));
            isplaying = true;
        }
    }
}

// 播放列表中的上一首
void MusicPlayer::on_prevButton_clicked()
{
    QString currentPath = player->source().toLocalFile();
    QModelIndexList matches = musicModel->match(
        musicModel->index(0, 0),
        Qt::UserRole,
        currentPath,
        1,
        Qt::MatchExactly
        );
    if(!matches.empty()){
        int currentRow = matches.first().row();
        int prevRow = currentRow - 1;
        // 如果是第一首歌，切换到末尾
        if(prevRow < 0){
            prevRow = musicModel->rowCount() - 1;
        }
        QStandardItem *prevItem = musicModel->item(prevRow);
        if(prevItem){
            QString prevPath = prevItem->data(Qt::UserRole).toString();
            player->setSource(QUrl::fromLocalFile(prevPath));
            player->play();

            ui->playButton->setIcon(QIcon(":/images/prefix1/images/pause.png"));
            isplaying = true;
        }
    }
}

// 打开设置界面
void MusicPlayer::on_optionsButton_clicked()
{
    if(!settingsDialog){
        settingsDialog = new Settings(nullptr);
        connect(settingsDialog, &Settings::textColorChanged, this, [this](const QColor &color) {
            // 更新主窗口文字颜色
            this->setStyleSheet(QString("#mainWindow, #mainWindow * { color: %1; }").arg(color.name()));
            QSettings settings("iyl", "MusicPlayer");
            m_textColor = settings.value("app/textColor", "white").toString();
            updatenonscrollText();
            updateAuthorLabel();
        });
    }

    settingsDialog->show();
}

// 显示歌曲封面
void MusicPlayer::displayAlbumCover()
{
    // 获取封面图像数据
    QVariant coverData = player->metaData().value(QMediaMetaData::CoverArtImage);
    ui->albumCover->clear();

    QPixmap finalPixmap(ui->albumCover->size());
    finalPixmap.fill(Qt::transparent); // 使背景透明

    QPixmap sourcePixmap;
    bool hasValidCover = false;

    // 加载封面
    if (coverData.isValid()) {
        // 处理不同类型的图像数据
        if (coverData.canConvert<QImage>()) {
            sourcePixmap = QPixmap::fromImage(coverData.value<QImage>());
            hasValidCover = true;
        } else if (coverData.canConvert<QByteArray>()) {
            QByteArray imageData = coverData.value<QByteArray>();
            hasValidCover = sourcePixmap.loadFromData(imageData);
        }
    }

    // 如果没有有效封面，使用默认图像
    if (!hasValidCover || sourcePixmap.isNull()) {
        sourcePixmap = QPixmap(":/images/prefix1/images/defaultCover.png");
    }

    // 确保源图像有效
    if (!sourcePixmap.isNull()) {
        // 缩放图像以适应目标大小，保持比例
        sourcePixmap = sourcePixmap.scaled(
            ui->albumCover->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            );

        // 创建圆角效果
        QPainter painter(&finalPixmap);
        painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

        QPainterPath path;
        int radius = 15; // 圆角半径，可以调整
        path.addRoundedRect(
            0, 0,
            finalPixmap.width(), finalPixmap.height(),
            radius, radius
            );

        // 设置裁剪路径
        painter.setClipPath(path);

        // 计算居中位置
        int x = (finalPixmap.width() - sourcePixmap.width()) / 2;
        int y = (finalPixmap.height() - sourcePixmap.height()) / 2;

        // 绘制图像
        painter.drawPixmap(x, y, sourcePixmap);

        // 添加边框
        painter.setPen(QPen(QColor(255, 255, 255, 60), 1));
        painter.drawPath(path);
    }

    // 设置最终图
    ui->albumCover->setPixmap(finalPixmap);
}

//导入并解析歌词文件
void MusicPlayer::on_pushButton_clicked() {
    QSettings settings("iyl", "MusicPlayer");
    QString lastLyricPath = settings.value("app/lastLyricPath", QDir::homePath()).toString();

    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("打开歌词文件"),
        lastLyricPath,
        tr("歌词文件 (*.lrc)")
        );
    if (fileName.isEmpty()) return;

    QFileInfo fileInfo(fileName);
    settings.setValue("app/lastLyricPath", fileInfo.absolutePath());

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("错误"), tr("无法打开歌词文件"));
        return;
    }

    // 清空旧数据
    m_lyrics.clear();
    lyricTimes.clear();
    lyricTexts.clear();
    m_translationLyrics.clear(); // 存储翻译

    QTextStream stream(&file);
    QString content = stream.readAll().replace("\r", ""); // 处理Windows换行符
    QStringList lines = content.split('\n', Qt::SkipEmptyParts);

    QRegularExpression timeTagRx(R"(\[(\d{2}):(\d{2})\.(\d{2,3})\])");
    QRegularExpression infoTagRx(R"(\[(ar|ti|al|by|offset|re|ve):.+\])");

    QMap<qint64, QString> tempOriginalLyrics;  // 原文
    QMap<qint64, QString> tempTranslationLyrics; // 翻译

    bool isTranslationLine = false;
    QString previousLyricText;
    qint64 previousStartTime = 0;

    qDebug() << "开始解析歌词文件:" << fileName;
    qDebug() << "总行数:" << lines.size();

    for (int i = 0; i < lines.size(); i++) {
        const QString &line = lines[i];

        // 跳过元信息行
        if (infoTagRx.match(line).hasMatch()) {
            continue;
        }

        // 查找时间标签
        QRegularExpressionMatchIterator timeIt = timeTagRx.globalMatch(line);
        if (!timeIt.hasNext()) {
            continue;
        }

        // 提取行文本（去除时间标签）
        QString fullLineText = line;
        fullLineText.remove(timeTagRx);
        fullLineText = fullLineText.trimmed();

        if (fullLineText.isEmpty()) {
            continue;
        }

        // 判断是否是翻译行
        isTranslationLine = false;

        // 检查当前行是否是翻译行
        // 1. 查看是否包含中文字符
        static QRegularExpression chineseRx("[\u4e00-\u9fa5]");
        if (chineseRx.match(fullLineText).hasMatch()) {
            isTranslationLine = true;
        }

        // 2. 检查上一行的开始时间是否与当前行相同
        timeIt = timeTagRx.globalMatch(line);
        QRegularExpressionMatch firstTimeMatch = timeIt.next();
        int minutes = firstTimeMatch.captured(1).toInt();
        int seconds = firstTimeMatch.captured(2).toInt();
        QString msStr = firstTimeMatch.captured(3);
        int milliseconds = (msStr.length() == 2) ? msStr.toInt() * 10 : msStr.toInt();
        qint64 startTime = minutes * 60000 + seconds * 1000 + milliseconds;

        // 如果这一行和上一行的起始时间相同，且上一行不是翻译行，则当前行很可能是翻译
        if (i > 0 && !previousLyricText.isEmpty() && startTime == previousStartTime && !previousLyricText.contains("[]")) {
            isTranslationLine = true;
        }

        // 提取完整时间段
        timeIt = timeTagRx.globalMatch(line);
        qint64 firstTime = 0;
        qint64 lastTime = 0;

        // 获取第一个时间点
        if (timeIt.hasNext()) {
            QRegularExpressionMatch match = timeIt.next();
            minutes = match.captured(1).toInt();
            seconds = match.captured(2).toInt();
            msStr = match.captured(3);
            milliseconds = (msStr.length() == 2) ? msStr.toInt() * 10 : msStr.toInt();
            firstTime = minutes * 60000 + seconds * 1000 + milliseconds;
        }

        // 查找最后一个时间点
        while (timeIt.hasNext()) {
            QRegularExpressionMatch match = timeIt.next();
            minutes = match.captured(1).toInt();
            seconds = match.captured(2).toInt();
            msStr = match.captured(3);
            milliseconds = (msStr.length() == 2) ? msStr.toInt() * 10 : msStr.toInt();
            lastTime = minutes * 60000 + seconds * 1000 + milliseconds;
        }

        // 如果只有一个时间点，使用它作为最后时间点
        if (lastTime == 0) {
            lastTime = firstTime;
        }

        // 保存当前行信息，用于下一行判断
        previousLyricText = fullLineText;
        previousStartTime = firstTime;

        // 根据是否是翻译行存储到不同的Map
        if (isTranslationLine) {
            tempTranslationLyrics.insert(firstTime, fullLineText);
        } else {
            tempOriginalLyrics.insert(firstTime, fullLineText);
        }
    }

    file.close();

    // 检查是否成功解析到歌词
    if (tempOriginalLyrics.isEmpty() && tempTranslationLyrics.isEmpty()) {
        QMessageBox::information(this, tr("提示"), tr("未在文件中找到有效歌词"));
        return;
    }

    // 将临时Map转换为最终的MultiMap
    // 优先使用翻译，如果翻译不存在则使用原文
    QList<qint64> allTimes;
    allTimes.append(tempOriginalLyrics.keys());
    allTimes.append(tempTranslationLyrics.keys());
    std::sort(allTimes.begin(), allTimes.end());
    allTimes.erase(std::unique(allTimes.begin(), allTimes.end()), allTimes.end());

    for (qint64 time : allTimes) {
        if (m_lyricStyle.showTranslation && tempTranslationLyrics.contains(time)) {
            m_lyrics.insert(time, tempTranslationLyrics[time]);
            m_translationLyrics.insert(time, tempTranslationLyrics[time]);
        } else if (tempOriginalLyrics.contains(time)) {
            m_lyrics.insert(time, tempOriginalLyrics[time]);
        }
    }

    // 生成排序后的时间列表
    lyricTimes = m_lyrics.keys();
    std::sort(lyricTimes.begin(), lyricTimes.end());

    // 生成对应的歌词文本列表
    lyricTexts.clear();
    for (qint64 t : lyricTimes) {
        lyricTexts.append(m_lyrics.value(t));
    }

    qDebug() << "最终歌词行数:" << lyricTexts.size();

    // 在UI显示歌词
    updateLyricDisplay();
}

// 歌词滚动显示
void MusicPlayer::updateLyric(qint64 position) {
    if (lyricTimes.isEmpty() || lyricTexts.isEmpty()) return;

    // 二分查找当前歌词行
    auto it = std::upper_bound(lyricTimes.begin(), lyricTimes.end(), position);
    int currentIndex = (it != lyricTimes.begin()) ? (it - lyricTimes.begin() - 1) : 0;

    // 确保索引在有效范围内
    currentIndex = qBound(0, currentIndex, lyricTexts.size() - 1);

    // 如果当前行没有变化，不需要更新UI
    static int lastIndex = -1;
    if (currentIndex == lastIndex) return;
    lastIndex = currentIndex;

    // 更新文本颜色
    QTextCursor cursor(ui->lyric->document());
    QTextCharFormat activeFormat, normalFormat;

    // 使用设置的颜色
    activeFormat.setForeground(m_lyricStyle.activeColor);
    normalFormat.setForeground(m_lyricStyle.textColor);

    // 加粗当前行
    activeFormat.setFontWeight(QFont::Bold);
    normalFormat.setFontWeight(QFont::Normal);

    // 增加当前行字体大小
    QFont activeFont = ui->lyric->font();
    activeFont.setPointSize(m_lyricStyle.fontSize + 1);
    activeFormat.setFont(activeFont);

    // 更新所有行的颜色
    QTextBlockFormat centerFormat;
    centerFormat.setAlignment(m_lyricStyle.alignment);

    for (int i = 0; i < lyricTexts.size(); ++i) {
        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::NextBlock, QTextCursor::MoveAnchor, i);
        cursor.select(QTextCursor::BlockUnderCursor);

        // 设置对齐方式和颜色
        cursor.setBlockFormat(centerFormat);
        cursor.setCharFormat(i == currentIndex ? activeFormat : normalFormat);
    }

    // 创建一个光标定位到当前播放行
    QTextCursor viewCursor(ui->lyric->document());
    viewCursor.movePosition(QTextCursor::Start);
    viewCursor.movePosition(QTextCursor::NextBlock, QTextCursor::MoveAnchor, currentIndex);

    // 先将光标移到当前行
    ui->lyric->setTextCursor(viewCursor);

    // 确保当前行在视图区域中可见
    ui->lyric->ensureCursorVisible();

    // 使用垂直滚动条确保当前行居中显示
    QScrollBar *vScrollBar = ui->lyric->verticalScrollBar();
    if (vScrollBar) {
        // 获取当前行在视图中的高度
        QRect cursorRect = ui->lyric->cursorRect();
        int lineHeight = cursorRect.height();

        // 计算视图的一半高度
        int viewportHeight = ui->lyric->viewport()->height();
        int halfViewport = viewportHeight / 2;

        // 计算需要滚动的额外距离，使当前行居中
        int extraScroll = halfViewport - lineHeight / 2 - cursorRect.y();

        // 应用滚动
        vScrollBar->setValue(vScrollBar->value() - extraScroll);
    }

    // 使光标可见但不闪烁
    ui->lyric->setCursorWidth(0);
}

// 更新歌词显示
void MusicPlayer::updateLyricDisplay() {
    if (lyricTexts.isEmpty()) return;

    ui->lyric->clear();

    // 使用设置的歌词颜色
    QTextCharFormat defaultFormat;
    defaultFormat.setForeground(m_lyricStyle.textColor);

    // 设置字体大小
    QFont font = ui->lyric->font();
    font.setPointSize(m_lyricStyle.fontSize);
    ui->lyric->setFont(font);

    QTextCursor cursor(ui->lyric->document());

    // 初始化歌词显示，每行一个歌词
    for (int i = 0; i < lyricTexts.size(); ++i) {
        if (i > 0) {
            cursor.insertBlock(); // 插入新行
        }
        cursor.insertText(lyricTexts[i], defaultFormat);
    }

    // 设置文本对齐方式
    QTextBlockFormat blockFormat;
    blockFormat.setAlignment(m_lyricStyle.alignment);
    blockFormat.setLineHeight(150, QTextBlockFormat::ProportionalHeight); // 设置行高为正常的1.5倍

    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(blockFormat);

    // 重置文档修改状态，避免*号显示
    ui->lyric->document()->setModified(false);

    // 设置只读，防止用户编辑
    ui->lyric->setReadOnly(true);

    // 设置背景为透明
    QPalette p = ui->lyric->palette();
    p.setColor(QPalette::Base, Qt::transparent);
    ui->lyric->setPalette(p);

    // 取消滚动条边框
    ui->lyric->setFrameShape(QFrame::NoFrame);
}

// 设置歌词样式
void MusicPlayer::setLyricStyle(const LyricStyle &style) {
    m_lyricStyle = style;

    // 如果已经加载了歌词，更新显示
    if (!lyricTexts.isEmpty()) {
        updateLyricDisplay();
        // 触发当前歌词高亮
        updateLyric(player->position());
    }
}

// 初始化默认歌词样式
void MusicPlayer::initLyricStyle() {
    // 默认样式设置
    m_lyricStyle.textColor = Qt::black;       // 普通歌词颜色
    m_lyricStyle.activeColor = Qt::red;       // 当前播放歌词颜色
    m_lyricStyle.showTranslation = true;      // 优先显示翻译
    m_lyricStyle.alignment = Qt::AlignCenter; // 居中对齐
    m_lyricStyle.fontSize = 15;               // 字体大小
}
