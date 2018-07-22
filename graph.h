#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <QList>

#include <QDebug>

template<typename T>
class Graph
{
public:
    Graph() :
        m_v(0)
    {}

    void add    (const T &data);
    void addEdge(const qint64 &v, const qint64 &w);
    void remove (const qint64 &i);
    void remove (const T &data);

    qint64 find (const T &data);

    Node<T> get    (const qint64 &i);
    Node<T> get    (const T &data);

    void bfs(const qint64 &startIndex);

private:
    // Number of vertices
    qint64         m_v;
    QList<Node<T>> m_graph;
};

#include "graph.cpp"

#endif // GRAPH_H
