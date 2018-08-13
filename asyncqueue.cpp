#ifndef ASYNCQUEUE_CPP
#define ASYNCQUEUE_CPP

#include "asyncqueue.h"

template<typename T>
AsyncQueue::AsyncQueue()
{

}

template<typename T>
AsyncQueue::~AsyncQueue()
{
    m_queue.clear();
}

#endif // ASYNCQUEUE_CPP
