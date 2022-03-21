cmake_minimum_required(VERSION 3.22)
project(undoina2 C)

set(CMAKE_C_STANDARD 99)

add_executable(undoina2 main.c medicament.c medicament.h MyList.c MyList.h mysort.h service.h mysort.c service.c undo.h undo.c undo_tests.h undo_tests.c)
