/**
 *  @file main.c
 *  @brief Programa para manipulacao de antenas e efeitos nefastos numa matriz 12x12.
 *
 *  @author DavidPinheiro
 *  @date 2025-03-30
 *  @project ProjetoEDA_25444_FASE1
 */
#include <stdio.h>
#include <stdlib.h>
#include "antena.h"

int main() {

    // Declaração de variáveis
    ListaLigada* lista = NULL;                         /* Ponteiro para a lista de antenas */
    ListaLigada* efeitosnefasto = NULL;                /* Ponteiro para a lista de efeitos nefastos */
    int opcao;                                         /* Opcao escolhida pelo utilizador no menu */
    int x, y;                                          /* Coordenadas da antena ou efeito */
    char frequencia;                                   /* Frequência da antena a ser adicionada */
    char matriz[12][12];                               /* Matriz que representa a cidade 12x12 */
    const char* nomeFicheiro = "antenas.txt";          /* Nome do ficheiro que contém as antenas */

    do {
        lista = CarregarFicheiro(nomeFicheiro);
        efeitosnefasto = EfeitoNefasto(lista);
        AtualizarFicheiro(lista, efeitosnefasto, nomeFicheiro);
        // Exibir o menu
        Menu(&opcao);

        switch (opcao) {
        case 1:  // Listar as antenas
            system("cls");

            // Ler o conteudo do ficheiro para a matriz
            LerFicheiroParaMatriz(nomeFicheiro, matriz); 

            // Listar as antenas e os efeitos nefastos
            ListarAntenas(matriz, lista);  
            break;

        case 2:  // Exibir o conteúdo do ficheiro
            // Visualizar o conteúdo do ficheiro
            Ficheiro(nomeFicheiro);
            break;

        case 3:  // Adicionar uma antena
            system("cls");

            /*
            printf("------ Adicionar uma Antena ------\n");

            printf("Frequencia da Antena (Caractere): ");
            scanf_s(" %c", &frequencia, 1);

            printf("Coordenada X: ");
            scanf_s("%d", &x);

            printf("Coordenada Y: ");
            scanf_s("%d", &y);

            validarCoordenadas(x, y);

           */

            // Inserir a antena na lista
            InserirAntena(lista, 'F', 0, 1);
            InserirAntena(lista, 'D', 11, 11);
            InserirAntena(lista, 'F', 2, 5);

            // Recalcular o efeito nefasto e atualizar o arquivo
            efeitosnefasto = EfeitoNefasto(lista);
            AtualizarFicheiro(lista, efeitosnefasto, nomeFicheiro);
            
            break;

        case 4:  // Remover uma antena
            system("cls");
            /*
             printf("------ Remover uma Antena ------\n");

             printf("Coordenada X (0-11): ");
             scanf_s("%d", &x);

             printf("Coordenada Y (0-11): ");
             scanf_s("%d", &y);

             validarCoordenadas(x, y);

             */

            // Remover a antena da lista
            if (RemoverAntena(lista, 11, 11)) {
                // Recalcular o efeito nefasto e atualizar o arquivo
                efeitosnefasto = EfeitoNefasto(lista);
                AtualizarFicheiro(lista, efeitosnefasto, nomeFicheiro);
            }
            else {
                return 0;
            }
            break;

        case 5:  
            // Libertar a memoria das listas 
            free(lista);
            free(efeitosnefasto);
            exit(0);  
            break;
        default:
            return 0;
            break;
        }

    } while (opcao != 5);

    // Liberar a memoria das listas 
    free(lista);
    free(efeitosnefasto);
    return 0;
}
