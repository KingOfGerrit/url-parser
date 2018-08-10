#include "mainwindow.h"
#include <QApplication>
#include <QRunnable>
#include <QThreadPool>

#include <QQueue>

#include "graph.h"

class HelloWorldTask : public QRunnable
{
    void run()
    {
        qDebug() << Q_FUNC_INFO << QThread::currentThread();
    }
};

int main(int argc, char *argv[])
{
    QQueue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    while (!queue.isEmpty())
        qDebug() << queue.dequeue() << endl;


    HelloWorldTask *hello = new HelloWorldTask();
    HelloWorldTask *hello1 = new HelloWorldTask();
    QThreadPool *pool = new QThreadPool();
    pool->setMaxThreadCount(2);

    // QThreadPool takes ownership and deletes 'hello' automatically
    pool->start(hello);
    pool->start(hello1);
    qDebug() << Q_FUNC_INFO << QThread::currentThread();
    qDebug() << pool->activeThreadCount();
    qDebug() << pool->maxThreadCount();

    Graph<QString> g;

    g.add("0");
    g.add("1");
    g.add("2");
    g.add("3");

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.bfs(2);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
