#include "networksettings.h"
#include "mainwindow.h"
#include "ui_networksettings.h"

void NetworkSettings::onModeChanged(bool isRegulator)
{
    ui->startServerButton->setEnabled(isRegulator); // Włączone tylko w trybie Regulatora
    ui->connectButton->setEnabled(!isRegulator);    // Włączone tylko w trybie Obiektu regulacji
    ui->ipLineEdit->setEnabled(!isRegulator);       // IP włączone tylko w trybie Obiektu regulacji
    ui->portLineEdit->setEnabled(true);             // Port zawsze włączony
}
NetworkSettings::NetworkSettings(Manager *manager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NetworkSettings)
    , manager(manager)

{
    ui->setupUi(this);

    // Powiązanie sygnału z aktualizacją statusu
    connect(manager, &Manager::statusChanged, ui->statusLabel, &QLabel::setText);

    connect(ui->startServerButton, &QAbstractButton::clicked, this, [this, manager]() {
        double port = ui->portLineEdit->text().toDouble();
        manager->startServer(port);
        // manager->startTaktowanie(); // Rozpocznij wykonywanie taktu
    });

    connect(ui->connectButton, &QAbstractButton::clicked, this, [this, manager]() {
        QString host = ui->ipLineEdit->text();
        double port = ui->portLineEdit->text().toDouble();
        manager->connectToServer(host, port);
        //manager->startTaktowanie(); // Rozpocznij wykonywanie taktu
    });

    connect(manager, &Manager::statusChanged, ui->statusLabel, &QLabel::setText);
    connect(manager, &Manager::statusChanged, this, &NetworkSettings::updateLampka);

    //  updateLampka("Symulacja wyrabia");
    //updateLampka("Symulacja nie wyrabia");
}

NetworkSettings::~NetworkSettings()
{
    delete ui;
}
void NetworkSettings::updateLampka(const QString &status)
{
    // Ustaw obramowanie na biały kolor dla efektu przejściowego
    ui->statusLampka->setStyleSheet("QLabel { border: 2px solid white; }");

    // Po krótkim czasie, ustaw normalny kolor
    QTimer::singleShot(200, [this, status]() {
        if (status.contains("nie wyrabia")) {
            ui->statusLampka->setStyleSheet(
                "QLabel { background-color : red; color : white; border: none; }");
            ui->statusLampka->setText("Stan: Nie wyrabia");
        } else if (status.contains("wyrabia")) {
            ui->statusLampka->setStyleSheet(
                "QLabel { background-color : green; color : white; border: none; }");
            ui->statusLampka->setText("Stan: Wyrabia");
        }
    });
}

void NetworkSettings::on_startServerButton_clicked()
{
    emit objectModeActivated();
    qDebug() << "Sygnał startServerRequested został wyemitowany.";
}

void NetworkSettings::on_stopServerButton_clicked()
{
    manager->stopServer();
    emit networkModeDisabled();
}

void NetworkSettings::on_connectButton_clicked()
{
    emit regulatorModeActivated(); // Emituj sygnał do MainWindow
    manager->startTaktowanie();
}

void NetworkSettings::on_disconnectButton_clicked()
{
    manager->disconnectClient();
    manager->stopTaktowanie();
    emit networkModeDisabled(); // Wyemitowanie sygnału przejścia do trybu lokalnego
    qDebug() << "Połączenie sieciowe zatrzymane. Przełączono do trybu lokalnego obiektu.";
}
