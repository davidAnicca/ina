//
// Created by david on 20.03.2022.
//



#pragma once

#include "MyList.h"

typedef struct {
    MyList* allmeds;
} Farmacie;

/*
	creare farmacie
*/
Farmacie* createFarmacie();

/*
	distrugere farmacie
*/
void destroyFarmacie(Farmacie* farm);

/*
	adaugare medicament farmacie
*/
int addMedicament(Farmacie* farm, int cod, char* nume, float concentratie, int cantitate);

/*
	filtru
	medicamente unde stocul disponibil este mai mic decat o valoare data
*/
MyList* filterStoc(Farmacie* farm, int stoc);
/*
 * filtrare dupa concentratie.
 * toate medicamentele cu o concentratie mai mare decat cea data
 */
MyList* filterConcentratie(Farmacie* farm, float concentratie);
void test_concentratie();
/*
	filtru
	medicamente cu numele incepand cu o litera data
*/
MyList* filterLitera(Farmacie* farm, char* litera);

/*
	sortare dupa nume
*/
MyList* sortByName(Farmacie* farm);

/*
	sortare dupa cantitate
*/
MyList* sortByQuantity(Farmacie* farm);

int findMedicament(Farmacie* farm, int cod);
int deleteMedicament(Farmacie* farm, int cod);
int modifyMedicament(Farmacie* farm, int cod, char* nume_nou, float concentratie_noua, int cantitate);


void testAddMedicament();
void testAddInvalidMedicament();
void testSorts();
void testModifyService();
void testFindService();
void testDeleteService();

