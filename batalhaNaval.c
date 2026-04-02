#include <stdio.h>

/*Desafio Batalha Naval
Nível Mestre
Tema 5 - Habilidades especiais e áreas de efeito.
Objetivo: Implementando habilidades especiais com áreas de efeito distintas: cone, cruz e octaedro.
Aluno: Fábio Oliveira Nunes Matrícula: 202601102478*/

// Obs: 0 (~) representa água, 3 (N) representa uma parte do navio e 5 X) a área de ataque.

#define LINHAS 10 // Definindo o número de linhas do tabuleiro
#define COLUNAS 10 // Definindo o número de colunas do tabuleiro

int main () {

    char colunas[COLUNAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Vetor para representar as letras das colunas

    int tabuleiro[LINHAS][COLUNAS] = { // Matriz 10x10 para representar o tabuleiro sem navios
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
    
    //posicionando o terceiro navio na diagonal (de A5 a C7 - A5, B6, C7):
    if (tabuleiro[4][0] == 0 && tabuleiro[5][1] == 0 && tabuleiro[6][2] == 0) {
        tabuleiro[4][0] = 3;
        tabuleiro[5][1] = 3;
        tabuleiro[6][2] = 3;
    } else {
        printf("Aviso: Não foi possível posicionar o navio. Sobreposição detectada entre A5 e C7!\n");
    }

    //posicionando o quarto navio na diagonal (de C10 a E8 - C10, D9, E8):
    if (tabuleiro[9][2] == 0 && tabuleiro[8][3] == 0 && tabuleiro[7][4] == 0) {
        tabuleiro[9][2] = 3;
        tabuleiro[8][3] = 3;
        tabuleiro[7][4] = 3;
    } else {
        printf("Aviso: Não foi possível posicionar o navio. Sobreposição detectada entre C10 e E8!\n");
    }
    
    //implementando área de ataque das habilidades especiais (cone, cruz e octaedro) usando matrizes para representar as áreas de efeito:
    // 5 sobrepõe a água (0) e o navio (3) para indicar onde a habilidade atinge.

    // área de ataque do cone no tabuleiro (exemplo: ataque em H1, que atinge H1, G2, H2, I2, F3, G3, H3, I3, J3):
    
    int linha_ataque = 0; // 1ª linha
    int col_ataque = 7; // coluna H
    
    // Aplica o cone de 3 linhas de altura
    
    for (int i = 0; i < 3; i++) {
        for (int j = col_ataque - i; j <= col_ataque + i; j++) {
        
            // Verificação de segurança: garante que o ataque não saia do tabuleiro (0-9)

            if (j >= 0 && j < 10 && (linha_ataque + i) < 10) {
            tabuleiro[linha_ataque + i][j] = 5;
            }
        }
    }   

    // área de ataque da cruz no tabuleiro (exemplo: ataque em E5)
    
    linha_ataque = 4; // 5ª linha (índice 4)
    col_ataque = 4;   // coluna E (índice 4)

    // --- Parte VERTICAL (3 espaços: de -1 a +1) ---
        for (int i = -1; i <= 1; i++) {
            if (linha_ataque + i >= 0 && linha_ataque + i < 10) {
            tabuleiro[linha_ataque + i][col_ataque] = 5;
        }
    }

    // --- Parte HORIZONTAL (5 espaços: de -2 a +2) ---
    for (int j = -2; j <= 2; j++) {
        if (col_ataque + j >= 0 && col_ataque + j < 10) {
            tabuleiro[linha_ataque][col_ataque + j] = 5;
        }
    }
    
    
    // área de ataque do octaedro no tabuleiro (exemplo: ataque em B2, que atinge B2, A2, C2, B1, B3):
    
    linha_ataque = 1; // 2ª linha (índice 1)
    col_ataque = 1;   // coluna B (índice 1)
    
    // O octaedro atinge o centro (B2) e os 4 pontos adjacentes (A2, C2, B1, B3)

    // 1. Marca a linha vertical (3 espaços)
    for (int i = -1; i <= 1; i++) {
        
        int r = linha_ataque + i;
        
        if (r >= 0 && r < 10) {
            tabuleiro[r][col_ataque] = 5;
        }
    }

    // 2. Marca a linha horizontal (3 espaços)
    for (int j = -1; j <= 1; j++) {
        
        int c = col_ataque + j;
        
        if (c >= 0 && c < 10) {
            tabuleiro[linha_ataque][c] = 5;
        }
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
            } else if(tabuleiro[i][j] == 5) {
            printf("X "); // X representa uma parte do navio atingida pela habilidade
            } else {
            printf("~ "); // ~ representa água
            }
        }
        printf("|\n");
    }
    printf("   +---------------------+\n"); // linha da borda inferior do tabuleiro
    printf("\n");

    // Criar Matrizes de Habilidade:

    int cone[3][5], cruz[3][5], octaedro[3][5];
    int centro = 2; // Índice central para as formas

    //Explicação da área de ataque das habilidades:
    printf("Demonstração das áreas de ataque:\n\n");

    // Habilidade CONE
    printf("Habilidade CONE:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1; // Parte do cone
            } else {
                cone[i][j] = 0; // Área sem efeito
            }
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    // Habilidade CRUZ
    printf("\nHabilidade CRUZ:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            // Linha do meio (i == 1) OU Coluna do meio (j == centro)
            if (i == 1 || j == centro) {
                cruz[i][j] = 1; // Parte da cruz
            } else {
                cruz[i][j] = 0;
            }
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    // Habilidade OCTAEDRO
    printf("\nHabilidade OCTAEDRO:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            // No octaedro 3x5, a linha 0 e 2 só tem o centro. A linha 1 tem 3 elementos.
            if ((i == 0 && j == centro) || 
                (i == 1 && j >= centro - 1 && j <= centro + 1) || 
                (i == 2 && j == centro)) {
                octaedro[i][j] = 1; // Parte do octaedro
            } else {
                octaedro[i][j] = 0;
            }
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}