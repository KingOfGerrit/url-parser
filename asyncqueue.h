#ifndef ASYNCQUEUE_H
#define ASYNCQUEUE_H

#include <QQueue>
#include <QMutex>
#include <QObject>
#include <QThread>

template<typename T>
class AsyncQueue
{
public:
    AsyncQueue();

    void customEnqueue(const T& t);
    T    customDequeue();
    void customClean ();

private:
    QQueue<T> m_queue;
    QMutex    m_mutex;
};

#include "asyncqueue.cpp"

#endif // ASYNCQUEUE_H
