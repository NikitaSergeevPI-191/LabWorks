#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>

int **MassInput(int N)
{
    int **a = NULL;
    a = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i<N; i++)
        {
            a[i]=(int*)malloc(N * sizeof(int));
            for (int j = 0; j<N; j++)
            {
                printf("a[%d][%d] = ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
        //int **a = a;
        return a;
}
int CalculationAndOtputResults(int N, int **a)
{
     bool AllLeftSmaller = false;
    bool AllRightBigger = false;
    bool NoNumbersInRow = false;
    int c[2][N];
    for(int i =0;i<N;i++)
    {
        NoNumbersInRow = true;
        for(int j=0;j<N;j++)
        {
            if(j>0&&j<N-1)
            {
                int Z = a[i][j];
                for(int k =0;k<N;k++)
                {
                    int ZZ = a[i][k];
                    if(k<j)
                    {
                        if(Z>ZZ)
                        {
                            AllLeftSmaller = true;
                        }
                        else
                        {
                            AllLeftSmaller = false;
                        }
                        //AllLeftSmaller = false;
					//записать в массив X Matrix[i][j]
					//printf(" строчке есть это число=");
                    //printf("%d", X);

                    }
                    else if(k>j)
                    {
                        if(Z<ZZ)
                        {
                            AllRightBigger = true;
                        }
                        else
                        {
                            AllRightBigger = false;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                if(AllLeftSmaller&&AllRightBigger)
                {
                    /*printf("В %d",i);
                    printf(" строчке есть это число=");
                    printf("%d\n", Z);*/
                    c[0][j] = -1;
                    c[1][j] = Z;
                    NoNumbersInRow = false;
                }
                else
                {
                    /*printf("В %d",i);
                    printf(" строчке нет этого числа.\n");*/
                    c[0][j] = 0;
                    c[1][j] = Z;
                    //continue;
                }
            }

        }
        if(NoNumbersInRow)
            {
                printf("В %d",i);
                printf(" строчке нет этого числа.\n");
            }
            else
            {
                printf("В %d",i);
                    printf(" строчке есть эти числа/число : ");

                for(int i=0;i<N;i++)
                {

                    if(c[0][i] == -1)
                    {
                        printf("%d  ", c[1][i]);
                    }
                    else
                    {

                        continue;
                    }

                }
                printf("\n");
            }
    }
    return 0;
}
int OutputOfMassive(int N, int **a)
{
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int main()
{
    char* locale = setlocale(LC_ALL, "");

    //int **a = NULL;
    //int **c = NULL;
    //int b[2] = {0,0};
    int N;

    printf("Введите количество строк и столбцов");
    scanf("%d", &N);
    int **InputedMass;
    InputedMass = MassInput(N);
    //c = (int**)malloc(N*sizeof(b));

    CalculationAndOtputResults(N,InputedMass);
    OutputOfMassive(N,InputedMass);




    free(InputedMass);
    getchar();
    return 0;
}
