#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "graph.h"

template<typename T>
Graph<T>::Graph() :
    m_v(0)
{

}

template<typename T>
void Graph<T>::add(const T &data)
{
    m_graph.append(Node<T>(m_v++, data));
}

template<typename T>
void Graph<T>::addEdge(const qint64 &v, const qint64 &w)
{
    m_graph[v].addToList(w);
}

template<typename T>
void Graph<T>::remove(const qint64 &i)
{
    --m_v;
    m_graph.removeAt(i);

    foreach (Node<T> n, m_graph)
    {
        n.removeFromList(i);
    }
}

template<typename T>
void Graph<T>::remove(const T &data)
{
    --m_v;
    qint64 i = find(data);
    m_graph.removeAt(i);

    foreach (Node<T> n, m_graph)
    {
        n.removeFromList(i);
    }
}

template<typename T>
void Graph<T>::clear()
{
    m_v = 0;
    m_graph.clear();
}

template<typename T>
qint64 Graph<T>::find(const T &data)
{
    for (qint64 i = 0; i < m_graph.size(); ++i)
    {
        if (m_graph.at(i).getData() == data)
        {
            return i;
        }
    }

    return -1;
}

template<typename T>
Node<T> Graph<T>::get(const qint64 &i)
{
    return m_graph.at(i);
}

template<typename T>
Node<T> Graph<T>::get(const T &data)
{
    foreach (Node<T> n, m_graph)
    {
        if (n.getData() == data)
        {
            return n;
        }
    }

    return Node<T>(-1, "");
}

template<typename T>
void Graph<T>::bfs(const qint64 &startIndex)
{
    qint64 s = startIndex;

    // Mark all the vertices as not visited
    bool *visited = new bool[m_v];
    for(int i = 0; i < m_v; i++)
        visited[i] = false;

    // Create a queue for BFS
    QLinkedList<qint64> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(m_graph.at(s).number());

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    QLinkedList<qint64>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        qDebug() << s;
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = m_graph[s].getBegin(); i != m_graph[s].getEnd(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

template<typename T>
Graph::~Graph()
{
    clear();
}

#endif // GRAPH_CPP
