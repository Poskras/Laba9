#include <stdio.h>
#include <locale.h>
#include <windows.h>

#define ROW 9
#define COL 9

int Task1_1(int row, int col);
int Task1_2(int row, int col);
int Task1_3(int row, int col);
int Task2(int number);
char Task3(char symbol, int height, int width, int row, int col);

int main()
{
    int row;
    int col;
    int number;
    int sum;
    int inputResult;
    char answer;
    char symbol;
    int again;
    int height;
    int width;

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF8");

    printf("ЗАДАНИЕ 1.1. Таблица умножения\n");
    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= COL; col++)
        {
            printf("%5d", Task1_1(row, col));
        }
        printf("\n");
    }

    printf("\nЗАДАНИЕ 1.2. Левый нижний треугольник таблицы умножения\n");
    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= row; col++)
        {
            printf("%5d", Task1_2(row, col));
        }
        printf("\n");
    }

    printf("\nЗАДАНИЕ 1.3. Вывод чисел от 41 до 80\n");
    for (row = 0; row < 4; row++)
    {
        for (col = 0; col < 10; col++)
        {
            printf("%5d", Task1_3(row, col));
        }
        printf("\n");
    }

    printf("\nЗАДАНИЕ 2. Сумма цифр, больших или равных 7\n");
    do
    {
        printf("Введите целое положительное число: ");
        inputResult = scanf_s("%d", &number);

        if (inputResult != 1 || number <= 0)
        {
            printf("Ошибка: необходимо ввести положительное целое число.\n");
            return 1;
        }

        sum = Task2(number);
        printf("Сумма цифр, больших или равных 7: %d\n", sum);

        printf("Продолжить? (y — да, n — нет): ");
        if (scanf_s(" %c", &answer, 1) != 1)
        {
            printf("Ошибка ввода ответа.\n");
            return 1;
        }
    } while (answer == 'y' || answer == 'Y');

    printf("\nЗАДАНИЕ 3. Рисование фигуры\n");
    do
    {
        printf("Введите символ для рисования фигуры: ");
        if (scanf_s(" %c", &symbol, 1) != 1)
        {
            printf("Ошибка ввода символа.\n");
            return 1;
        }

        printf("Введите высоту фигуры (1-100): ");
        if (scanf_s("%d", &height) != 1 || height < 1 || height > 100)
        {
            printf("Ошибка: высота должна быть от 1 до 100.\n");
            return 1;
        }

        printf("Введите ширину фигуры (1-100): ");
        if (scanf_s("%d", &width) != 1 || width < 1 || width > 100)
        {
            printf("Ошибка: ширина должна быть от 1 до 100.\n");
            return 1;
        }

        printf("\n");
        for (row = 0; row < height; row++)
        {
            for (col = 0; col < width; col++)
            {
                printf("%c", Task3(symbol, height, width, row, col));
            }
            printf("\n");
        }

        printf("\nПродолжить? (любое ненулевое число — да, 0 — нет): ");
        if (scanf_s("%d", &again) != 1)
        {
            printf("Ошибка ввода ответа.\n");
            return 1;
        }
    } while (again != 0);

    return 0;
}

int Task1_1(int row, int col)
{
    return row * col;
}

int Task1_2(int row, int col)
{
    return row * col;
}

int Task1_3(int row, int col)
{
    return 41 + row * 10 + col;
}

int Task2(int number)
{
    int digit;
    int sum;

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
    return sum;
}

char Task3(char symbol, int height, int width, int row, int col)
{
    int inset;

    inset = row * width / (4 * height);
    if (col >= inset && col < width - inset)
    {
        return symbol;
    }
    return ' ';
}
