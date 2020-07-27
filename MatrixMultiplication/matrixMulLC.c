#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand((unsigned int)time(NULL));
    int size[25] = {
        1000, 2000, 3000, 4000, 5000, 6000,
        7000, 8000, 9000, 10000, 11000, 12000,
        13000, 14000, 15000, 16000, 17000, 18000,
        19000, 20000, 21000, 22000, 23000, 24000,
        25000
    };

    /*Criando Arquivo de Resultados*/
    FILE *fp;
    fp = fopen("cResultsLC.csv","w+");
    fprintf(fp,"tamanho;tempo(10^-3 s)\n");
    /*Loop de variacao de tamanho da matrix nxn*/
    for (int s = 0; s < sizeof(size)/sizeof(int); s++) {
        /*Criando Matrix A*/
        double **A = malloc(size[s] * sizeof(double *));
        for(int i = 0; i < size[s]; i++) {
            A[i] = malloc(size[s] * sizeof(double));
        }
        /*Criando Matrix x*/
        double *x = malloc(size[s] * sizeof(double));
        /*Criando Matrix b*/
        double *b = malloc(size[s] * sizeof(double));
        /*Zerando todos os elementos da matrix b*/
        for (int el = 0; el < size[s]; el++) {
            b[el] = 0;
        }
        /*Variaveis de Iteracao matricial*/
        int linha;
        int coluna;
        /*Populando Matrix A com double aleatorios enter 0 e 1*/
        for (linha = 0; linha < size[s]; linha++) {
            for (coluna = 0; coluna < size[s]; coluna++) {
                A[linha][coluna] = ((double)rand())/RAND_MAX;
            }
        }
        /*Populando vetor x com double aleatorios enter 0 e 1*/
        for (linha = 0; linha < size[s]; linha++) {
            x[linha] = ((double)rand())/RAND_MAX;
        }
        /*Operacao de multiplicacao matricial*/
        clock_t begin = clock();
        for (linha = 0; linha < size[s]; linha++) {
            for (coluna = 0; coluna < size[s]; coluna++) {
                b[linha] += A[linha][coluna]*x[coluna];
            }
        }
        clock_t end = clock();
        /*Termino da operacao de multiplicacao matricial*/
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(fp,"%i;%f\n", size[s], time_spent*1000);
        /*Liberando memoria alocada*/
        free(x);
        free(b);
        for(int i = 0; i < size[s]; i++) {
            free(A[i]);
        }
        free(A);
    }
    /*Fechando Arquivo aberto*/
    fclose(fp);

    return 0;
}