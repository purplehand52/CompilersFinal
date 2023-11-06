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
