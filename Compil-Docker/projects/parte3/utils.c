// Estrutura da tabela de simbolos

#define TAM_TAB 100

struct elemTabSimbolos
{
    char id[100]; // identificador
    int end;      // endereco
    int tip;      // tipo
} tabSimb[TAM_TAB], elemTab;

int posTab = 0;

int buscaSimbolo(char *id)
{
    int i;
    for (i = posTab - 1; strcmp(tabSimb[i].id, id) && i >= 0; i--)
        ;
    return i;
}

void insereSimbolo(struct elemTabSimbolos elem)
{
    int i;
    if (posTab == TAM_TAB)
        yyerror("Tabela de Simbolos Cheia!");
    i = buscaSimbolo(elem.id);
    if (i != -1)
        yyerror("Identificador duplicado");
    tabSimb[posTab++] = elem;
}