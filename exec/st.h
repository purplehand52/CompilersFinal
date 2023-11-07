#include<stdbool.h>

struct st
{
    int rows,cols,type;
    int num;
    float real;
    char *str;
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
enum Primitives{Int, Uint, Float, Complex, String, Matrix, State, Bool};

struct OutputSymbolEntry{
    char* id;
    int type;
    bool primitive;
    int dim;
    struct OutputSymbolEntry* next;
};