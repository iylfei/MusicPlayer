#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);

    //加载字体设置
    QSettings settings("iyl","MusicPlayer");
    if(settings.contains("app/font")){
        QFont savedFont;
        savedFont.fromString(settings.value("app/font").toString());
        ui->fontComboBox->setCurrentFont(savedFont);
    }
}

Settings::~Settings()
{
    delete ui;
}

//修改字体
void Settings::on_fontComboBox_currentFontChanged(const QFont &f)
{
    QApplication::setFont(f);

    QSettings settings("iyl","MusicPlayer");
    settings.setValue("app/font",f.toString());

    //更新所有控件的字体
    foreach (QWidget *widget, QApplication::allWidgets()) {
        widget->setFont(f);
    }
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

//修改文字大小
void Settings::changeFontSize()
{

}
