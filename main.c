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

#include "func.h" 

int main()
{

    long long user_number = INFINITY; 
    
    printf("Enter the number: "); 
    scanf_s("%lld", &user_number); 

    if (transform(user_number) == 0) 
        printf("ERROR!\n"); 

    putchar('\n'); 
    
    return 0;
}
