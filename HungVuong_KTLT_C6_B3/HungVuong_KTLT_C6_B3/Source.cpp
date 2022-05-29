#include <stdio.h>
#include <conio.h>
#include <windows.h>

void InputRC(int &row, int &column) {
	do {
		printf("Row: ");
		scanf_s("%d", &row);
		printf("Column: ");
		scanf_s("%d", &column);
	} while (row <= 2 || column <= 2 || row > 10 || column > 10);
}

void InputPosRC(int row, int column, int &posR, int &posC) {
	do {
		printf("Pos Row: ");
		scanf_s("%d", &posR);
		printf("Pos Column: ");
		scanf_s("%d", &posC);
	} while (posR < 0 || posC < 0 || posR >= row || posC >= column);
}

void InitBoard(int **&a, int row, int column) {
	a = new int *[row];
	for (int i = 0; i < row; i++) {
		a[i] = new int[column];
		for (int j = 0; j < column; j++) {
			a[i][j] = 0;
		}
	}
}

void OutputBoard(int **a, int row, int column) {
	printf("\t");
	for (int i = 0; i < column; i++) {
		printf("%d\t", i);
	}
	printf("\n\n");
	for (int i = 0; i < row; i++) {
		printf("%d\t", i);
		for (int j = 0; j < column; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void OutputPosAbove(int posR, int posC, int column) {
	int i, j;
	if (posR <= 0 || posR - 2 < 0)
		return;
	posR -= 2;
	i = posC + 1;
	if (i != column)
		printf("(%d, %d), ", posR, i);
	j = posC - 1;
	if (j != -1)
		printf("(%d, %d), ", posR, j);
}

void OutputPosBelow(int posR, int posC, int row, int column) {
	int i, j;
	if (posR >= row - 1 || posR + 2 >= row)
		return;
	posR += 2;
	i = posC + 1;
	if (i != column)
		printf("(%d, %d), ", posR, i);
	j = posC - 1;
	if (j != -1)
		printf("(%d, %d), ", posR, j);
}

void OutputPosRight(int posR, int posC, int column) {
	int i, j;
	if (posC >= column - 1 || posC + 2 >= column)
		return;
	posC += 2;
	i = posR + 1;
	if (i != column)
		printf("(%d, %d), ", i, posC);
	j = posR - 1;
	if (j != -1)
		printf("(%d, %d), ", j, posC);
}

void OutputPosLeft(int posR, int posC, int row) {
	int i, j;
	if (posC <= 0 || posC - 2 < 0)
		return;
	posC -= 2;
	i = posR + 1;
	if (i < row)
		printf("(%d, %d), ", i, posC);
	j = posR - 1;
	if (j != -1)
		printf("(%d, %d)", j, posC);
}

void IsPosHorse(int posR, int posC, int row, int column) {
	printf("\nPos Horse (%d, %d): ", posR, posC);
	OutputPosAbove(posR, posC, column);
	OutputPosBelow(posR, posC, row, column);
	OutputPosRight(posR, posC, column);
	OutputPosLeft(posR, posC, row);
}

void OutputResult(int **a, int row, int column) {
	int posR, posC;
	InputPosRC(row, column, posR, posC);
	system("cls");
	a[posR][posC] = 1;
	OutputBoard(a, row, column);
	IsPosHorse(posR, posC, row, column);
}

void main() {
	int **a;
	int row, column;
	InputRC(row, column);
	InitBoard(a, row, column);
	OutputBoard(a, row, column);
	OutputResult(a, row, column);
	_getch();
}