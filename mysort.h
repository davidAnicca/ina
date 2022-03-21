//
// Created by david on 20.03.2022.
//

#ifndef MYSORT_H_
#define MYSORT_H_

#include "MyList.h"
/*
   Tipul functie de comparare pentru 2 elemente
   returneaza 0 daca sunt egale, 1 daca m1>m2, -1 altfel
*/
typedef int(*FunctieComparare)(Medicament* m1, Medicament* m2);

/*
	Sorteaza in place
	cmpF - relatia dupa care se sorteaza
*/
void sort(MyList* l, FunctieComparare cmpF);

#endif
