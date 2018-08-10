#ifndef WORKER_H
#define WORKER_H

#include <QRegExp>
#include <QTimer>
#include <QObject>
#include <QRunnable>
#include <QtNetwork>

#include <QPair>
#include <QList>

typedef QNetworkReply::NetworkError NetErr;

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)

public:
    Worker();

    bool running() const;

signals:
    void runningChanged(bool running);
    void parseDone     (QPair<QString, QList<QString>> data);
    void finished      ();

public slots:
    void run       ();

    void setRunning(bool running);

private:
    bool      m_running;
    int const m_timeout = 60000;

    void           parseHtml            (QUrl    url);
    NetErr         getHtml              (QUrl    url,  QString &html);
    QList<QString> searchTextBySubstring(QString text, QString find);
    QList<QString> searchTextByRegExp   (QString text, QRegExp rx);
};

#endif // WORKER_H
