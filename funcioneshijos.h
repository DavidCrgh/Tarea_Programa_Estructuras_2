#ifndef FUNCIONESHIJOS_H
#define FUNCIONESHIJOS_H
#include "avltest.h"

bool esFamiliar(NodoHumano* humano, NodoHumano* candidato);
bool estaDisponible(NodoHumano* humano, node* arbol);
bool tieneCandidatos(node* nodo,node* arbol, NodoHumano* humano);
#endif // FUNCIONESHIJOS_H
