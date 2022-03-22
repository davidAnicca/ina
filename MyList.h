//
// Created by david on 20.03.2022.
//



#pragma once
#include "medicament.h"

typedef void* ElemType;
typedef struct {
    ElemType* elems;
    int lg; //lungime
    int cap; //capacitate
} MyList;

/*
  Creeaza o lista goala
*/
MyList* createEmpty();

/*
  Distruge lista
*/
void destroy(MyList* l, void (*destructor)(void*));

/*
  Returneaza un element din lista
  poz - pozitia elemntului, pozitie valida
  returneaza elemtnul de pe acea pozitie
*/
ElemType get(MyList* l, int poz);

/*
	Modifica elementul de pe o pozitie data
	returneaza elemntul suprascris
*/
ElemType set(MyList* l, int poz, Medicament* m);

/*
  returneaza nr de elemente din lista
*/
int size(MyList* l);

/*
  Adauga un element in lista
  post: elemtul este adugat la finalul listei
*/
void add(MyList* l, ElemType el);

/*
  Copie a listei
  returneaza Mylist care are aceleasi elemente precum l
*/
MyList* copyList(MyList* l);

ElemType delete_m(MyList* l, int poz);

void testCreateList();
void testIterateList();
void testCopyList();
void testResize();



