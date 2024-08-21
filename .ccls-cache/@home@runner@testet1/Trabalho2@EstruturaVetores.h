#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H

// enumeracoes (enum) ajudam a deixar o codigo mais legivel, possibilitando que voce de significado
// as suas constantes, para mais informacoes https://en.cppreference.com/w/c/language/enum
// as constantes do enum em sua inicialização vao representar o numero resultante da soma do valor da
// constante anterior mais 1, caso nao haja valor algum na primeira constante ela vai ser inicializada com 0
enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO = -10, NUMERO_INEXISTENTE = -9,
       ESTRUTURA_AUXILIAR_VAZIA = -8, TAMANHO_INVALIDO = -7, SEM_ESPACO_DE_MEMORIA = -6, POSICAO_INVALIDA = -5,
       JA_TEM_ESTRUTURA_AUXILIAR = -4, SEM_ESTRUTURA_AUXILIAR = -3, SEM_ESPACO = -2, SUCESSO = -1};

typedef struct reg {
    int conteudo;
    struct reg *prox;
} No;

typedef struct {
   int * ponteiro;
   int tamanho;
   int quantidade;
} EstruturaPrincipal;

int criarEstruturaAuxiliar(int posicao, int tamanho);
int inserirNumeroEmEstrutura(int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
No *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No **inicio);

void inicializar();
void finalizar();
void dobrar(int *x);

#endif  // TRABALHO2_ESTRUTURAVETORES_H
