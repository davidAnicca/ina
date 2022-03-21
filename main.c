


#include <stdio.h>

#include "medicament.h"
#include "MyList.h"
#include "service.h"
#include "undo_tests.h"


void testAll() {

    testCreateDestroy();
    printf("create destroy\n");
    testCreateList();
    printf("create list\n");
    testIterateList();
    printf("iter list\n");
    testCopyList();
    printf("copy \n");
    testAddMedicament();
    printf("add med\n");
    testAddInvalidMedicament();
    printf("add invalid\n");
    testResize();
    printf("test resize\n");
    testSorts();
    printf("sort\n");
    testModifyService();
    printf("mod srv\n");
    testFindService();
    printf("find srv\n");
    testDeleteService();
    printf("delete srv\n");
}

void readMedicament(Farmacie* farm) {
    printf("Cod:");
    int cod;
    scanf("%d", &cod);
    printf("Nume:");
    char nume[30];
    scanf("%s", nume);
    printf("Concentratie:");
    float c;
    scanf("%f", &c);
    printf("Cantitate:");
    int cant;
    scanf("%d", &cant);
    int error = addMedicament(farm, cod, nume, c, cant);
    if (error != 0) {
        printf("Medicament invalid.\n");
    }
    else {
        printf("Medicament adaugat cu succes.\n");
    }
}

void printAllMeds(MyList* l) {
    printf("Medicamente:\n");
    for (int i = 0; i < size(l); i++) {
        Medicament* m = get(l, i);
        printf("Cod:%d Nume:%s Concentratie=%f Cantitate=%d\n", m->cod, m->nume, m->concentratie, m->cantitate);
    }
}

void ui_filtruLitera(Farmacie* farm) {
    printf("Litera:");
    char c[2]="";
    scanf("%s", c);
    MyList* filtered = filterLitera(farm, c);
    printAllMeds(filtered);
    destroy(filtered, destroyMedicament);
}

void ui_filtruStoc(Farmacie* farm) {
    printf("Stoc:");
    int st;
    scanf("%d", &st);
    MyList* filtered = filterStoc(farm, st);
    printAllMeds(filtered);
    destroy(filtered, destroyMedicament);
}

void showAll(Farmacie* farm) {
    MyList* meds = filterStoc(farm, 0);
    printAllMeds(meds);
    destroy(meds, destroyMedicament);
}


void ui_sortByName(Farmacie* farm) {
    MyList* meds = sortByName(farm);
    printAllMeds(meds);
    destroy(meds, destroyMedicament);
}

void ui_sortByQuantity(Farmacie* farm) {
    MyList* meds = sortByQuantity(farm);
    printAllMeds(meds);
    destroy(meds, destroyMedicament);
}

void ui_modify(Farmacie* farm) {
    printf("Cod:");
    int cod;
    scanf("%d", &cod);
    printf("Noul nume:");
    char nume[30];
    scanf("%s", nume);
    printf("Noua concentratie:");
    float c;
    scanf("%f", &c);
    printf("Cantitate:");
    int cant;
    scanf("%d", &cant);
    int succes = modifyMedicament(farm, cod, nume, c, cant);
    if (succes != 0) {
        printf("Medicament modificat cu succes.\n");
    }
    else {
        printf("Medicament invalid.\n");
    }

}
void ui_delete(Farmacie* farm) {
    printf("Cod:");
    int cod;
    scanf("%d", &cod);
    int succes = deleteMedicament(farm, cod);
    if (succes != 0) {
        printf("Medicament sters cu succes.\n");
    }
    else {
        printf("Medicament invalid.\n");
    }
}
void run() {
    Farmacie* farm = createFarmacie();
    int ruleaza = 1;
    while (ruleaza) {
        printf("0 Exit\n1 Add\n2 Print all\n3 Filter name\n4 Filter stock\n5 Sort by name\n6 Sort by quantity\n7 Modify\n8 Delete\nCommand:");
        int cmd = 0;
        scanf("%d", &cmd);
        switch (cmd) {
            case 0:
                ruleaza = 0;
                break;
            case 1:
                readMedicament(farm);
                break;
            case 2:
                showAll(farm);
                break;
            case 3:
                ui_filtruLitera(farm);
                break;
            case 4:
                ui_filtruStoc(farm);
                break;
            case 5:
                ui_sortByName(farm);
                break;
            case 6:
                ui_sortByQuantity(farm);
                break;
            case 7:
                ui_modify(farm);
                break;
            case 8:
                ui_delete(farm);
                break;
            default:
                printf("Comanda invalida!\n");
        }
    }
    destroyFarmacie(farm);
}


int main() {
    testAll();
    run_undo();
    run();
    return 0;
}



