// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Lara Carolina Brito dos Santos
//  email: laracarolina2110@gmail.com
//  Matrícula: 20232160013
//  Semestre: 2°

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "LaraSantos20232160013.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}


DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int anobissexto(int iAno) {
    if (((iAno % 4 == 0) && (iAno % 100) != 0) || (iAno % 400 == 0)) {
      return 1;
    }
  else {
    return 0;
  }
}

int validacaodadata(int iDia, int iMes, int iAno) {
  int diaspormes[12] = {31, 28 + anobissexto(iAno), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  switch(iMes) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
          return (iDia >= 1 && iDia <= 31);
      case 4: case 6: case 9: case 11:
          return (iDia >= 1 && iDia <= 30);
      case 2: 
          return (iDia >= 1 && iDia <= diaspormes[1]);
      default: 
          return 0;
  }
}

int q1(char data[])
{
  DataQuebrada dq = quebraData(data);
  int iDia = dq.iDia;
  int iMes = dq.iMes;
  int iAno = dq.iAno;
  if (dq.valido) { 
    int i = validacaodadata(iDia, iMes, iAno);
    if (i == 1) {
      return 1;
    }
    else {
      return 0;
    }
  }
  else {
    return 0;
  }
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

void diferenca_datas(int Diainicial, int Mesinicial, int Anoinicial, int  Diafinal, int Mesfinal, int Anofinal, int *anos, int *meses, int *dias) {
    *anos = Anofinal - Anoinicial;
    *meses = Mesfinal - Mesinicial;
    *dias = Diafinal - Diainicial;

      if (*dias < 0) {
          (*meses)--;
          *dias += anobissexto(Anofinal)? 29 : 28; // Considerar fevereiro de forma adequada
      }

      if (*meses < 0) {
          (*anos)--;
          *meses += 12;
      }
  }

DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    int anos, meses, dias;
    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      DataQuebrada dq = quebraData(datainicial);

      int Diainicial = dq.iDia;
      int Mesinicial = dq.iMes;
      int Anoinicial = dq.iAno;
      
      DataQuebrada dq2 = quebraData(datafinal);

      int Diafinal = dq2.iDia;
      int Mesfinal = dq2.iMes;
      int Anofinal = dq2.iAno;

      diferenca_datas(Diainicial, Mesinicial, Anoinicial, Diafinal, Mesfinal, Anofinal, &anos, &meses, &dias);

      if (anos < 0 || meses < 0 || anos < 0) {
        dma.retorno = 4;
        return dma;
      }
        dma.retorno = 1;
        dma.qtdDias = dias;
        dma.qtdMeses = meses;
        dma.qtdAnos = anos;
        return dma;
      

    }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
    int contador = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        char caractere = texto[i];


        // Considerando sensibilidade a maiúsculas e minúsculas, se necessário
        if (!isCaseSensitive) {
            caractere = tolower(caractere);
            c = tolower(c);
        }

        if (caractere == c) {
            contador++;
        }
    }
    return contador;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
  int tamanho_texto = strlen(strTexto);
  int tamanho_palavra = strlen(strBusca);
  int contador = 0, Ocorrencias = 0, acento = 0;

  for (int i = 0; i <= tamanho_texto - tamanho_palavra; i++) {
    int j;
    int achou = 1;
    acento = 0;
    for (j = 0; j < tamanho_palavra; j++) {
      if (strTexto[i + j] != strBusca[j]) {
        achou=0;
        break;
      }
    }
    for (int k=0; k<= i+j; k++) {
      if (strTexto[k] < 0)
        acento++;
    }

    if (achou) {
        if (acento > 0) {
          posicoes[Ocorrencias * 2] = i + 1 - acento/2;
          posicoes[Ocorrencias * 2 + 1] = i + j - acento/2;
          Ocorrencias++;
        } else {
          posicoes[Ocorrencias * 2] = i + 1;
          posicoes[Ocorrencias * 2 + 1] = i + j;
          Ocorrencias++;
        }
      }
    }

  return Ocorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
   int invertido = 0;

   while (num > 0) {
       int a = num % 10;

       invertido = invertido * 10 + a;

       num /= 10;

   }
   return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){

    int contador = 0;

    char numerobasestr[30];
    char numerobuscastr[30];

    sprintf(numerobasestr, "%d", numerobase);
    sprintf(numerobuscastr, "%d", numerobusca);

    int tamanhonumbase = strlen(numerobasestr);
    int tamanhonumbusca = strlen(numerobuscastr);

    for (int i = 0; i <= tamanhonumbase - tamanhonumbusca; ++i) {
        int j;
        for (j = 0; j < tamanhonumbusca; ++j) {
            if (numerobasestr[i + j] != numerobuscastr[j]) {
                break;
            }
        }
        if (j == tamanhonumbusca) {
            contador += 1;
            i += tamanhonumbusca - 1;
        }
    }
    return contador;
}
