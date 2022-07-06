/*
* @file Practice2022.c
* @author Шарапов І.Ю. гр. 515-А
* @date 27 червня 2022
* @brief
*
* Завдання: Розробити програму, що переводить ціле число у текст
* англійською мовою.Необхідно реалізувати підтримку позитивних і
* негативних чисел в діапазоні 32 - бітного знакового числа (Варіант 26)
*
*/

#include "func.h" // підключення заголовного файлу

int main()
{

    long long user_number = INFINITY; // оголошення змінної 

    // цикл перевірки на корректність вводу числа
    while (user_number < INT_MIN || user_number > INT_MAX) {
        printf("Enter the number: "); // запрошення до вводу числа
        scanf_s("%lld", &user_number); // ввід числа
        if (user_number < INT_MIN || user_number > INT_MAX)
            printf("Incorrect range!\n");
    }

    if (transform(user_number) == 0) // виклик функції 
        printf("ERROR!\n"); 

    putchar('\n'); 
    
    return 0;
}
