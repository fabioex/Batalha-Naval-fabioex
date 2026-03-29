#include <stdio.h>

/*Desafio Batalha Naval
Nível Novato: .
Tema 4 - posicionamento de navios em um tabuleiro 10x10 usando matriz bidimensional.
Objetivo: Criar um tabuleiro de batalha naval posicionando seus navios.
Aluno: Fábio Oliveira Nunes Matrícula: 202601102478*/

// Obs: 0 representa água e 3 representa uma parte do navio.

int main () {

    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Vetor para representar as letras das colunas

    int tabuleiro[10][10] = { // Matriz 10x10 para representar o tabuleiro sem navios
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };


    // Posicionando o primeiro navio na horizontal (linha 3, colunas de 3 a 5 - D3, E3, F3):
    if (tabuleiro[2][3] == 0 && tabuleiro[2][4] == 0 && tabuleiro[2][5] == 0) { // Se estiver vazio (água)
        tabuleiro[2][3] = 3;    // Pode colocar o navio
        tabuleiro[2][4] = 3;
        tabuleiro[2][5] = 3;
    } else {
        printf("Aviso: Não foi possível posicionar o navio. Sobreposição detectada entre D3 e F3!\n");
    }

    // posicionando o segundo navio na vertical (coluna 7, linhas de 5 a 7 - H6, H7, H8):
    if (tabuleiro[5][7] == 0 && tabuleiro[6][7] == 0 && tabuleiro[7][7] == 0) {
        tabuleiro[5][7] = 3;
        tabuleiro[6][7] = 3;
        tabuleiro[7][7] = 3;
    } else {
        printf("Aviso: Não foi possível posicionar o navio. Sobreposição detectada entre H6 e H8!\n");
    }
    

    printf("Tabuleiro de Batalha Naval:\n");
    
    // Imprimindo as letras do vetor das colunas (linha 11)
    printf("     "); // Espaço para alinhar as letras do vetor das colunas
    for (int j = 0; j < 10; j++) { 
        printf("%c ", colunas[j]);
    }
    printf("\n"); // pula para a próxima linha após imprimir as letras das colunas

    printf("   +---------------------+\n"); // linha de separação do índice das colunas
    
    for (int i = 0; i < 10; i++) {
        
        printf("%2d | ", i + 1); // impressão do índice das linhas
        
        for (int j = 0; j < 10; j++) {
        //conversão estética para mostrar os navios (N) e a água (~) no tabuleiro:
            if(tabuleiro[i][j] == 3) {
            printf("N "); // N representa uma parte do navio
            } else {
            printf("~ "); // ~ representa água
    }
        }
        printf("|\n");
    }
    printf("   +---------------------+\n"); // linha da borda inferior do tabuleiro
    printf("\n");


    return 0;
}