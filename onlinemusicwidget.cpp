#include "onlinemusicwidget.h"
#include "ui_onlinemusicwidget.h"

OnlineMusicWidget::OnlineMusicWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OnlineMusicWidget)
{
    ui->setupUi(this);

    //禁止改变窗口尺寸
    this->setFixedSize(this->geometry().size());
    //去掉标题
    this->setWindowFlag(Qt::FramelessWindowHint);

    //初始化播放器和音频输出
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    //初始化设置窗口
    settingsDialog = nullptr;

    //设置初始音量
    ui->volumeSlider->setValue(30);
    audioOutput->setVolume(0.3);

    //总时长
    connect(player, &QMediaPlayer::durationChanged, this, &OnlineMusicWidget::updateDuration);

    //初始化进度条
    ui->progressSlider->setMinimum(0);
    ui->progressSlider->setValue(0);
    // 更新进度条
    connect(player, &QMediaPlayer::durationChanged, this, &OnlineMusicWidget::updateDuration);
    connect(player, &QMediaPlayer::positionChanged, this, &OnlineMusicWidget::updateProgress);
    connect(ui->progressSlider, &QSlider::sliderPressed, this, &OnlineMusicWidget::onSliderPressed);
    connect(ui->progressSlider, &QSlider::sliderReleased, this, &OnlineMusicWidget::onSliderReleased);
    connect(ui->progressSlider, &QSlider::valueChanged, this, &OnlineMusicWidget::onSliderValueChanged);

    //更新背景
    connect(settingsDialog, &Settings::backgroundChanged, this, [this]() {
        update();
        repaint();
    });

    //安装事件过滤器
    qApp->installEventFilter(this);
    //本地歌曲路径
    musicListPath = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation)
                    + "/LocalMusic/musiclist.json";

    // 确保目录存在
    QDir dir(QFileInfo(musicListPath).path());
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    scrollTimer = new QTimer(this);
    connect(scrollTimer,&QTimer::timeout,this,&OnlineMusicWidget::scrollText);
    scrollTimer->setInterval(SCROLL_INTERVAL);
    scrollPosition = 0;

    //播放列表
    musicModel = new QStandardItemModel(this);
    ui->musicList->setModel(musicModel);

    //在构造函数中添加测试代码
    //player->setSource(QUrl::fromLocalFile("D:\\songs\\电台节目\\白fi - 噗妮露是可爱史莱姆 ED「唱」.mp3"));
}

OnlineMusicWidget::~OnlineMusicWidget()
{
    if (scrollTimer) {
        scrollTimer->stop();
    }
    delete ui;
}

void OnlineMusicWidget::paintEvent(QPaintEvent *paint)
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
void OnlineMusicWidget::on_closeButton_clicked()
{
    close();
}

//音乐下载和播放
void OnlineMusicWidget::DownloadPlayer(QString songId)
{
    // 网易云音乐的API地址
    // 这里使用的是获取音乐URL的API
    QString url = "http://music.163.com/api/song/url?id=" + songId + "&br=320000";

    // 也可以同时获取歌曲详细信息
    QString detailUrl = "http://music.163.com/api/song/detail?ids=[" + songId + "]";

    // 发起网络请求获取音乐数据
    HttpAccessFunc(url);
    HttpAccessFunc(detailUrl);
}

//访问HTTP网页
void OnlineMusicWidget::HttpAccessFunc(QString)
{

}
// //解析album_id和hash(使用JSON)
// void OnlineMusicWidget::HashJsonAnalysis(QByteArray)
// {

// }
// //搜索音乐数据信息的JSON解析，解析出真正的音乐文件和歌词
// QString MusicJsonAnalysis(QByteArray)
// {

// }
//鼠标拖动窗口实现移动
void OnlineMusicWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(ispressed)
    {
        QPoint movePos = event->globalPos();//窗口初始位置
        move(movePos - movepoint);
    }
}
//按下
void OnlineMusicWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        ispressed = true;
        //窗口移动距离
        movepoint = event->globalPos() - pos();
    }
}
//释放
void OnlineMusicWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    ispressed = false;
}


//最小化
void OnlineMusicWidget::on_minButton_clicked()
{
    this->showMinimized();
}

//播放/暂停
void OnlineMusicWidget::on_playButton_clicked()
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

//音量
void OnlineMusicWidget::on_volumeSlider_valueChanged(int volume)
{
    audioOutput->setVolume(volume / 100.0);
}

//#进度条
void OnlineMusicWidget::onSliderPressed()
{
    userSeeking = true;
}

void OnlineMusicWidget::onSliderReleased()
{
    userSeeking = false;
    player->setPosition(ui->progressSlider->value());
}

//修改当前时间
void OnlineMusicWidget::onSliderValueChanged(int value)
{
    if (userSeeking) {
        QTime currentTime(0, (value / 60000) % 60, (value / 1000) % 60);
        ui->currentTimeLabel->setText(currentTime.toString("mm:ss"));
    }
}

//自动更新进度条
void OnlineMusicWidget::updateProgress(qint64 position)
{
    if (!userSeeking) {  // 只有在用户不拖动时才更新进度条
        ui->progressSlider->setValue(position);
        QTime currentTime(0, (position / 60000) % 60, (position / 1000) % 60);
        ui->currentTimeLabel->setText(currentTime.toString("mm:ss"));
    }
}
//更新总时长标签
void OnlineMusicWidget::updateDuration(qint64 duration)
{
    ui->progressSlider->setMaximum(duration);

    // 更新总时间标签
    QTime totalTime(0, (duration / 60000) % 60, (duration / 1000) % 60);
    ui->totalTimeLabel->setText(totalTime.toString("mm:ss"));
}

//开启/关闭静音
void OnlineMusicWidget::on_volumeButton_clicked()
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


void OnlineMusicWidget::on_addButton_clicked()
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
    //保存
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

void OnlineMusicWidget::on_localMusicListButton_clicked()
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

        //播放本地音乐
        connect(localMusicList, &QListWidget::itemDoubleClicked, this, &OnlineMusicWidget::onLocalMusicDoubleClicked);

        //读取歌曲
        loadMusicList();

        // 将顶部布局和列表添加到主布局
        layout->addLayout(topLayout, 0);      // 添加拉伸因子0，保持最小高度
        layout->addWidget(localMusicList, 1);  // 添加拉伸因子1，允许拉伸

        // 设置容器大小
        container->setFixedSize(250, 350);  // 固定大小，防止大小改变

        // 连接添加按钮信号
        connect(addButton, &QPushButton::clicked, this, &OnlineMusicWidget::on_addButton_clicked);

        listContainer = container;

        // 设置样式
        container->setStyleSheet(
            "QWidget { background-color: white; }"
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

//点击其他区域关闭列表
bool OnlineMusicWidget::eventFilter(QObject *watched, QEvent *event)
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

//保存本地歌曲
void OnlineMusicWidget::saveMusicList()
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

//加载保存的本地歌曲
void OnlineMusicWidget::loadMusicList()
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

//双击播放本地音乐
void OnlineMusicWidget::onLocalMusicDoubleClicked(QListWidgetItem *item)
{
    // 设定播放路径
    QString filepath = item->data(Qt::UserRole).toString();
    player->setSource(QUrl::fromLocalFile(filepath));
    player->play();

    // 更改播放图标
    ui->playButton->setIcon(QIcon(":/images/prefix1/images/pause.png"));
    isplaying = true;

    //添加到播放列表

    addToPlaylist(filepath);

    // 重置滚动相关的变量
    scrollPosition = 0;
    textWidth = 0;
    scrollOffset = 0;

    disconnect(player, &QMediaPlayer::metaDataChanged, nullptr, nullptr);

    //显示作者信息
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

    //绘制作者
    int authorwidth = ui->authorLabel->width();
    QPixmap pixmap(authorwidth,ui->authorLabel->height());
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setFont(ui->authorLabel->font());
    painter.setPen(Qt::white);
    QRect textRect = QRect(0, 0, authorwidth, ui->authorLabel->height());
    painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, artist);
    ui->authorLabel->setPixmap(pixmap);


    ui->titleLabel->setText(fullTitle);
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
        // 直接绘制非滚动文本
        QPixmap pixmap(labelWidth, ui->titleLabel->height());
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        painter.setFont(ui->titleLabel->font());
        painter.setPen(Qt::white);
        QRect textRect = QRect(0, 0, labelWidth, ui->titleLabel->height());
        painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, fullTitle);
        ui->titleLabel->setPixmap(pixmap);
    }
    });
}


//标题滚动显示
void OnlineMusicWidget::scrollText()
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
    painter.setPen(Qt::white);

    int fullWidth = fm.horizontalAdvance(displayText);

    painter.drawText(QRect(-scrollOffset, 0, fullWidth, ui->titleLabel->height()),
                     Qt::AlignLeft | Qt::AlignVCenter,
                     displayText);

    ui->titleLabel->setPixmap(pixmap);

    scrollOffset = (scrollOffset + 1) % (textWidth + fm.horizontalAdvance("     "));
}

//添加到播放列表
void OnlineMusicWidget::addToPlaylist(const QString &songPath)
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

//播放列表中的下一首
void OnlineMusicWidget::on_nextButton_clicked()
{
    //获取当前播放歌曲路径
    QString currentPath = player->source().toLocalFile();
    QModelIndexList matches = musicModel->match(
        musicModel->index(0,0),
        Qt::UserRole,
        currentPath,
        1,
        Qt::MatchExactly
        );
    if(!matches.empty()){
        //获取当前播放歌曲位置
        int currentRow = matches.first().row();
        int nextRow = currentRow + 1;
        //如果是最后一首歌，切换到第一首
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

//播放列表中的上一首
void OnlineMusicWidget::on_prevButton_clicked()
{
    QString currentPath = player->source().toLocalFile();
    QModelIndexList matches = musicModel->match(
        musicModel->index(0,0),
        Qt::UserRole,
        currentPath,
        1,
        Qt::MatchExactly
        );
    if(!matches.empty()){
        int currentRow = matches.first().row();
        int prevRow = currentRow - 1;
        //如果是第一首歌，切换到末尾
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

//打开设置界面
void OnlineMusicWidget::on_optionsButton_clicked()
{
    if(!settingsDialog){
        settingsDialog = new Settings(this);
    }
    settingsDialog->show();
}

