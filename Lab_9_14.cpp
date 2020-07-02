#include <stdio.h>
#include <locale.h>
#include <stdio.h>

int max_s(int** matr, int j, int razmer) {
	int max_stolb = matr[j][0];
	for (int i = 1; i < razmer; i++) {
		if (matr[j][i] > max_stolb) {
			max_stolb = matr[j][i];
		}
	}
	return max_stolb;
}

void obmen_stolbov(int** matr, int stolb1, int stolb2) {
	int* p = matr[stolb1];
	matr[stolb1] = matr[stolb2];
	matr[stolb2] = p;
}

void sort_s(int** matr, int razmer) {
	bool est_obmen;

	do 	{
		est_obmen = false;
		for (int j = 1; j < razmer; j++) {
			if (max_s(matr, j - 1, razmer) < max_s(matr, j, razmer))
			{
				obmen_stolbov(matr, j - 1, j);
				est_obmen = true;
			}
		}
	} while (est_obmen);
}

void vivod_matr(int** matr, int razmer) {
	for (int i = 0; i < razmer; i++) {
		for (int j = 0; j < razmer; j++) {
			printf("%d\t", matr[j][i]);
		}
		printf("\n");
	}
}


int main() {
	char *locale = setlocale(LC_ALL,"Russian");
	printf("Введите n - размерность матрицы a[n][n]: ");
	int n;
	scanf("%d", &n);
	int** a, i, j;
	a = new int* [n];
	for (j = 0; j < n; j++) {
		a[j] = new int[n];
		printf("Введите %d чисел для столбца %d:\n", n, j);
		for (i = 0; i < n; i++) {
			scanf("%d", &a[j][i]);
		};
	};
	printf("Исходная матрица a[%d][%d]:\n", n, n);
	vivod_matr(a, n);
	sort_s(a, n);
	printf("Матрица a[%d][%d] после сортировки столбцов по убыванию их наибольших элементов:\n", n, n);
	vivod_matr(a, n);
	delete[]a;
	return 0;
}
