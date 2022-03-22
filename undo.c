//
// Created by david on 21.03.2022.
//
#include "MyList.h"
#include <malloc.h>
#include "undo.h"

Undo* create_undo(){
    Undo* und = (Undo*)malloc(sizeof(Undo));
    und->versions = createEmpty();
    return und;
}

void destroy_a_list_with_meds(void* lst){
    destroy(lst, (void (*)(void*))destroyMedicament);
}

void destroy_undo(Undo* und){
    destroy(und->versions, destroy_a_list_with_meds);
    free(und);
}

void save(Undo* und, Farmacie* farm){
    MyList* new_instance = createEmpty();
    for(int i = 0; i < farm->allmeds->lg; i++){
        add(new_instance, copyMedicament((Medicament*)farm->allmeds->elems[i]));
    }
    add(und->versions, new_instance);
}

void undo(Undo* und, Farmacie* farm){
    if(und->versions->lg == 0)
        return;
    destroy(farm->allmeds, (void (*)(void *)) destroyMedicament);
    farm->allmeds = und->versions->elems[(und->versions->lg)-1];
    und->versions->lg--;
}