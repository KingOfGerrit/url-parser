#include "mainwindow.h"
#include <QApplication>
#include <QRunnable>
#include <QThreadPool>

#include "graph.h"

class HelloWorldTask : public QRunnable
{
    void run()
    {
        qDebug() << "Hello world from thread" << QThread::currentThread();
    }
};

int main(int argc, char *argv[])
{
    HelloWorldTask *hello = new HelloWorldTask();
    HelloWorldTask *hello1 = new HelloWorldTask();

    // QThreadPool takes ownership and deletes 'hello' automatically
    QThreadPool::globalInstance()->start(hello);
    QThreadPool::globalInstance()->start(hello1);
    qDebug() << "Main Thread" << QThread::currentThread();

//    Graph<QString> g;

//    g.add("0");
//    g.add("1");
//    g.add("2");
//    g.add("3");

//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 0);
//    g.addEdge(2, 3);
//    g.addEdge(3, 3);

//    g.bfs(2);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
