#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    int main() {
        int podeColocarDireita = 1;
        int podeColocarHorizontal = 1;
        int podeColocarEsquerda = 1;
        printf("     ");
        printf("TABULEIRO NAVAL");

        printf("\n");
        printf("\n");

        char linha[] = {'A','B','C','D','E','F','G','H','I','J'};//vetor de linhas para ficar em cima do tabuleiro

        int tabuleiro[10][10] = {0};//matriz da tabela


        //navios
        int navioV[3] = {3,3,3};
        int navioH[3] = {3,3,3};
        int navioDiagonalDireita[3] = {3,3,3};
        int navioDiagonalEsquerda[3] ={3,3,3};

        //posições dos navios
        int linhaVertical = 3;
        int colunaVertical = 6;
        

        int linhaHorizontal = 4;
        int colunaHorizontal = 2;

        int linhaDiagonalDireita = 4;
        int colunaDiagonalDireita = 7;

        int linhaDiagonalEsquerda = 0;
        int colunaDiagonalEsquerda = 4;



        
        //movimentação vertical
        if(linhaVertical + 3 <= 10){
            for(int i = 0 ; i < 3;i++){
                tabuleiro[linhaVertical + i][colunaVertical] = navioV[i];
            }
        }
        //verificação horizontal
                for(int i = 0; i < 3 ; i++){
            
            int l = linhaHorizontal;
            int c = colunaHorizontal + i;

            if(tabuleiro[l][c] != 0){
                podeColocarHorizontal = 0;
                break;
            }
        }        
         //movimentação horizontal
        if(podeColocarHorizontal && colunaHorizontal + 3 <= 10){
            for(int i = 0 ; i < 3;i++){
                tabuleiro[linhaHorizontal ][colunaHorizontal + i] = navioH[i];
            }
        }else{
            printf("erro de sobreposição na horizontal\n");
            return 0;
        }
        //verficação diagonal baixo direita
        for(int i = 0; i < 3 ; i++){
            
            int l = linhaDiagonalDireita + i;
            int c = colunaDiagonalDireita + i;

            if(tabuleiro[l][c] != 0){
                podeColocarDireita = 0;
                break;
            }
        }

        //movimentação diagonal baixo direita
        if (podeColocarDireita && linhaDiagonalDireita + 3 <= 10 && colunaDiagonalDireita + 3 <= 10){
            for(int i = 0; i < 3; i++){
                tabuleiro[linhaDiagonalDireita + i][colunaDiagonalDireita + i] = navioDiagonalDireita[i];
            }
        }else{
            printf("erro de sobreposição na diagonal direita\n");
            return 0;
        }
          //verficação diagonal baixo esquerda
        for(int i = 0; i < 3 ; i++){
            
            int l = linhaDiagonalEsquerda + i;
            int c = colunaDiagonalEsquerda - i;

            if(tabuleiro[l][c] != 0){
                podeColocarEsquerda = 0;
                break;
            }
        }

        //movimentação diagonal baixo direita
        if (podeColocarEsquerda&&linhaDiagonalEsquerda + 3 <= 10 && colunaDiagonalEsquerda + 3 <= 10){
            for(int i = 0; i < 3; i++){
                tabuleiro[linhaDiagonalEsquerda + i][colunaDiagonalEsquerda - i] = navioDiagonalEsquerda[i];
            }
        }else{
            printf("erro de sobreposição na diagonal esquerda\n");
            return 0;
        }

         //habilidades
         
        //cone
        int cone [3][5] = {0};
        int centro = 2;
        int linhaCone = 0;
        int colunaCone = 5;

        for(int  i = 0; i < 3 ; i++){
            for(int j = centro - i ; j <= centro + i ; j++){
                cone[i][j] = 1;
            }
        }

        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 5 ; j++){
                if(cone[i][j] == 1){
                tabuleiro[linhaCone + i][colunaCone + (j - centro)] = 1; 
                }
            }
        }
        //cruz
        int cruz [3][5] = {0};
        int linhaCruz = 6;
        int colunaCruz = 5;

        for (int i = 0; i < 3; i++){
            for(int j = 0 ; j < 5 ; j++){
                if(i == 1 || j == 2){
                    cruz[i][j] = 1;
                }
            }
        }
            for(int i = 0 ; i < 3 ; i++){
             for(int j = 0 ; j < 5 ; j++){
                if(cruz[i][j] == 1){
                tabuleiro[linhaCruz + i][colunaCruz + (j - centro)] = 1; 
                }
            }
        }

        //octaedro
        int octaedro [3][5] = {0};
        int linhaOctaedro = 4;
        int colunaOctaedro = 3;
         for (int i = 0; i < 3; i++){
            for(int j = 0 ; j < 5 ; j++){
                if(abs(i - 1)+ abs(j - 2) <= 1){
                    octaedro[i][j] = 1;
                }
            }
        }
          for(int i = 0 ; i < 3 ; i++){
             for(int j = 0 ; j < 5 ; j++){
                if(octaedro[i][j] == 1){
                tabuleiro[linhaOctaedro + i][colunaOctaedro + (j - centro)] = 1; 
                }
            }
        }
    
        



        printf("   ");//identação pra ficar alinhado

        for (int i = 0; i < 10; i++){//loop linhas em cima do tabuleiro

            printf("%c ", linha[i]);//linha de letras do tabuleiro
        }
        
        printf("\n");
        
        for(int i = 0; i < 10; i++){//loop linhas da tabela
            printf("%d  ",i);//números do lado do tabuleiro

            for(int j = 0; j <10; j++)//loop colunas da tabela
            {
                printf("%d ",tabuleiro[i][j]);//zeros do tabuleiro
            }
            printf("\n");
        }
     

    return 0;
}
