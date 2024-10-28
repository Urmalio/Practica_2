/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author
 */

#include "maxqueue.h"

MaxQueue::MaxQueue()
{
 maximo = numeric_limits<int>::min();
}
MaxQueue::~MaxQueue() = default;
bool MaxQueue::empty() const
{
 return queue.empty();
}
int MaxQueue::size() const
{
 return static_cast<int>(queue.size());
}
element MaxQueue::front() const
{
 return element{queue.front(),maximo};
}
element MaxQueue::back() const
{
 return element{queue.back(),maximo};
}
void MaxQueue::pop()
{
 if (queue.front() == maximo)
  maximo = *max_element(queue.begin(),queue.end());
 queue.pop_front();
}
void MaxQueue::push(int num)
{
 if (num > maximo)
  maximo = num;
 queue.push_back(num);
}
void MaxQueue::swap(MaxQueue & another_queue)
{
 queue.swap(another_queue.queue);
 int temp = maximo;
 maximo = another_queue.maximo;
 another_queue.maximo = temp;
}



