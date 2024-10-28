/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author
 */

#include "maxqueue.h"

ostream& operator<<(ostream& os, const element& elemento)
{

 char c[100];
 sprintf( c, "%3d | %3d", elemento.valor, elemento.maximo );

 cout << c;
 return os;
}

MaxQueue::MaxQueue()
{
 maximo = numeric_limits<int>::min();
}
MaxQueue::~MaxQueue() = default;
bool MaxQueue::empty()
{
 return queue.empty();
}
int MaxQueue::size()
{
 return static_cast<int>(queue.size());
}
element MaxQueue::front()
{
 return element{queue.front(),maximo};
}
element MaxQueue::back()
{
 return element{queue.back(),maximo};
}
//
void MaxQueue::pop()
{
 if (queue.front() == maximo)
  maximo = *(max_element(++queue.begin(),queue.end()));
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



