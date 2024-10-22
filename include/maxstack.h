/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author
 */

#ifndef MAXSTACK_H
#define MAXSTACK_H

#include <ostream>
#include <queue>

using namespace std;

//****************************** Struct Element ******************************//
/**
 * @brief Estructura auxiar para el retorno del par valor-maximo
 *
 * Para un par en un momento dado representan:
 * - valor: el retorno de la estructura semejante de la stl
 * - maximo: el máximo de la estructura en cierto momento
 *
 */
struct element{
  int valor;
  int maximo;
};

/**
 * @brief Sobrecarga del operador de salida de un element
 * El resultado en @p os será de la forma: v | m
 * Dónde v es el valor y m el máximo
 */
ostream& operator<<(ostream& os, const element& elemento);

//****************************** Clase MaxStack ******************************//
/**
 *
 */
class MaxStack{

private:
 priority_queue< int, deque<int>, greater<int> > pq{};
 queue<int> q;

public:

 //***************** Constructores *****************//
 /**
  * @brief Constructor por defecto
  * Crea un stack sin elementos
  */
 MaxStack();

 /**
  * @brief Constructor de copia de la clase
  *
  * @param cola La cola con la cual se va a inicializar nuestro objeto implícito
  */
 MaxStack(const MaxStack & cola );

 //***************** Consulta de propiedades *****************//
 /**
  * @brief Comprueba si la cola está vacía
  *
  * @return True si la cola está caía, false si no
  */
 bool empty() const;

 /**
  * @brief Devuelve el tamaño de la pila
  *
  * @post Devuelve un entero no negativo y 0 solo si la pila está vacía
  */
 int size() const;

 //***************** Acceso y Escritura de elementos *****************//
 /**
  * @brief Añade un elemento en el tope de la pila
  */
 void push(int num);

 /**
  * @brief Elimina el elemento de el tope de la pila
  *
  * @post El top de la pila y su máximo han podido cambia y en cualquier caso hay un elemento menos en esta
  */
 void pop();

 /**
  * @brief Devuelve un element con el top de la pila
  *
  * @pre 0 < size()
  *
  * @post Element tiene en valor el tope de la pila y en maximo el maximo de esta
  */
 element top() const;

};
#endif
