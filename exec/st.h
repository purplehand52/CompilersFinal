struct st
{
    int rows,cols;
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
    struct List* target_params;
    struct BlockTable* next;
};

struct GateTable{
    char *id;
    int rows,cols;
    struct GateTable* next;
};

/* Output Symbol Table */
/* Primitives List */
enum Primitives{INT, UINT, FLOAT, COMPLEX, STRING, MATRIX, STATE, BOOL};

struct OutputSymbolEntry{
    char* id;
    int type;
    bool primitive;
    int dim;
    struct OutputSymbolEntry* next;
};