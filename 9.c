#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>

void Task1_1();
void Task1_2();
void Task1_3();
void Task2();
void Task3();
void exelpe();

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, ".UTF8");

	Task1_1();
	Task1_2();
	Task1_3();
	Task2();
	Task3();

	return 0;
}

#define ROW 9
#define COL 9
void Task1_1() {
	int row, col;
	printf("\n");
	for (row = 1;row <= ROW;++row)
	{
		for (col = 1;col <= COL;col++)
			printf("%5d", col * row);
		printf("\n");
	}
	system("pause");
}
void Task1_2() {
	int row, col;
	printf("\n левый нижний треугольник: \n");
	for (row = 1; row <= ROW; ++row)
	{
		for (col = 1; col <= row; ++col)
		{
			printf("%5d", col * row);
		}
		printf("\n");
	}
	system("pause");
}
void Task1_3() {
	// вариант 3 20-17

	int row, col;
	int number = 41;
	for (row = 1; row <= 4; ++row)
	{
		for (col = 1; col <= 10; ++col)
		{
			printf("%5d", number);
			number++;
		}
		printf("\n");
	}
	system("pause");
}

void Task2() {

	int number, digit, sum;
	char answer;
	do
	{
		printf("введите целое положительное число: ");
		scanf_s("%d", &number);
		sum = 0;
		while (number > 0)
		{
			digit = number % 10;
			if (digit >= 7)
			{
				sum += digit;
			}
			number /= 10;
		}
		printf("сумма цифр больше или равных 7: %d\n", sum);
		printf("продолжить? (y - да, n - нет): ");
		scanf_s(" %c", &answer);
	} while (answer == 'y' || answer == 'Y');
}

void Task3() {
	char symbol;
	int again;

	do
	{
		printf("введите символ для рисования фигуры: ");
		scanf_s(" %c", &symbol);

		printf("\n");

		int height = 8;
		int width = 16;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j >= i / 2 && j < width - i / 2)
				{
					printf("%c", symbol);
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("\nпродолжить? (Да — любое число, Нет — 0): ");
		scanf_s("%d", &again);
	} while (again != 0);
}