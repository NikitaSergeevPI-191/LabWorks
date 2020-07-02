#include<stdio.h>
#include <locale.h>
#include <stdlib.h>
#define FILE_DANNIE "D:\\dannie.txt"
#define FILE_REZULTAT "D:\\rezultat.txt"
#define N 5

int vvod(int a[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("A[%d][%d]= ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	return 0;
}
void full(int a[N][N])
{
	FILE* file;
	if (fopen_s(&file, FILE_DANNIE, "r") == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fscanf(file, "%d", &a[i][j]);
			}
		};
		fclose(file);
	} else {
		printf("Ошибка при открытии %s\n", FILE_DANNIE);
		exit(-1);
	}
}
int* zapolnit_a_x(int(*a)[N], int* x, void (*funk_vvoda)(int[N][N]))
{
	funk_vvoda(a);
	int summa;
	for (int i= 0; i < N; i++) {
		if (a[i][0] == 0) {
			summa = 0;
		}
		else {
			summa = a[i][0];
		}
		if (summa != 0) {
			for (int j = 1; j < N; j++) {
				if (((summa < 0) && (a[i][j] < 0)) || ((summa > 0) && (a[i][j] > 0))) {
					summa = summa + a[i][j];
				}
				else {
					summa = 0;
					break;
				}
			}
		}
		x[i] = summa;
	};
	return x;
}

int rekurs_najti_y(const int massiv[N], bool nado_summu, int indeks)
{
	if (indeks == (N - 1)) {
		if (nado_summu) {
			return massiv[indeks];
		}	else {
			return 0;
		}
	};

	if (!nado_summu) {
		if (massiv[indeks] == 0) {
			return rekurs_najti_y(massiv, true, indeks + 1);
		}	else {
			return rekurs_najti_y(massiv, false, indeks + 1);
		}
	}
	else {
		return massiv[indeks] + rekurs_najti_y(massiv, true, indeks + 1);
	};
}

void vivod(const int a[N][N], const int x[N], int y) {
	printf("Матрица a[%d][%d]:\n", N, N);
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			printf("%d\t", a[row][col]);
		};
		printf("\n");
	};

	printf("Массив значений x[%d]:\n", N);
	for (int row = 0; row < N; row++) {
		printf("%d\t", x[row]);
	};
	printf("\n");

	printf("Значение y = %d (сумма эл-тов массива x, после 1го нулевого эл-та).\n", y);

	FILE* file;
	if (fopen_s(&file, FILE_REZULTAT, "w") == 0) {
		fprintf(file, "Матрица a[%d][%d]:\n", N, N);
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				fprintf(file, "%d\t", a[row][col]);
			};
			fprintf(file, "\n");
		};

		fprintf(file, "Массив значений x[%d]:\n", N);
		for (int row = 0; row < N; row++) {
			fprintf(file, "%d\t", x[row]);
		};
		fprintf(file, "\n");

		fprintf(file, "Значение y = %d (сумма эл-тов массива x, после 1го нулевого эл-та).\n", y);
		fclose(file);
	}	else {
		printf("Ошибка при открытии %s", FILE_REZULTAT);
	};
}

int main()
{
	setlocale(LC_CTYPE, "");
	int a[N][N];
	int x[N];
	int vibor;
	void (*funkcia_vvoda)(int[N][N]);
	printf("Ввод матрицы:\n1 - с клавиатуры\n2 - из фалйа %s\nВаш выбор: ", FILE_DANNIE);
	do {
		scanf("%d", &vibor);
	} while ((vibor != 1) && (vibor != 2));
	funkcia_vvoda = vibor == 1 ? vvod : full;
	zapolnit_a_x(a, x, funkcia_vvoda);
	vivod(a, x, rekurs_najti_y(x, false, 0));
	return 0;
}
