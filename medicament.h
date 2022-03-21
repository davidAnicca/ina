//
// Created by david on 20.03.2022.
//

#ifndef UNDOINA2_MEDICAMENT_H
#define UNDOINA2_MEDICAMENT_H

#pragma once

typedef struct {
    int cod;
    char* nume;
    float concentratie;
    int cantitate;
}Medicament;

/*
Creeaza medicament nou
*/
Medicament* createMedicament(int cod, char* nume, float concentratie, int cantitate);

/*
Dealocare memorie ocupata de medicament
*/
void destroyMedicament(Medicament* m);

/*
Creeaza o copie a medicamentului
*/
Medicament* copyMedicament(Medicament* m);

/*
Valideaza medicament
return !=0 daca medicament e invalid
*/
int validate(Medicament* m);

void testCreateDestroy();

#endif //UNDOINA2_MEDICAMENT_H
