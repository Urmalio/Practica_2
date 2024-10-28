/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */

#include "maxstack.h"

#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const element& elemento){

 char c[100];
 sprintf( c, "%3d | %3d", elemento.valor, elemento.maximo );

 cout << c;
 return os;
}

MaxStack::MaxStack()= default;

MaxStack::MaxStack(const MaxStack& cola)= default;

bool MaxStack::empty() const { return q.empty(); }

int MaxStack::size() const { return static_cast<int>(q.size()); }

void MaxStack::push(int valor){ q.push(valor); pq.push(valor);}

void MaxStack::pop(){

 //almacena todos los valores que han sido eliminados de la pila, pero que no eran maximos
 static priority_queue< int > eliminated_nonmax;

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

 //longterm free memory (max used 2n)
 if ( q.size() <= eliminated_nonmax.size() && q.size() > 10 ){
  priority_queue<int> aux;

  for(int i = 0; i<pq.size(); ++i){

   if( pq.top() == eliminated_nonmax.top() )
    eliminated_nonmax.pop();
   else
    aux.push( eliminated_nonmax.top() );

   pq.pop();
  }

  pq.swap(aux);
 }

}

element MaxStack::top() const{ return  element{q.back(), pq.top()}; }




