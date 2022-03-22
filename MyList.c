//
// Created by david on 20.03.2022.
//

#include "MyList.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>
/*
	Creeaza o lista goala
*/
MyList* createEmpty() {
    MyList* rez = (MyList*) malloc(sizeof(MyList));
    rez->lg = 0;
    rez->cap = 2;
    rez->elems = (ElemType*)malloc(sizeof(ElemType) * rez->cap);
    return rez;
}

/*
  Distruge lista
*/
void destroy(MyList* l, void (*destructor)(void*)) {
    //dealoca medicamente
    for (int i = 0; i < l->lg; i++) {
        destructor(l->elems[i]);
    }
    free(l->elems);
    free(l);
}

/*
  Returneaza un element din lista
  poz - pozitia elemntului, pozitie valida
  returneaza elemtnul de pe acea pozitie
*/
ElemType get(MyList* l, int poz) {
    return l->elems[poz];
}

/*
	Modifica elementul de pe o pozitie data
	returneaza elemntul suprascris
*/
ElemType set(MyList* l, int poz, Medicament* m) {
    ElemType rez = l->elems[poz];
    (l->elems[poz]) = m;
    return rez;
}

/*
  returneaza nr de elemente din lista
*/
int size(MyList* l) {
    return l->lg;
}

/*
  Aloca mai multa memorie daca e nevoie
*/
void ensureCapacity(MyList* l) {
    if (l->lg < l->cap) {
        return; //we have room
    }
    //alocate more memory
    int newCapacity = l->cap + 2;
    ElemType* nElems = (ElemType*)malloc(sizeof(ElemType) * newCapacity);
    //copy elems
    for (int i = 0; i < l->lg; i++) {
        nElems[i] = l->elems[i];
    }
    //dealocate old vector
    free(l->elems);
    l->elems = nElems;
    l->cap = newCapacity;
}

/*
  Adauga un element in lista
  post: elementul este adugat la finalul listei
*/
void add(MyList* l, ElemType el) {
    ensureCapacity(l);
    l->elems[l->lg] = el;
    l->lg++;
}
/*
	Sterge un element din lista de pe o pozitie data
	pre: poz-integer
		 l- MyList
	post: elementul este sters
*/
ElemType delete_m(MyList* l, int poz) {
    ElemType el = l->elems[poz];
    for (int i = poz; i < l->lg - 1; i++) {
        l->elems[i] = l->elems[i + 1];
    }
    l->lg--;
    return el;
}

/*
  Copie a listei
  returneaza Mylist care are aceleasi elemente precum l
*/
MyList* copyList(MyList* l) {
    MyList* rez = createEmpty();
    for (int i = 0; i < size(l); i++) {
        ElemType m = get(l, i);
        add(rez, m);
    }
    return rez;
}

void testCreateList() {
    MyList* l = createEmpty();
    assert(size(l) == 0);
    destroy(l, (void (*)(void*))destroyMedicament);
}
void testIterateList() {
    MyList* l = createEmpty();
    add(l, createMedicament(1,"nurofen", 200,5));
    add(l, createMedicament(2,"paduden", 400, 3));
    assert(size(l) == 2);
    Medicament* m = get(l, 0);

    assert(m->cod==1);
    m = get(l, 1);
    assert(strcmp(m->nume, "paduden") == 0);
    destroy(l, (void (*)(void*))destroyMedicament);
}

void testCopyList() {
    MyList* l = createEmpty();
    add(l, createMedicament(1, "nurofen", 200, 5));
    add(l, createMedicament(2, "paduden", 400, 3));
    MyList* l2 = copyList(l);
    assert(size(l2) == 2);
    Medicament* m = get(l2, 0);
    assert(m->cod == 1);
    destroy(l, (void (*)(void*))destroyMedicament);
    free(l2->elems);
    free(l2);
}

void testResize() {
    MyList* l = createEmpty();
    for (int i = 0; i < 10; i++) {
        add(l, createMedicament(1, "nurofen", 200, 5));
    }
    assert(size(l) == 10);
    destroy(l, (void (*)(void*))destroyMedicament);
}



