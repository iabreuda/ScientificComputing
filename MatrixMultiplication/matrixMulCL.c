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
    fp = fopen("cResultsCL.csv","w+");
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
        /*Variaveis de Iteracao matricial*/
        int linha;
        int coluna;
        /*Populando Matrix A e vetor x com double aleatorios enter 0 e 1*/
        for (linha = 0; linha < size[s]; linha++) {
            x[linha] = ((double)rand())/RAND_MAX;
            /*Zerando elementos do vetor de resultados*/
            b[linha] = 0;
            for (coluna = 0; coluna < size[s]; coluna++) {
                A[linha][coluna] = ((double)rand())/RAND_MAX;
            }
        }
        /*Operacao de multiplicacao matricial*/
        clock_t begin = clock();
        for (coluna = 0; coluna < size[s]; coluna++) {
            for (linha = 0; linha < size[s]; linha++) {
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