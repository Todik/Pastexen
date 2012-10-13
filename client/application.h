#ifndef APPLICATION_H
#define APPLICATION_H

#include <QxtGui/QxtApplication>
#include <QxtGui/QxtGlobalShortcut>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QSettings>
#include <QFile>
#include "configwidget.h"
#include "network.h"

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int argc, char *argv[]);
    ~Application();
    void pxAppInit();
private slots:
    inline void processScreenshotFull() { processScreenshot(true); }
    inline void processScreenshotPart() { processScreenshot(false); }
    void processCodeShare();
    void trayIconClicked(const QSystemTrayIcon::ActivationReason &button);
    void linkAvaliable(const QString &link);
    void aboutDialog();
private:
    void processScreenshot(bool isFullScreen);
private:
    ConfigWidget *_configWidget;
    QSystemTrayIcon *_trayIcon;
    QMenu *_trayIconMenu;
    QxtGlobalShortcut *_shortcutScreenFull;
    QxtGlobalShortcut *_shortcutScreenPart;
    QxtGlobalShortcut *_shortcutTextShare;
    Network *_network;
    Ui::Form *_configUi;
    QSettings *_settings;
};

#endif // APPLICATION_H
