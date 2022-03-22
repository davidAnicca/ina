//
// Created by david on 20.03.2022.
//
#include "service.h"
#include "mysort.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>


/*
	creare farmacie
*/
Farmacie* createFarmacie() {
    Farmacie* rez = (Farmacie*)malloc(sizeof(Farmacie));
    rez->allmeds = createEmpty();
    return rez;
}

/*
	distrugere farmacie
*/
void destroyFarmacie(Farmacie* farm) {
    destroy(farm->allmeds, destroyMedicament);
    free(farm);
}

/*
	adaugare medicament farmacie
*/

int addMedicament(Farmacie* farm, int cod, char* nume, float concentratie, int cantitate) {
    Medicament* m = createMedicament(cod, nume, concentratie, cantitate);
    int errorCode = validate(m);
    if (errorCode != 0) {
        destroyMedicament(m);
        return errorCode;
    }
    add(farm->allmeds, m);
    return 0;//ok
}

/*
int addMedicament(MyList* farm, int cod, char* nume, float concentratie, int cantitate) {
	Medicament m = createMedicament(cod, nume, concentratie, cantitate);
	int errorCode = validate(m);
	if (errorCode != 0) {
		destroyMedicament(&m);
		return errorCode;
	}
	add(farm, m);
	return 0;//ok
}
*/
int findMedicament(Farmacie* farm, int cod) {
    int poz = -1;
    for (int i = 0; i < size(farm->allmeds); i++) {
        //Medicament m = get(farm, i);
        Medicament* m = get(farm->allmeds, i);
        if (m->cod == cod) {
            poz = i;
            break;
        }
    }
    return poz;
}

/*
int findMedicament(MyList* farm, int cod) {
	int poz = -1;
	for (int i = 0; i < farm->lg; i++) {
		Medicament m = get(farm, i);
		if (m.cod == cod) {
			poz = i;
			break;
		}
	}
	return poz;
}
*/
int modifyMedicament(Farmacie* farm, int cod, char* nume_nou,float concentratie_noua, int cantitate) {
    int poz = findMedicament(farm, cod);
    if (poz != -1) {
        Medicament* med_nou = createMedicament(cod, nume_nou, concentratie_noua, cantitate);
        //Medicament m = get(farm, poz);
        Medicament* m = get(farm->allmeds, poz);
        destroyMedicament(m);
        //set(farm, poz, med_nou);
        set(farm->allmeds, poz, med_nou);
        return 1;
    }
    return 0;
}

/*
int modifyMedicament(MyList* farm, int cod, char* nume_nou, float concentratie_noua, int cantitate) {
	int poz = findMedicament(farm, cod);
	if (poz != -1) {
		Medicament med_nou = createMedicament(cod, nume_nou, concentratie_noua, cantitate);
		Medicament m = get(farm, poz);
		destroyMedicament(&m);
		set(farm, poz, med_nou);
		return 1;
	}
	return 0;
}
*/
int deleteMedicament(Farmacie* farm, int cod) {
    int poz_to_delete = findMedicament(farm, cod);
    if (poz_to_delete != -1) {
        //Medicament m = delete_m(farm, poz_to_delete);
        Medicament* m = delete_m(farm->allmeds, poz_to_delete);
        destroyMedicament(m);
        return 1;
    }
    return 0;
}

/*
int deleteMedicament(MyList* farm, int cod) {
	int poz_to_delete = findMedicament(farm, cod);
	if (poz_to_delete != -1) {
		Medicament m = delete_m(farm, poz_to_delete);
		//
		destroyMedicament(&m);
		return 1;
	}
	return 0;
}
*/
/*
	filtru
	medicamente unde stocul disponibil este mai mic decat o valoare data
*/

MyList* filterStoc(Farmacie* farm, int stoc) {
    if (stoc == 0) {
        return copyList(farm->allmeds);
    }
    MyList* rez = createEmpty();
    for (int i = 0; i < size(farm->allmeds); i++) {
        Medicament* m = get(farm->allmeds, i);
        if (m->cantitate<stoc) {
            add(rez, m);
        }
    }
    return rez;
}

/*
MyList filterStoc(MyList* farm, int stoc) {
	if (stoc == 0) {
		return copyList(farm);
	}
	MyList rez = createEmpty();
	for (int i = 0; i < farm->lg; i++) {
		Medicament m = get(farm, i);
		if (m.cantitate < stoc) {
			add(&rez, copyMedicament(&m));
		}
	}
	return rez;
}
*/
/*
	filtru
	medicamente cu numele incepand cu o litera data
*/

MyList* filterLitera(Farmacie* farm, char* litera) {
    if (litera == NULL || strlen(litera) == 0) {
        return copyList(farm->allmeds);
    }
    MyList* rez = createEmpty();
    for (int i = 0; i < size(farm->allmeds); i++) {
        Medicament* m = get(farm->allmeds, i);

        //strcpy_s(caract,1, (m.nume)[0]);
        //if (strcmp(caract, litera) == 0)
        if(strstr(m->nume, litera)==(m->nume))
        {
            add(rez, m);
        }
    }
    return rez;
}

MyList* filterConcentratie(Farmacie* farm, float concentratie) {
    if (concentratie == 0) {
        return copyList(farm->allmeds);
    }
    MyList* rez = createEmpty();
    for (int i = 0; i < size(farm->allmeds); i++) {
        Medicament* m = get(farm->allmeds, i);

        //strcpy_s(caract,1, (m.nume)[0]);
        //if (strcmp(caract, litera) == 0)
        if(m->concentratie > concentratie)
        {
            add(rez, m);
        }
    }
    return rez;
}

/*
MyList filterLitera(MyList* farm, char* litera) {
	if (litera == NULL || strlen(litera) == 0) {
		return copyList(farm);
	}
	MyList rez = createEmpty();
	for (int i = 0; i < farm->lg; i++) {
		Medicament m = get(farm, i);

		//strcpy_s(caract,1, (m.nume)[0]);
		//if (strcmp(caract, litera) == 0)
		if (strstr(m.nume, litera) == (m.nume))
		{
			add(&rez, copyMedicament(&m));
		}
	}
	return rez;
}
*/
int cmpNume(Medicament* m1, Medicament* m2) {
    return strcmp(m1->nume, m2->nume);
}

int cmpCantitate(Medicament* m1, Medicament* m2) {
    if (m1->cantitate > m2->cantitate) {
        return 1;
    }
    return 0;
}
/*
	sortare dupa nume
*/
MyList* sortByName(Farmacie* farm) {
    MyList* l = copyList(farm->allmeds);
    sort(l, cmpNume);
    return l;
}

/*
	sortare dupa cantitate
*/
MyList* sortByQuantity(Farmacie* farm) {
    MyList* l = copyList(farm->allmeds);
    sort(l, cmpCantitate);
    return l;
}

void testAddMedicament() {
    Farmacie* farm = createFarmacie();
    addMedicament(farm, 1, "nurofen", 200, 5);
    addMedicament(farm, 2, "paduden", 400, 3);
    addMedicament(farm, 2, "padre", 400, 3);
    MyList* fil = filterLitera(farm, NULL);
    assert(size(fil) == 3);
    //destroy(filtered); lol
    free(fil->elems);
    free(fil);
    //MyList filtered = filterStoc(&farm, 0);
    MyList* filtered = filterStoc(farm, 0);
    assert(size(filtered) == 3);
    free(filtered->elems);
    free(filtered);
    MyList* filtered2 = filterStoc(farm, 4);
    assert(size(filtered2) == 2);
    free(filtered2->elems);
    free(filtered2);
    MyList* filtered3 = filterLitera(farm, "p");
    assert(size(filtered3) == 2);
    free(filtered3->elems);
    free(filtered3);
    destroyFarmacie(farm);
}




void testAddInvalidMedicament() {
    Farmacie* farm = createFarmacie();
    int errorCode = addMedicament(farm, -77, "paduden", 200, 5);
    assert(errorCode != 0);

    errorCode = addMedicament(farm, 1, "", 200, 5);
    assert(errorCode != 0);

    errorCode = addMedicament(farm, 1, "paduden", -200, 5);
    assert(errorCode != 0);

    errorCode = addMedicament(farm, 1, "paduden", 200, -5);
    assert(errorCode != 0);

    MyList* filtered = filterStoc(farm, 0);
    assert(size(filtered) == 0);
    free(filtered->elems);

    //filtered = filterLitera(&farm, NULL);
    //assert(size(&filtered) == 0);
    //destroy(&filtered);
    free(filtered);
    destroyFarmacie(farm);
}

void testSorts() {
    Farmacie* farm = createFarmacie();
    addMedicament(farm, 1, "a", 200, 1);
    addMedicament(farm, 2, "c", 400, 3);
    addMedicament(farm, 3, "b", 400, 2);
    MyList* l = sortByName(farm);
    assert(strcmp(((Medicament*)get(l, 1))->nume, "b") == 0);
    free(l->elems);
    free(l);
    MyList* l2 = sortByQuantity(farm);
    assert(((Medicament*)get(l2, 0))->cantitate == 1);
    assert(((Medicament*)get(l2, 1))->cantitate == 2);
    free(l2->elems);
    free(l2);
    destroyFarmacie(farm);

}
void testFindService() {
    Farmacie* farm = createFarmacie();
    addMedicament(farm, 1, "a", 200, 1);
    addMedicament(farm, 2, "c", 400, 3);
    addMedicament(farm, 3, "b", 400, 2);
    MyList* filtered = filterStoc(farm, 0);
    assert(size(filtered) == 3);
    free(filtered->elems);
    //assert(size(&farm) == 3);
    int poz = findMedicament(farm, 1);
    assert(poz == 0);
    poz = findMedicament(farm, 6);
    assert(poz == -1);
    free(filtered);
    destroyFarmacie(farm);
    //assert(size(&farm) == 0);



}
void testModifyService() {
    Farmacie* farm = createFarmacie();
    addMedicament(farm, 1, "a", 200, 1);
    addMedicament(farm, 2, "c", 400, 3);
    addMedicament(farm, 3, "b", 400, 2);
    MyList* filtered = filterStoc(farm, 0);
    assert(size(filtered) == 3);
    free(filtered->elems);
    //assert(size(&farm) == 3);
    int modificat_succes = modifyMedicament(farm, 1,"a",222,1);
    assert(modificat_succes == 1);
    int modificat_nesucces = modifyMedicament(farm, 333, "aa", 222, 1);
    assert(modificat_nesucces == 0);
    free(filtered);
    destroyFarmacie(farm);

}

void testDeleteService() {
    Farmacie* farm = createFarmacie();
    addMedicament(farm, 1, "a", 200, 1);
    addMedicament(farm, 2, "c", 400, 3);
    addMedicament(farm, 3, "b", 400, 2);
    MyList* filtered = filterStoc(farm, 0);
    assert(size(filtered) == 3);
    free(filtered->elems);
    //assert(size(&farm) == 3);
    //int sters_succes = deleteMedicament(&farm, 1, "aa", 222, 1);
    int sters_succes = deleteMedicament(farm, 1);
    assert(sters_succes == 1);
    //int sters_nesucces = deleteMedicament(&farm, 333, "aa", 222, 1);
    int sters_nesucces = deleteMedicament(farm, 333);
    assert(sters_nesucces == 0);
    free(filtered);
    destroyFarmacie(farm);

}

void test_concentratie(){
    Farmacie* farm = createFarmacie();
    addMedicament(farm, 1, "a", 200, 1);
    addMedicament(farm, 2, "c", 400, 3);
    addMedicament(farm, 3, "b", 400, 2);
    MyList* filtered = filterConcentratie(farm, 0);
    assert(size(filtered) == 3);
    free(filtered->elems);
    free(filtered);
    MyList* filtered2 = filterConcentratie(farm, 300);
    assert(size(filtered2) == 2);
    free(filtered2->elems);
    free(filtered2);

    destroyFarmacie(farm);
}



