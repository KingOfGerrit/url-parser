#ifndef NODE_H
#define NODE_H

#include <QLinkedList>

template<typename T>
class Node
{
public:
    Node(qint64 number, T data);

    void addToList     (const qint64 &numberOfNode);
    void removeFromList(const qint64 &numberOfNode);
    bool existInList   (const qint64 &numberOfNode) const;
    void clean         ();

    qint64 number () const;
    T      getData() const;

    QLinkedList<qint64>::iterator getBegin();
    QLinkedList<qint64>::iterator getEnd();

private:
    qint64              m_number;
    T                   m_data;
    QLinkedList<qint64> m_adj;
};

#include "node.cpp"

#endif // NODE_H
