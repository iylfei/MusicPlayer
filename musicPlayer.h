#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include <QPainter>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QAudioOutput>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessagebox>
#include <QTime>
#include <QTimer>
#include <math.h>
#include <QMouseEvent>
#include <QListWidgetItem>
#include <QFileInfo>
#include <QDir>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDialog>
#include <QStandardItemModel>
#include "settings.h"
#include <QPainterPath>


QT_BEGIN_NAMESPACE
namespace Ui {
class OnlineMusicWidget;
}
QT_END_NAMESPACE

class OnlineMusicWidget : public QWidget
{
    Q_OBJECT

public:
    OnlineMusicWidget(QWidget *parent = nullptr);
    ~OnlineMusicWidget();

    void paintEvent(QPaintEvent *paint);

private slots:

    void on_closeButton_clicked();

    void on_minButton_clicked();

    void on_playButton_clicked();

    void onSliderPressed();

    void onSliderReleased();

    void onSliderValueChanged(int value);

    void on_volumeSlider_valueChanged(int volume);

    void updateProgress(qint64 position);

    void on_volumeButton_clicked();

    void on_addButton_clicked();

    void on_localMusicListButton_clicked();

    void onLocalMusicDoubleClicked(QListWidgetItem *item);

    void scrollText();

    void on_nextButton_clicked();

    void on_prevButton_clicked();

    void addToPlaylist(const QString &songPath);

    void on_optionsButton_clicked();

    void updateAuthorLabel();

    void updatenonscrollText();

    void updateMetadata();

    void drawAuthorLabel();

    void on_musicList_doubleClicked(const QModelIndex &index);

    void displayAlbumCover();

private:
    Ui::OnlineMusicWidget *ui;

    QMediaPlayer* player;
    QAudioOutput *audioOutput;
    bool isplaying;
    bool userSeeking = false;
    bool isMuted;
    float preVolume;
    QWidget *listContainer = nullptr;
    QListWidget *localMusicList = nullptr;
    bool isLocalMusicListVisible = false;
    QPushButton *addButton = nullptr;
    QWidget *container = nullptr;
    void saveMusicList();  // 保存歌曲列表
    void loadMusicList();  // 加载歌曲列表
    QString musicListPath; // 保存json文件的路径
    QTimer *scrollTimer;        // 用于控制文本滚动
    QString fullTitle;          // 完整的标题文本
    QString m_currentArtist; // 当前歌手信息
    int scrollPosition;         // 当前滚动位置
    static const int SCROLL_INTERVAL = 30;  // 滚动间隔（毫秒）
    int scrollOffset = 0;        // 像素偏移量
    int textWidth = 0;           // 文本总像素宽度
    bool needScroll = false;  // 是否需要滚动
    QStandardItemModel *musicModel;  //播放列表
    Settings *settingsDialog; //设置对话框
    QColor m_textColor = Qt::white;

protected:
    //音乐下载和播放
    void DownloadPlayer(QString songId);
    //访问HTTP网页
    void HttpAccessFunc(QString);
    //解析album_id和hash(使用JSON)
    void HashJsonAnalysis(QByteArray);
    //搜索音乐数据信息的JSON解析，解析出真正的音乐文件和歌词
    QString MusicJsonAnalysis(QByteArray);
    //鼠标拖动窗口实现移动
    void mouseMoveEvent(QMouseEvent *event);//移动
    void mousePressEvent(QMouseEvent *event);//按下
    void mouseReleaseEvent(QMouseEvent *event);//释放
    void updateDuration(qint64 duration);
    bool eventFilter(QObject *watched, QEvent *event);

    QPoint m_mousepoint;
    QPoint movepoint;
    bool ispressed;
};
#endif // MUSICPLAYER_H
