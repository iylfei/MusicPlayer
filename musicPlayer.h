#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include <QWidget>
#include <QPainter>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QAudioOutput>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QScrollBar>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QListWidgetItem>
#include <QFileInfo>
#include <QDir>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDialog>
#include <QStandardItemModel>
#include <QPainterPath>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStringConverter>
#include <QTextStream>
#include <QSettings>
#include <QRegularExpression>
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MusicPlayer;
}
QT_END_NAMESPACE

class MusicPlayer : public QWidget
{
    Q_OBJECT
public:
    MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();
    struct LyricStyle {
        QColor textColor = Qt::red;
        QColor activeColor = Qt::yellow;
        bool showTranslation = true;
        Qt::Alignment alignment = Qt::AlignCenter;
        int fontSize = 12;
    };

protected:
    void paintEvent(QPaintEvent *paint) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    // 界面控制
    void on_closeButton_clicked();
    void on_minButton_clicked();
    void on_optionsButton_clicked();

    // 播放控制
    void on_playButton_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();

    // 进度和音量控制
    void onSliderPressed();
    void onSliderReleased();
    void onSliderValueChanged(int value);
    void on_volumeSlider_valueChanged(int volume);
    void on_volumeButton_clicked();
    void updateProgress(qint64 position);
    void updateDuration(qint64 duration);

    // 播放列表管理
    void on_addButton_clicked();
    void on_localMusicListButton_clicked();
    void onLocalMusicDoubleClicked(QListWidgetItem *item);
    void on_musicList_doubleClicked(const QModelIndex &index);

    // 界面更新
    void scrollText();
    void updateAuthorLabel();
    void updatenonscrollText();
    void updateMetadata();
    void displayAlbumCover();

    //歌词
    void on_pushButton_clicked();
    void updateLyricDisplay();
    void updateLyric(qint64 position); // 缺少的函数声明
    void setLyricStyle(const LyricStyle &style);
    void initLyricStyle();

private:
    Ui::MusicPlayer *ui;
    QMediaPlayer* player;
    QAudioOutput *audioOutput;

    // 播放状态
    bool isplaying;
    bool userSeeking = false;
    bool isMuted;
    float preVolume;

    // 播放列表
    QWidget *listContainer = nullptr;
    QListWidget *localMusicList = nullptr;
    bool isLocalMusicListVisible = false;
    QPushButton *addButton = nullptr;
    QWidget *container = nullptr;
    QStandardItemModel *musicModel;  // 播放列表

    // 文件管理
    void saveMusicList();  // 保存歌曲列表
    void loadMusicList();  // 加载歌曲列表
    QString musicListPath; // 保存json文件的路径
    void addToPlaylist(const QString &songPath);

    // 文本滚动
    QTimer *scrollTimer;        // 用于控制文本滚动
    QString fullTitle;          // 完整的标题文本
    QString m_currentArtist;    // 当前歌手信息
    int scrollPosition;         // 当前滚动位置
    static const int SCROLL_INTERVAL = 30;  // 滚动间隔（毫秒）
    int scrollOffset = 0;       // 像素偏移量
    int textWidth = 0;          // 文本总像素宽度
    bool needScroll = false;    // 是否需要滚动

    // 设置与样式
    Settings *settingsDialog;   // 设置对话框
    QColor m_textColor = Qt::white;
    void drawAuthorLabel();

    // 窗口拖动
    QPoint m_mousepoint;
    QPoint movepoint;
    bool ispressed;

    // 歌词显示
    LyricStyle m_lyricStyle;
    QMultiMap<qint64, QString> m_lyrics;       // 存储歌词
    QMap<qint64, QString> m_translationLyrics; // 存储翻译歌词
    QList<qint64> lyricTimes;                  // 歌词时间点列表
    QStringList lyricTexts;                    // 歌词文本列表
};

#endif // MUSICPLAYER_H
