/**
* @file antena.h
* @brief  Definicao das estruturas e funcoes para manipulacao de antenas e efeitos nefastos.
* @author DavidPinheiro
*  @date 2025-03-30
*  @project ProjetoEDA_25444_FASE1
*/

#ifndef ANTENA_H
#define ANTENA_H

#include <stdio.h>
#include <stdlib.h>


 /**
  *  @struct Antena
  *  @brief Estrutura que representa uma antena.
  *
  *  Cada antena possui uma frequencia (caracter) e coordenadas (x, y).
  *  A estrutura e organizada como uma lista ligada.
  */
typedef struct Antena {
	char frequencia;		/* Frequencia da antena */
	int x;					/* Coordenada X da antena */
	int y;					/* Coordenada Y da antena */
	struct Antena* prox;	/* Apontador para a proxima antena na lista */
} Antena;

/**
  *	@struct ListaLigada
  *  @brief Estrutura que representa uma lista ligada de antenas.
  *
  *  Esta estrutura contem um apontador para o primeiro elemento da lista,
  *  permitindo o armazenamento e manipulacao dinamica de multiplas antenas.
  */
typedef struct ListaLigada {
    Antena* h;				/* Apontador para o primeiro elemento da lista */
} ListaLigada;



int Menu(int* opcao);

ListaLigada* CarregarFicheiro(const char* nome_ficheiro);
ListaLigada* EfeitoNefasto(ListaLigada* lista);
ListaLigada* CriarLista();
int AtualizarFicheiro(ListaLigada* lista, ListaLigada* efeitos, const char* nome_ficheiro);

int LerFicheiroParaMatriz(const char* nomeFicheiro, char matriz[12][12]);
int ListarAntenas(char matriz[12][12], ListaLigada* lista);

int Ficheiro(char* nomeFicheiro);

int InserirAntena(ListaLigada* lista, char frequencia, int x, int y);

int RemoverAntena(ListaLigada* lista, int x, int y);


#endif  // !ANTENA_H


