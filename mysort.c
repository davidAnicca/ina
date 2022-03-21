//
// Created by david on 20.03.2022.
//

#include "mysort.h"


/**
* Sorteaza in place
* cmpf - relatia dupa care se sorteaza
*/
void sort(MyList* l, FunctieComparare cmpF) {
    int i, j;
    for (i = 0; i < size(l); i++) {
        for (j = i + 1; j < size(l); j++) {
            Medicament* m1 = get(l, i);
            Medicament* m2 = get(l, j);
            if (cmpF(m1, m2) > 0) {
                //interschimbam
                set(l, i, m2);
                set(l, j, m1);
            }
        }
    }
}




