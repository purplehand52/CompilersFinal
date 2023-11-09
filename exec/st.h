#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct st
{
    int rows,cols,type;
    int num;
    float real;
    char *str;
    int cond_count; /* For number of arguments in condense */
    int* cond_list; /* For arguments of condense */

    int level;
    bool prim;
    int dim;
    struct Complex
    {
        float real;
        float imag;
    } cpx;

    struct Quantum
    {
        struct Complex first;
        struct Complex second;
    } q;

    struct List
    {
        char *id;
        struct List *next;
    } list;
};

struct BlockTable{
    char * id;
    struct List* params;
    int len;
    struct BlockTable* next;
};

struct GateTable{
    char *id;
    int rows,cols;
    struct GateTable* next;
};

/* Output Symbol Table */
/* Primitives List */
enum Primitives{Uint, Int, Float, Complex, Matrix, State, Bool, String, Scope};
#define COMPATIBLE 4

struct OutputSymbolEntry{
    char* id;
    int type;
    bool primitive;
    bool isLoopId;
    /* int matrix[2]; */
    int dim;
    int level;
    struct OutputSymbolEntry* prev; // symtab will be modified near highest level, so reverse direction preferred
    /* Add pointer for scope expansion */
};
