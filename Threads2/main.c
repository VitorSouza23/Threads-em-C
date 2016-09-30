#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
#include <time.h>

#define NTHREADS 2
#define TAMVET 1000

int vet[TAMVET];

void preencherVetor(void *parametro);

int main()

{
    int part1 = 1, part2 = 2, indice;

    _beginthread(preencherVetor,0,&part1);
    _beginthread(preencherVetor,0,&part2);

    for(indice = 0; indice < TAMVET; indice++){
        printf("\nPosição no vetor: %d - Valor: %d\n",indice + 1, vet[indice]);
    }
    return 0;
}

void preencherVetor(void *parametro)
{
    int nthread = (int) *(int*) parametro;
    int indice;

    if(nthread == 1)
        {
            for(indice = 0; indice < 500; indice++)
                {
                    vet[indice] = rand() % 1000;
                }
        }else if(nthread == 2)
        {
            for(indice = 500; indice < TAMVET; indice++)
                {
                    vet[indice] = rand() % 1000;
                }
        }

        Sleep(20);
}
