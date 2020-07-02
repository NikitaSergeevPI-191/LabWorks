#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 5

int vvod(int A[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("A[%d][%d]= ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
	return 0;
}

int full(int A[][N])
{
	int i, j;
	FILE* f;
	f = fopen("rrrr.txt", "r");
	if (f != NULL)
	{
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				fscanf(f, "%d", &A[i][j]);
	}
	else printf("Ошибка открытия файла");
	fclose(f);
	return 0;
}

int decision(int A[][5], int n, int a, int b)
{
	int j, i, m, l, X[N], min[N], x;
	for (m = 0; m < N; m++)
	{
		for (i = 0; i < (N - 1); i++)
		{
			for (l = i + 1; l < N; l++)
			{
				if (A[m][i] > A[m][l])
				{
					x = A[m][l];
					A[m][l] = A[m][i];
					A[m][i] = x;
				}
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("A[%d][%d]= ", i, j);
			printf("%d \n", A[i][j]);
		}
	}
	return 0;
}

int recursion(int Y,int i, int X[])
{
    if(i == 0 )
    {
        return Y;
    }
    else
    {
        if(X[i-1] > 0)
        {
            Y=i-1;
            return Y;
        }
        else
        {
            return recursion(Y,i - 1, X);
        }
    }

}

int output(int A[][N], int X[])
{
	FILE* f;
	int Y =0;
	system("cls");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("A[%d][%d]=%d ", i, j, A[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < N; i++)
		printf("\nx[%d]=%d", i, X[i]);

	printf("\ny=%d", recursion(Y,N, X));
	f = fopen("wwww.txt", "w");
	if (f != NULL)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				fprintf(f, "A[%d][%d]=%d ", i, j, A[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < N; i++)
			fprintf(f, "\nx[%d]=%d", i, X[i]);

		fprintf(f, "\ny=%d", recursion(Y,N, X));
	}
	else
		printf("Ошибка открытия файла");

    return 0;
}

int *MainCalculation(int A[][5],int a,int b,int (*yka)(int[][N] ),int X[])
{
    (*yka)(A);
    decision(A, N, a, b);
    for (int i = 0; i < N; i++)
	{
		if (A[i][0] >= 0) X[i] = 1;
		else X[i] = -1;
	}
	int *P =X;
    return P;
}

int main()
{
	char* locale = setlocale(LC_ALL, "");
	int A[N][N], X[N], a = 0, b = 0, k = 0;
	int (*yka)(int[][N]) = NULL; // yka указывает на функцию
	printf("Укажите какой ввод матрицы нужен: Если с клавиатуры то введите 1, если с файла, то 0\n");
	scanf("%d", &k);
	if (k == 1)
		yka = vvod;
	else
		yka = full;
	/*yka(A, N);
	decision(A, N, a, b);*/
	int *Xpointer;
	Xpointer = MainCalculation(A,a,b,yka, X);

	for (int i = 0; i < N; i++)
	{
		printf("X[%d]= ", i);
		printf("%d \n", X[i]);
	}
	//printf("\nY=%d", Y);
	output(A, Xpointer);
}
