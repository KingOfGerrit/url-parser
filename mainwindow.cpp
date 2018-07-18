#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(ui->urlLineEdit->text())));
    QEventLoop event;
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    QString html = response->readAll(); // Source should be stored here

    int j = 0;

    QString subStr = ui->findWordLineEdit->text();
    while ((j = html.indexOf(subStr, j)) != -1) {
        qDebug() << "Found " + subStr + " tag at index position" << j;
        qDebug() << html.mid(j - 5, subStr.length() + 10);
        ++j;
    }

    // QRegExp method
//    QRegExp rx("(" + ui->findWordLineEdit->text() + ")");
//    int pos = 0;

//    while ((pos = rx.indexIn(html, pos)) != -1)
//    {
//        qDebug() << rx.cap(1);
//        pos += rx.matchedLength();
//    }

    //qDebug() << html;
}
