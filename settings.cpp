#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    m_initializing = true;

    // 初始化字号选项
    QStringList sizes = {"小", "较小", "一般", "较大", "大"};
    ui->sizecomboBox->addItems(sizes);

    // 加载保存的设置
    QSettings settings("iyl","MusicPlayer");

    // 字体初始化（阻塞信号）
    ui->fontComboBox->blockSignals(true);
    QString fontFamily = settings.value("app/fontFamily", QApplication::font().family()).toString();
    ui->fontComboBox->setCurrentFont(QFont(fontFamily));
    ui->fontComboBox->blockSignals(false);

    // 字号初始化（阻塞信号）
    ui->sizecomboBox->blockSignals(true);
    QString sizeText = settings.value("app/sizeText", "一般").toString();
    ui->sizecomboBox->setCurrentText(sizeText);
    ui->sizecomboBox->blockSignals(false);

    m_initializing = false;

    //连接文字颜色槽函数
    connect(ui->blackButton,&QPushButton::clicked,this,[this](){setTextColor(Qt::black);});//黑色
    connect(ui->whiteButton,&QPushButton::clicked,this,[this](){setTextColor(Qt::white);});//白色
    connect(ui->blueButton,&QPushButton::clicked,this,[this](){setTextColor(QColor(121, 255, 251));});//蓝色
    connect(ui->yellowButton,&QPushButton::clicked,this,[this](){setTextColor(QColor(255, 255, 127));});//黄色
    connect(ui->redButton,&QPushButton::clicked,this,[this](){setTextColor(QColor(200, 0, 0));});//红色
}

Settings::~Settings() {
    delete ui;
}

//修改背景
void Settings::on_backgroundButton_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(
        this,
        tr("选择背景图片"),
        QDir::homePath(),
        tr("图片文件 (*.png *.jpg *.jpeg *.bmp)")
    );

    if(!imagePath.isEmpty()){
        QSettings settings;
        settings.setValue("app/background", imagePath);

        //重启应用以更改设置
        qApp->exit(EXIT_CODE_REBOOT);
        }

}

void Settings::on_fontComboBox_currentFontChanged(const QFont &f)
{
    if(m_initializing) return;

    QFont newFont = QApplication::font();
    newFont.setFamily(f.family());

    // 保持当前字号
    QSettings settings("iyl","MusicPlayer");
    if(settings.contains("app/fontSize")){
        newFont.setPixelSize(settings.value("app/fontSize").toInt());
    }

    QApplication::setFont(newFont);
    settings.setValue("app/fontFamily", f.family());

    // 更新所有控件
    qApp->setFont(newFont);
    foreach(QWidget *widget, QApplication::allWidgets()) {
        widget->setFont(newFont);
    }
}
//修改文字大小
void Settings::changeFontSize()
{
    QStringList items;
    items << "小" << "较小" << "一般" << "较大" << "大";

    ui->sizecomboBox->clear();
    ui->sizecomboBox->addItems(items);

    // 加载保存的设置
    QSettings settings("iyl","MusicPlayer");
    QString savedSizeText = settings.value("app/size", "一般").toString();
    ui->sizecomboBox->setCurrentText(savedSizeText);
    ui->sizecomboBox->setMinimumWidth(100);
}
void Settings::on_sizecomboBox_currentTextChanged(const QString &text)
{
    if(m_initializing) return;

    static QMap<QString, int> sizeMap = {
        {"小",12}, {"较小",14}, {"一般",18}, {"较大",20}, {"大",22}
    };

    if(sizeMap.contains(text)){
        QFont newFont = QApplication::font();
        newFont.setPixelSize(sizeMap[text]);

        QApplication::setFont(newFont);
        qApp->setFont(newFont);

        QSettings settings("iyl","MusicPlayer");
        settings.setValue("app/fontSize", sizeMap[text]);
        settings.setValue("app/sizeText", text);

        foreach(QWidget *widget, QApplication::allWidgets()) {
            widget->setFont(newFont);
        }
    }
}


//文字颜色设置
void Settings::setTextColor(const QColor &color)
{
    QSettings settings("iyl","MusicPlayer");
    settings.setValue("app/textColor",color.name());
    emit(textColorChanged(color));
}
