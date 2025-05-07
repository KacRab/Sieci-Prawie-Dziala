#ifndef NETWORKSETTINGS_H
#define NETWORKSETTINGS_H

#include <QDialog>

#include <QWidget>
#include "Manager.h"

namespace Ui {
class NetworkSettings;
}

class MainWindow;

class NetworkSettings : public QDialog
{
    Q_OBJECT

public:
    explicit NetworkSettings(Manager *manager, QWidget *parent = nullptr);
    ~NetworkSettings();

    void updateLampka(const QString &status);
public slots:
    void onModeChanged(bool isRegulator);

private slots:
    void on_stopServerButton_clicked();

    void on_disconnectButton_clicked();

    void on_startServerButton_clicked();

    void on_connectButton_clicked();

signals:
    void regulatorModeActivated(); // Wywoływany po kliknięciu Start Server
    void networkModeDisabled();    // Wywoływany po kliknięciu Stop
    void objectModeActivated();

private:
    Ui::NetworkSettings *ui;
    Manager *manager;
    MainWindow *mainWindow;
};

#endif // NETWORKSETTINGS_H
