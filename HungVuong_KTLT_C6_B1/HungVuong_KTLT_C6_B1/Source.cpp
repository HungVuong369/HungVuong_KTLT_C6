#include <time.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int Random(int min, int max) {
	return min + rand() % (max + 1 - min);
}

void InputRC(int &rowAndColumn) {
	do {
		printf("Row and Column: ");
		scanf_s("%d", &rowAndColumn);
	} while (rowAndColumn < 0 && rowAndColumn > 10);
}

void Formula(int rowAndColumn, int &result) { // Công thức
	result = rowAndColumn * (pow(rowAndColumn * 1.0, 2) + 1) / 2;
}

void Input(int **&a, int rowAndColumn) {
	a = new int *[rowAndColumn];
	for (int i = 0; i < rowAndColumn; i++) {
		a[i] = new int[rowAndColumn];
		for (int j = 0; j < rowAndColumn; j++) {
			printf("a[%d][%d]= ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		printf("\n");
	}
}

void InputRand(int **&a, int rowAndColumn) {
	srand((int)time(0));
	a = new int *[rowAndColumn];
	for (int i = 0; i < rowAndColumn; i++) {
		a[i] = new int[rowAndColumn];
		for (int j = 0; j < rowAndColumn; j++) {
			a[i][j] = Random(0, 10);
		}
	}
	printf("\n");
}

void Output(int **a, int rowAndColumn) {
	for (int i = 0; i < rowAndColumn * rowAndColumn; i++) {
		printf("%d\t", a[i / rowAndColumn][i % rowAndColumn]);
		if (i % rowAndColumn == rowAndColumn - 1)
			printf("\n");
	}
	printf("\n");
}

int StopCondition(int &check, int result) {
	return check != result ? 1 : check = 0;
}

int IsCheckColumn(int **a, int rowAndColumn, int result) {
	int check = 0;
	for (int i = 0; i < rowAndColumn; i++) {
		for (int j = 0; j < rowAndColumn; j++) {
			check += a[i][j];
		}
		if (StopCondition(check, result))
			return 0;
	}
	return 1;
}

int IsCheckRow(int **a, int rowAndColumn, int result) {
	int check = 0;
	for (int i = 0; i < rowAndColumn; i++) {
		for (int j = 0; j < rowAndColumn; j++) {
			check += a[j][i];
		}
		if (StopCondition(check, result))
			return 0;
	}
	return 1;
}

int IsCheckFirstDiagonal(int **a, int rowAndColumn, int result) {
	int check = 0;
	for (int i = 0; i < rowAndColumn; i++) {
		check += a[i][i];
	}
	if (StopCondition(check, result))
		return 0;
	return 1;
}

int IsCheckSecondDiagonal(int **a, int rowAndColumn, int result) {
	int check = 0;
	for (int i = rowAndColumn - 1, j = 0; i >= 0; i--, j++) {
		check += a[j][i];
	}
	if (StopCondition(check, result))
		return 0;
	return 1;
}

int IsCheckMagicSquares(int **a, int rowAndColumn, int result) {
	if (!IsCheckRow(a, rowAndColumn, result))
		return 0;
	if (!IsCheckColumn(a, rowAndColumn, result))
		return 0;
	if (!IsCheckFirstDiagonal(a, rowAndColumn, result))
		return 0;
	if (!IsCheckSecondDiagonal(a, rowAndColumn, result))
		return 0;
	return 1;
}

void IsMagicSquares(int **a, int rowAndColumn, int result) {
	system("cls");
	Output(a, rowAndColumn);
	if (IsCheckMagicSquares(a, rowAndColumn, result))
		printf("This is Magic Squares");
	else
		printf("This not Magic Squares");
}

void main() {
	int **a;
	int result, rowAndColumn, mode;
	InputRC(rowAndColumn);
	Formula(rowAndColumn, result);
	Input(a, rowAndColumn);
	//InputRand(a, rowAndColumn);
	IsMagicSquares(a, rowAndColumn, result);
	_getch();
}