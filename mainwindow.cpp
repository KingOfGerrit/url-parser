#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork>
#include <QTimer>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(0, 1, this);
    model->setHeaderData(0, Qt::Horizontal, "Found items");
    ui->treeView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int const timeout = 60000;

    QTimer timer;
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(ui->urlLineEdit->text())));
    QEventLoop event;

    timer.setSingleShot(true);

    connect(&timer, &QTimer::timeout, response, &QNetworkReply::abort);
    connect(response, &QNetworkReply::finished, &event, &QEventLoop::quit);

    timer.start(timeout);   // 60 secs. timeout
    event.exec();

    if (response->error() == QNetworkReply::NoError)
    {
        // All ok
    }
    else
    {
        // Error
    }

    QString html = response->readAll(); // Source should be stored here

    QStandardItem *item = new QStandardItem(ui->urlLineEdit->text());
    model->appendRow(item);

    int j = 0;
    QStandardItem* parentT = model->findItems(ui->urlLineEdit->text())[0];
    QString subStr = ui->searchTextLineEdit->text();

    // Substring method
//    while ((j = html.indexOf(subStr, j)) != -1)
//    {
//        QString foundText = html.mid(j - 5, subStr.length() + 10);
//        foundText.remove(QRegExp("[\\n\\t\\r]"));

//        qDebug() << "Found " + subStr + " tag at index position" << j;
//        qDebug() << foundText;

//        QStandardItem* child = new QStandardItem(foundText);
//        parentT->appendRow(child);

//        ++j;
//    }

    // QRegExp method
//    QRegExp rx("(" + ui->findWordLineEdit->text() + ")");
//    int pos = 0;

//    while ((pos = rx.indexIn(html, pos)) != -1)
//    {
//        qDebug() << rx.cap(1);
//        pos += rx.matchedLength();
//    }
}
