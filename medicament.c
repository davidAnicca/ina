//
// Created by david on 20.03.2022.
//
#include "medicament.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

/*
Creeaza medicament nou
*/
Medicament* createMedicament(int cod, char* nume, float concentratie, int cantitate) {

    Medicament* rez = (Medicament*)malloc(sizeof(Medicament));
    rez->cod = cod;
    size_t nrC = strlen(nume) + 1;
    rez->nume = (char*)malloc(sizeof(char) * nrC);
    if (rez->nume != NULL) {
        strcpy(rez->nume, nume);
    }
    //rez.nume = malloc(sizeof(char) * nrC);
    //strcpy_s(rez.nume, nrC, nume);
    rez->concentratie = concentratie;
    rez->cantitate = cantitate;
    return rez;

    /*
    Medicament rez;
    rez.cod = cod;
    int nrC = (int)strlen(nume) + 1;
    rez.nume = malloc(nrC*sizeof(char) );
    strcpy_s(rez.nume, nrC, nume);
    rez.concentratie = concentratie;
    rez.cantitate = cantitate;
    return rez;
    */
}

/*
Dealocare memorie ocupata de medicament
*/
void destroyMedicament(Medicament* m) {
    free(m->nume);
    free(m);
}

/*
Creeaza o copie a medicamentului
*/
Medicament* copyMedicament(Medicament* m) {
    return createMedicament(m->cod, m->nume, m->concentratie, m->cantitate);
}

/*
Valideaza medicament
return !=0 daca medicament e invalid
*/
int validate(Medicament* m) {
    if (m->cod < 0) {
        return 1;
    }
    if (strlen(m->nume) == 0) {
        return 2;
    }
    if (m->concentratie < 0) {
        return 3;
    }
    if (m->cantitate < 0) {
        return 4;
    }
    return 0;
}

void testCreateDestroy() {
    Medicament* m = createMedicament(1, "paduden", 200, 5);
    assert(m->cod == 1);
    assert(strcmp(m->nume, "paduden") == 0);
    assert(m->concentratie == 200.0);
    assert(m->cantitate == 5);

    destroyMedicament(m);
}




