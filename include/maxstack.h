/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author
 */

#ifndef MAXSTACK_H
#define MAXSTACK_H
#include <queue>

using namespace std;

/**
 *
 */
struct element{
  int value;
  int maximum;
};

/**
 *
 */
class MaxStack{

private:
 priority_queue<int,greater<int>> pq;
 queue<int> q;

public:
/**
 * @brief Constructor por defecto
 * Crea un stack sin elementos
 */
 MaxStack();

 element push();
 int pop();
 element fetch();

};
#endif MAXSTACK_H
