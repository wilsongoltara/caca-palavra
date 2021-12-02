#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{ 
    int i, j, t, n, m;
    int encontrada; // 1 = SIM. 0 = NÃO
    
    char cacaPalavra[25][25], palavra[25][25];

    scanf("%d %d", &n, &m); //ler dimensão da matriz.
    
    //Ler elementos da matriz.
    for (i = 0; i < n; i++)
    {
        scanf("%s", cacaPalavra[i]);
    }

    //Armazena as palavras que serão buscadas na matriz.
    for (i = 0; i < n; i++)
    {
        scanf("%s", palavra[i]); 
    }
    printf("\n-- RESULTADO --\n");

    //Para cada palavra.
    for (int k = 0; k < n; k++) 
    {
        encontrada = 0;
        //Verifica cada linha do caça palavras.
        for (i = 0; i < n; i++) 
        {
            //Verifica cada coluna do caça palavras.
            for (j = 0; j < m; j++)
            {
                //Se a primeira letra for encontrada.
                if (palavra[k][0] == cacaPalavra[i][j]) 
                {   
                    //Se a segunda letra for encontrada ao Norte.
                    if (palavra[k][1] == cacaPalavra[i - 1][j]) 
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != cacaPalavra[i - t][j])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    //Se a segunda letra for encontrada ao Nordeste.
                    if (palavra[k][1] == cacaPalavra[i - 1][j + 1]) 
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != cacaPalavra[i - t][j + t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    //Se a segunda letra for encontrada ao Leste.
                    if (palavra[k][1] == cacaPalavra[i][j + 1]) 
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != cacaPalavra[i][j + t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    //Se a segunda letra for encontrada ao Sudeste.
                    if (palavra[k][1] == cacaPalavra[i + 1][j + 1]) 
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != cacaPalavra[i + t][j + t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }
                    //Se a segunda letra for encontrada ao Sul.
                    if (palavra[k][1] == cacaPalavra[i + 1][j]) 
                    {
                        encontrada = 1;
                        
                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != cacaPalavra[i + t][j])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    } 

                    //Se a segunda letra for encontrada ao Sudoeste.
                    if (palavra[k][1] == cacaPalavra[i + 1][j - 1]) 
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != cacaPalavra[i + t][j - t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    //Se a segunda letra for encontrada ao Oeste.
                    if (palavra[k][1] == cacaPalavra[i][j - 1]) 
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != cacaPalavra[i][j - t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    } 
                    
                    //Se a segunda letra for encontrada ao Noroeste. 
                    if (palavra[k][1] == cacaPalavra[i - 1][j - 1])
                    {
                        encontrada = 1;
    
                            for (t = 0; t < strlen(palavra[k]); t++)
                                if (palavra[k][t] != cacaPalavra[i - t][j - t])
                                    encontrada = 0;
    
                            if (encontrada)
                                break;
                    }
                }
            }
            if(encontrada)
                break;
        }
        if (encontrada)
                printf("%s - PALAVRA ENCONTRADA\n", palavra[k]);
            else
                printf("%s - PALAVRA NAO ENCONTRADA\n", palavra[k]);
    }                 
}