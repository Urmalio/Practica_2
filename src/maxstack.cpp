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
}

MaxStack::MaxStack()= default;

MaxStack::MaxStack(const MaxStack& cola): pq(cola.pq),q(cola.q){}

bool MaxStack::empty() const { return q.empty(); }

int MaxStack::size() const { return static_cast<int>(q.size()); }

void MaxStack::push(int valor){ q.push(valor); pq.push(valor); }

void MaxStack::pop(){

 //almacena todos los valores que han sido eliminados de la pila, pero que no eran maximos
 static priority_queue< int, deque<int>, greater<int> > eliminated_nonmax;

 //si la pila esta vacía no se hace nada
 if (q.empty())
  return;

 //valor que se va a desechar de la pila
 const int old_top=q.back();

 {
  //cola con todos los valores excepto el desechado
  queue<int> aux;

  int intermedios = static_cast<int>( q.size() )-1;

  for(int i = 0; i<intermedios; i++){
   aux.push(q.front() );
   q.pop();
  }
  q.pop(); //acaba de vaciar q

  q.swap(aux);
 } // == p.pop_back()

 if( old_top != pq.top() )
  eliminated_nonmax.push( old_top );
 else{
  pq.pop();
  while( !eliminated_nonmax.empty() && pq.top()==eliminated_nonmax.top() ){
   pq.pop();
   eliminated_nonmax.pop();
  }
 }

}

element MaxStack::top() const{ return {q.back(), pq.top()}; }




