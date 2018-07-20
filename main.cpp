#include "mainwindow.h"
#include <QApplication>

#include "graph.h"

int main(int argc, char *argv[])
{
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
