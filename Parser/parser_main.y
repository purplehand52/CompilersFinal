%token NUMBER
%token GATE, BLOCK_ID, ID
%token MEASURE, CONDITION, OTHERWISE, BARRIER
%token FOR, FOR_LEX, FOR_ZIP

%%

main_stmt_list: 
    main_stmt_list main_stmt
    | main_stmt
    ;

main_stmt:
    call_stmt
    | measure_stmt
    | condition_stmt
    | for_stmt
    | for_lex_stmt
    | for_zip_stmt
    | barrier_stmt
    ;

register:
    NUMBER  /* check non negative*/
    | ID
    ;

call_stmt:
    classic_control GATE ':' quantum_control register
    | classic_control BLOCK_ID ':' quantum_control register
    | classic_control BLOCK_ID ':' quantum_control '(' register_list ')'
    ;

register_list:
    register_list ',' register
    | register
    ;

classic_control:
    /* epsilon */
    | register '?'
    | '(' register_list ')' '?'
    ;

quantum_control:
    /* epsilon */
    | register ARROW
    | '(' register_list ')' ARROW
    ;

measure_stmt:
    MEASURE ':' register ARROW register

barrier_stmt:
    '\\' BARRIER
    ;

condition_stmt:
    CONDITION '(' expr ')' '{' main_stmt_list '}'
    | CONDITION '(' expr ')' '{' main_stmt_list '}' OTHERWISE '{' main_stmt_list '}'
    ;

/* negative numbers? */
value:
    NUMBER
    | ID
    ;

range: 
    value ':' value
    | value ':' value ':' value
    ;

range_list:
    range_list ',' range
    range
    ;

var_list:
    var_list ',' ID
    ID
    ;

for_stmt:
    FOR ID IN '(' range ')' '{' main_stmt_list '}'
    ;

for_lex_stmt:
    FOR_LEX '(' var_list ')'  IN '(' range_list ')' '{' main_stmt_list '}'
    ;

for_zip_stmt:
    FOR_ZIP '(' var_list ')'  IN '(' range_list ')' '{' main_stmt_list '}'
    ;