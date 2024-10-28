/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Diego Díaz Luis
 */

#ifndef MAXQUEUE_H
#define MAXQUEUE_H

#include <list>
#include <algorithm>

class MaxQueue
{
 private:
 std::list<int> queue;
 std::list<int> maximo;
 public:
 MaxQueue();
 ~MaxQueue();
 bool empty();
 int size();
 MaxQueue front();
 MaxQueue back();
 void emplace();
 void pop();
 void swap();
 friend std::ostream &operator<<(std::ostream &os, const MaxQueue &queue);
};


#endif MAXQUEUE_H
