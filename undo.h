//
// Created by david on 21.03.2022.
//

#ifndef UNDOINA2_UNDO_H
#define UNDOINA2_UNDO_H

#include "MyList.h"
#include "service.h"

typedef struct{
    MyList* versions;
}Undo;
/*
 * creează un undo
 */
Undo* create_undo(); //tested
/*
 * distruge un undo
 */
void destroy_undo(Undo*);   ///tested
/*
 * salvează ultima instanță
 * se apelează înainte de orice modificare
 */
void save(Undo*, Farmacie*);

/*
 * returnează ultima instanță
 */
void undo(Undo*, Farmacie*);

#endif //UNDOINA2_UNDO_H
