#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QApplication>
#include <QFileDialog>

#define EXIT_CODE_REBOOT 1000

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_backgroundButton_clicked();

    void changeFontSize();



    void on_sizecomboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Settings *ui;
    bool m_initializing = true;

signals:
    void backgroundChanged();

};

#endif // SETTINGS_H
