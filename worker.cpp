#include "worker.h"

Worker::Worker()
{

}

bool Worker::running() const
{
    return m_running;
}

void Worker::run()
{
    qDebug() << Q_FUNC_INFO << QThread::currentThread();
    while (m_running)
    {
        // do work
    }

    emit finished();
}

void Worker::setRunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(m_running);
}

QList<QString> Worker::searchTextBySubstring(QString text, QString find)
{
    QList<QString> foundElements;
    QStringList lines = text.split("\\n");

    for (int i = 0; i < fonts.size(); ++i)
    {
        QString line = lines[i];
        int pos = 0;

        while ((pos = line.indexOf(find, pos)) != -1)
        {
            QString foundText =
                    "Found text on line " % (i + 1) % ", position " % (pos + 1) % ":"
                    "..." % line.mid(pos - 5, find.length() + 10) % "...";

            qDebug() << foundText;

            foundElements.append(foundText);

            ++pos;
        }
    }

    return foundElements;
}

QList<QString> Worker::searchTextByRegExp(QString text, QRegExp rx)
{
    QList<QString> foundElements;
    int pos = 0;

    while ((pos = rx.indexIn(text, pos)) != -1)
    {
        qDebug() << rx.cap(1);
        foundElements.append(rx.cap(1));

        pos += rx.matchedLength();
    }

    return foundElements;
}

void Worker::parseHtml(QUrl url)
{
    QString html = "";
    NetErr  error = getHtml(url, html, QRegExp("[\\t\\r]"));

    // All ok
    if (error == QNetworkReply::NoError)
    {

    }
    // Error
    else
    {

    }
}

NetErr Worker::getHtml(QUrl url, QString &html, QRegExp whatRemoveFromHtmlFile)
{
    QTimer                timer;
    QNetworkAccessManager manager;
    QNetworkReply         *response = manager.get(QNetworkRequest(url));
    QEventLoop            event;

    timer.setSingleShot(true);

    connect(&timer,   &QTimer::timeout,         response, &QNetworkReply::abort);
    connect(response, &QNetworkReply::finished, &event,   &QEventLoop::quit);

    timer.start(m_timeout);
    event.exec();

    NetErr error = response->error();
    response->deleteLater();

    // All ok
    if (error == QNetworkReply::NoError)
    {
        // Stop timer
        timer.stop();

        html = response->readAll();
        html.remove(whatRemoveFromHtmlFile);
    }
    // Error
    else
    {
        html = "";
    }

    return error;
}
