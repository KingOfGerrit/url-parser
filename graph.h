#ifndef GRAPH_H
#define GRAPH_H

#include <QList>
#include <QLinkedList>

struct Node
{
    Node() {}
    QString url;
};

class Graph
{
public:
    Graph();
    explicit Graph(qint64 v);

    void add(Node node);
    void remove(int i);
    Node* get();

private:
    // Number of vertices
    qint64 m_v;
    QList<QLinkedList<Node>> m_adj;
};

#endif // GRAPH_H