/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Diego Díaz Luis
 */

#ifndef MAXQUEUE_H
#define MAXQUEUE_H

#include <iostream>
#include <list>
#include <algorithm>
#include <limits>

using namespace std;

/* @brief Estructura auxiar para el retorno del par valor-maximo
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

//
class MaxQueue
{
 private:
  list<int> queue;
  int maximo;
 public:
  MaxQueue();
  ~MaxQueue();
  bool empty() const;
  int size() const;
  element front() const;
  element back() const;
  void pop();
  void push(int num);
  void swap(MaxQueue & another_queue);
};

#endif
