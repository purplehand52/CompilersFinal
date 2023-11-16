#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct st
{
    int flag;
    int rows,cols,type;
    int num;
    float real;
    char *str;
    char* str2;
    int cond_count; /* For number of arguments in condense */
    int* cond_list; /* For arguments of condense */
    int out_flag; /* flag for output 0 -> id, 1 -> cout, 2 -> qout */
    char *start,*end,*step;

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

    struct List2
    {
        char *start,*step,*end;
        struct List2 *next;
    } list2;
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
#define COMPARABLE 3

struct OutputSymbolEntry{
    char* id;
    int level;
    int type;
    bool primitive;
    int matrix_dim; /* Matrix_dim */
    int dim;
    bool isLoopId;
    struct OutputSymbolEntry* prev; // symtab will be modified near highest level, so reverse direction preferred
    /* Add pointer for scope expansion */
};
