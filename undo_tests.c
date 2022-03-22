//
// Created by david on 21.03.2022.
//
#include <stdio.h>
#include <assert.h>
#include "undo.h"



void create_destroy_undo_test(){
    Undo* und = create_undo();
    assert(und->versions->lg == 0);
    destroy_undo(und);
}

void save_test(){
    Farmacie* farm = createFarmacie();
    Undo* und = create_undo();
    save(und, farm);
    assert(und->versions->lg==1);
    assert(((MyList*)und->versions->elems[0])->lg == 0);
    addMedicament(farm, 1, "xanax", (float)0.25, 100);
    save(und, farm);
    assert(und->versions->lg==2);
    assert(((MyList*)und->versions->elems[1])->lg == 1);
    assert(((Medicament*)((MyList*)und->versions->elems[1])->elems[0])->cod == 1);
    addMedicament(farm, 2, "anxiar", (float)0.25, 100);
    save(und, farm);
    assert(und->versions->lg==3);
    assert(((MyList*)und->versions->elems[2])->lg == 2);
    assert(((Medicament*)((MyList*)und->versions->elems[2])->elems[0])->cod == 1);
    assert(((Medicament*)((MyList*)und->versions->elems[2])->elems[1])->cod == 2);
    destroy_undo(und);
    destroyFarmacie(farm);
}

void undo_test(){
    Farmacie* farm = createFarmacie();
    Undo* und = create_undo();
    addMedicament(farm, 1, "xanax", (float)0.25, 100);
    addMedicament(farm, 2, "anxiar", (float)0.25, 100);
    save(und, farm);
    deleteMedicament(farm, 1);
    undo(und, farm);
    assert(farm->allmeds->lg == 2);
    assert(((Medicament*)farm->allmeds->elems[0])->cod==1);
    assert(((Medicament*)farm->allmeds->elems[1])->cod==2);
    save(und, farm);
    addMedicament(farm, 3, "escitalopram", (float)0.25, 100);
    save(und, farm);
    deleteMedicament(farm, 2);
    undo(und, farm);
    assert(farm->allmeds->lg == 3);
    assert(((Medicament*)farm->allmeds->elems[2])->cod==3);
    undo(und, farm);
    assert(farm->allmeds->lg == 2);
    assert(((Medicament*)farm->allmeds->elems[0])->cod==1);
    assert(((Medicament*)farm->allmeds->elems[1])->cod==2);

    destroy_undo(und);
    destroyFarmacie(farm);
}

void run_undo(){
    create_destroy_undo_test();
    save_test();
    undo_test();
    printf("undo tests done\n\n\n\n\n");
}
