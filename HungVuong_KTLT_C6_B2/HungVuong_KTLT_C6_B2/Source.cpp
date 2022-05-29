#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int Random(int min, int max){
	return min + rand() % (max + 1 - min);
}

void InputRC(int &row, int &column) {
	do {
		printf("Row: ");
		scanf_s("%d", &row);
		printf("Column: ");
		scanf_s("%d", &column);
	} while (row > 10 || row <= 2 || column > 10 || column <= 2);
}

void Input(int **&a, int row, int column) {
	a = new int *[row];
	for (int i = 0; i < row; i++) {
		a[i] = new int[row];
		for (int j = 0; j < column; j++) {
			printf("a[%d][%d]= ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}

void InputRand(int **&p, int row, int column) {
	srand((int)time(0));
	p = new int *[row];
	for (int i = 0; i < row; i++) {
		p[i] = new int[row];
		for (int j = 0; j < column; j++) {
			p[i][j] = Random(1, 100);
		}
	}
}

void Output(int **&a, int row, int column) {
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < column; j++) {
			printf("%d\t", a[i][j]);
		}
	}
}

int IsCheckRow(int **a, int posR, int posC, int row) {
	for (int i = 0; i < row; i++) {
		if (a[i][posC] >= a[posR][posC] && a[i][posC] != a[posR][posC])
			return 0;
	}
	return 1;
}

int IsCheckColumn(int **a, int posR, int posC, int column) {
	for (int i = 0; i < column; i++) {
		if (a[posR][i] >= a[posR][posC] && a[posR][i] != a[posR][posC])
			return 0;
	}
	return 1;
}

int IsCheckFirstDiagonal(int **a, int posR, int posC, int row, int column) {
	for (int i = posR - 1, j = posC - 1; i != -1 && j != -1; i--, j--) {
		if (a[i][j] >= a[posR][posC])
			return 0;
	}
	for (int i = posR + 1, j = posC + 1; i != row && j != column; i++, j++) {
		if (a[i][j] >= a[posR][posC])
			return 0;
	}
	return 1;
}

int IsCheckSecondDiagonal(int **a, int posR, int posC, int row, int column) {
	for (int i = posR - 1, j = posC + 1; i != -1 && j != column; i--, j++) {
		if (a[i][j] >= a[posR][posC])
			return 0;
	}
	for (int i = posR + 1, j = posC - 1; i != row && i != -1; i++, j--) {
		if (a[i][j] >= a[posR][posC])
			return 0;
	}
	return 1;
}

int IsCheckQueen(int **a, int posR, int posC, int row, int column) {
	if (!IsCheckRow(a, posR, posC, row))
		return 0;
	if (!IsCheckColumn(a, posR, posC, column))
		return 0;
	if (!IsCheckFirstDiagonal(a, posR, posC, row, column))
		return 0;
	if (!IsCheckSecondDiagonal(a, posR, posC, row, column))
		return 0;
	return 1;
}

void IsQueen(int **a, int row, int column) {
	printf("\n\nList Queen: ");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (IsCheckQueen(a, i, j, row, column))
				printf("%d[%d][%d]\t", a[i][j], i, j);
		}
	}
}

void main() {
	int **a;
	int row, column;
	InputRC(row, column);
	//InputRand(a, row, column);
	Input(a, row, column);
	Output(a, row, column);
	IsQueen(a, row, column);
	_getch();
}