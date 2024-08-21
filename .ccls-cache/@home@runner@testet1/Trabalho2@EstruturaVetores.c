#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

EstruturaPrincipal vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    if (vetorPrincipal[posicao].ponteiro != NULL) {
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }
    // se posição é um valor válido {entre 1 e 10}
    else if (posicao > 10 || posicao < 1) {
        retorno = POSICAO_INVALIDA;
    }
    // o tamanho ser muito grande
    else if (tamanho > 20) {
        retorno = SEM_ESPACO_DE_MEMORIA;
    }
    // o tamanho nao pode ser menor que 1
    else if (tamanho < 1) {
        retorno = TAMANHO_INVALIDO;
    }
    // deu tudo certo, crie
    else {    
        vetorPrincipal[posicao].ponteiro = malloc(tamanho * sizeof(int));
        vetorPrincipal[posicao].tamanho = tamanho;
        vetorPrincipal[posicao].quantidade = 0;
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;

    if (posicao > 10 || posicao < 1) {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao].ponteiro != NULL)
        {
            if (vetorPrincipal[posicao].quantidade < vetorPrincipal[posicao].tamanho)
            {
                //insere
                vetorPrincipal[posicao].ponteiro[vetorPrincipal[posicao].quantidade] = valor;
                vetorPrincipal[posicao].quantidade += 1;
                
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = 0;
    if (posicao > 10 || posicao < 1) {
        retorno = POSICAO_INVALIDA;
    }
    else {
        if (vetorPrincipal[posicao].ponteiro != NULL) {
            if (vetorPrincipal[posicao].quantidade > 0) {
                vetorPrincipal[posicao].quantidade --;
                retorno = SUCESSO;
            }
            else {
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }          
        }
        else {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int i, encontrado, retorno = 0;
    if (posicao > 10 || posicao < 1) {
        retorno = POSICAO_INVALIDA;
    }
    else {
        if (vetorPrincipal[posicao].ponteiro != NULL) {
            if (vetorPrincipal[posicao].quantidade > 0) {
                for(i = 0, encontrado = 0; i < vetorPrincipal[posicao].quantidade && encontrado == 0; i++) {
                    if (valor == vetorPrincipal[posicao].ponteiro[i]) {
                        encontrado = 1;
                    }
                }
            if (encontrado) {
                for (i = i - 1; i < vetorPrincipal[posicao].quantidade; i++) {
                    vetorPrincipal[posicao].ponteiro[i] = vetorPrincipal[posicao].ponteiro[i + 1];
                }
                vetorPrincipal[posicao].quantidade --;
                retorno = SUCESSO;
            }
            else {
                retorno = NUMERO_INEXISTENTE;
            }
            }
            else {
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }   
        else {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int i, retorno = 0;
    if (posicao > 10 || posicao < 1) {
        retorno = POSICAO_INVALIDA;
    }
    else {
        if (vetorPrincipal[posicao].ponteiro != NULL) {
            if (vetorPrincipal[posicao].quantidade > 0) {
                for (i = 0; i < vetorPrincipal[posicao].quantidade; i++) {
                    (vetorAux[i] = vetorPrincipal[posicao].ponteiro[i]);
                }
                retorno = SUCESSO;
            }
            else {
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0, i, j, aux;
    if (posicao > 10 || posicao < 1) {
        retorno = POSICAO_INVALIDA;
    }
    else {
        if (vetorPrincipal[posicao].ponteiro != NULL) {
            if (vetorPrincipal[posicao].quantidade > 0) {
                for (i = 0; i < vetorPrincipal[posicao].quantidade; i++) {
                    vetorAux[i] = vetorPrincipal[posicao].ponteiro[i];
                }
                for (i = 0; i < vetorPrincipal[posicao].quantidade - 1; i++) {
                    for (j = i + 1; j < vetorPrincipal[posicao].quantidade; j++) {
                        if (vetorAux[i] > vetorAux[j]) {
                            aux = vetorAux[i];
                            vetorAux[i] = vetorAux[j];
                            vetorAux[j] = aux;
                        }
                    }
                }
            }
            else {
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0, i, j;
    int contador = 0;
    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].ponteiro != NULL) {
            if (vetorPrincipal[i].quantidade > 0) {
                for (j = 0; j < vetorPrincipal[i].quantidade; j++) {
                    vetorAux[contador] = vetorPrincipal[i].ponteiro[j];
                    contador++;
                }
            }
        }    
    }
    if (contador > 0) {
        retorno = SUCESSO;
    }
    else {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i, j, retorno = 0, contador = 0, a, b, troca;
    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].ponteiro != NULL) {
            if (vetorPrincipal[i].quantidade > 0) {
                for (j = 0; j < vetorPrincipal[i].quantidade; j++) {
                    vetorAux[contador] = vetorPrincipal[i].ponteiro[j];
                    contador++;
                }
            }
        }
    }
    if (contador > 0) {
        for (a = 0; a < contador; a++) {
            for (b = a + 1; b < contador; b++) {
                if (vetorAux[a] > vetorAux[b]) {
                    troca = vetorAux[a];
                    vetorAux[a] = vetorAux[b];
                    vetorAux[b] = troca;
                }
            }
        }
        retorno = SUCESSO;
    }
    else {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
 
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    if (posicao > 10 || posicao < 1) {
        retorno = POSICAO_INVALIDA;
    }
    else {
        if (novoTamanho < 1) {
            retorno = NOVO_TAMANHO_INVALIDO;
        }
        else {
            if (vetorPrincipal[posicao].ponteiro != NULL) { 
                    int a = vetorPrincipal[posicao].tamanho + novoTamanho;
                    int * novoPonteiro = realloc(vetorPrincipal[posicao].ponteiro, (a * sizeof(int)));
                    if (!novoPonteiro) {
                        retorno = SEM_ESPACO_DE_MEMORIA;
                    }
                    else {
                        vetorPrincipal[posicao].tamanho = a;
                        retorno = SUCESSO;
                    }
            }
            else {
                retorno = SEM_ESTRUTURA_AUXILIAR;
            }
        }
    return retorno;
}
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;

    if (posicao > 10 || posicao < 1) {
        retorno = POSICAO_INVALIDA;
    }
    else {
        if (vetorPrincipal[posicao].ponteiro != NULL) {
            if (vetorPrincipal[posicao].quantidade > 0) {
                retorno = vetorPrincipal[posicao].quantidade;
            }
            else {
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    int i;
    for (i = 0; i < TAM; i++) {
        vetorPrincipal[i].ponteiro = NULL;
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].quantidade = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

    void finalizar(){
        int i;
        for (i = 0; i < TAM; i++) {
            if (vetorPrincipal[i].ponteiro != NULL) {
                free (vetorPrincipal[i].ponteiro);
            }
        }
    }
