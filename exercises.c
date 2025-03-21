#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for(int i = 0; i < 11; i++)
   {
      int *dato = malloc(sizeof(int));
      *dato = i;
      pushFront(L,dato);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   int *dato;
   dato = first(L);
   while(dato != NULL)
   {
      suma += *dato;
      dato = next(L);
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int *datoL;
   datoL = first(L);
   while(datoL != NULL)
   {
      if(*datoL == elem)
      {
         popCurrent(L);
      }
      datoL = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* Aux = create_stack();
   while(top(P1) != NULL)
   {
      push(Aux, top(P1));
      pop(P1);
   }
   while(top(Aux) != NULL)
   {
      push(P2,top(Aux));
      push(P1,top(Aux));
      pop(Aux);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* P1 = create_stack();
   Stack* P2 = create_stack();
   Stack* pAux = create_stack();
   if(strlen(cadena) % 2 != 0)
   {
      return 0;
   }
   else{
      for(int i = 0; i < (strlen(cadena)); i++)
      {
         push(P1, cadena[i]);
      }
      for(int i = 0; i < (strlen(cadena)/2); i++)
      {
         push(pAux, top(P1));
         pop(P1);
      }
      while(top(pAux) != NULL)
      {
         push(P2, top(pAux));
         pop(pAux);
      }
      free(pAux);
      while(top(P2) != NULL)
      {
         char* Char1 = top(P1);
         char* Char2 = top(P2);
         if(Char1 == '(' && Char2 != ')') return 0;
         if(Char1 == '{' && Char2 != '}') return 0;
         if(Char1 == '[' && Char2 != ']') return 0;
         pop(P1);
         pop(P2);
      }
      return 1;
   }
}