/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */

#include "maxstack.h"

using namespace std;

ostream& operator<<(ostream& os, const element& elemento){

 os << printf( "%d | %d", elemento.valor, elemento.maximo);
 return os;
};

MaxStack::MaxStack()= default;

MaxStack::MaxStack(const MaxStack& cola): pq(cola.pq),q(cola.q){};

bool MaxStack::empty() const { return q.empty(); };

int MaxStack::size() const { return static_cast<int>(q.size()); };

void MaxStack::push(int valor){ q.push(valor); pq.push(valor); };

void MaxStack::pop(){

 queue<int> aux;

 for(int i = 1; i<q.size(); i++){
  aux.push(q.front() );
  q.pop();
 }

 if( q.front() == pq.front() )
  pq.pop();
 else
  pq(aux);

 q=aux;

};

element MaxStack::top() const{ return {q.back(), pq.front()}; };




