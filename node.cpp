#ifndef NODE_CPP
#define NODE_CPP

#include "node.h"

template<typename T>
Node<T>::Node(qint64 number, T data) :
    m_number(number),
    m_data(data)
{

}

template<typename T>
void Node<T>::addToList(const qint64 &numberOfNode)
{
    m_adj.append(numberOfNode);
}

template<typename T>
void Node<T>::removeFromList(const qint64 &numberOfNode)
{
    m_adj.removeAll(numberOfNode);
}

template<typename T>
bool Node<T>::existInList(const qint64 &numberOfNode) const
{
    return m_adj.contains(numberOfNode);
}

template<typename T>
void Node::clean()
{
    m_number = 0;
    m_adj.clear();
}

template<typename T>
qint64 Node<T>::number() const
{
    return m_number;
}

template<typename T>
T Node<T>::getData() const
{
    return m_data;
}

template<typename T>
QLinkedList<qint64>::iterator Node<T>::getBegin()
{
    return m_adj.begin();
}

template<typename T>
QLinkedList<qint64>::iterator Node<T>::getEnd()
{
    return m_adj.end();
}

template<typename T>
Node::~Node()
{
    clea();
}

#endif // NODE_CPP
