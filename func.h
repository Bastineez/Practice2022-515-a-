// підключення заголовних файлів
#include <stdio.h>
#include <limits.h>
#include <math.h>

// оголошення матриці зі слів
char* numbers[7][10] = { "one", "two", "three", "four", "five", "six","seven","eight", "nine", "",
                    "ten", "eleven", "twelve", "thirteen","fourteen", "fifteen", "sixteen", "seventeen", "eighteen","nineteen",
                    "twenty", "thirty", "fourty", "fifty", "sixty","seventy", "eighty", "ninety", " ", " ",
                    "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred", "",
                    "thousands", "thousand", "thousands", "", "", "", "", "", "", "",
                    "millions", "million", "millions", "", "", "", "", "", "", "",
                    "billions", "billion", "billions" };

/**
* Розділити введене число на окремі цифри
*
* @param user_number введене число
* @return: 0 - якщо введене число не пройшло перевірку, 1 - в іншому разі
*/
int transform(int user_number){ 
    // перевірка на корректність вводу числа
    if (user_number < INT_MIN || user_number > INT_MAX) {
        return 0;
    }

    printf("\nYour converted number: "); // вивід трансформованого числа

    if (user_number == 0) printf("Zero"); // вивід нуля

    if (user_number < 0) // перевірка на негативне число 
    {
        printf("Minus ");
        user_number *= -1;
    }

    while (user_number > 0) // цикл перетворення та виводу числа
    {
        int one = 0, tens = 0, hundreds = 0, buffer = user_number; // Одиниці, десятки, сотні
        if (user_number >= 1000000000) // умова для числа більшого за мільярд  
            user_number /= 1000000000;
        else if (user_number >= 1000000) // умова для числа більшого за мільйон 
            user_number /= 1000000;
        else if (user_number >= 1000) // умова для числа більшого за тисячу
            user_number /= 1000;

        if (user_number >= 100) // умова для числа більшого за сотню 
        {
            hundreds = user_number / 100;
            user_number %= 100;
        }
        if (user_number >= 10) // умова для числа більшого за десять
        {
            tens = user_number / 10;
            user_number %= 10;
        }
        one = user_number;

        if (buffer >= 1000000000) // умова для числа більшого за мільярд 
        {
            int offset = 0;

            if (hundreds > 0) // якщо число більше за нуль 
                printf("%s ", numbers[3][hundreds - 1]);
            if (tens > 0) // якщо число більше за нуль 
            {
                if (tens > 1) // якщо число більше за один
                {
                    printf("%s ", numbers[2][tens - 2]);
                }
                else
                {
                    printf("%s ", numbers[1][one]);
                    one = 0;
                    offset = 0;
                }
            }
            if (one > 0)
            {
                printf("%s ", numbers[0][one - 1]);
                if (one == 1)
                    offset = 1;
                else if (one > 1 && one <= 4)
                    offset = 2;//"thousands", "thousand", "thousands"
            }
            printf("%s ", numbers[6][offset]);
        }


        else if (buffer >= 1000000) // умова для числа більшого за мільйон
        {
            int offset = 0;

            if (hundreds > 0) // якщо число більше за нуль 
                printf("%s ", numbers[3][hundreds - 1]);
            if (tens > 0) // якщо число більше за нуль 
            {
                if (tens > 1) // якщо число більше за один
                {
                    printf("%s ", numbers[2][tens - 2]);
                }
                else
                {
                    printf("%s ", numbers[1][one]);
                    tens = 0;
                    offset = 0;
                }
            }
            if (one > 0) // якщо число більше за нуль 
            {
                printf("%s ", numbers[0][one - 1]);
                if (one == 1)
                    offset = 1;
                else if (one > 1 && one <= 4)
                    offset = 2;//"thousands", "thousand", "thousands"
            }
            printf("%s ", numbers[5][offset]);
        }
        else if (buffer >= 1000) // умова для числа більшого за тисячу 
        {
            int offset = 0;

            if (hundreds > 0) // якщо число більше за нуль 
                printf("%s ", numbers[3][hundreds - 1]);
            if (tens > 0) // якщо число більше за нуль 
            {
                if (tens > 1) // якщо число більше за один
                {
                    printf("%s ", numbers[2][tens - 2]);
                }
                else
                {
                    printf("%s ", numbers[1][one]);
                    one = 0;
                    offset = 0;
                }
            }
            if (one > 0) // якщо число більше за нуль 
            {
                printf("%s ", numbers[0][one - 1]);
                if (one == 1)
                    offset = 1;
                else if (one > 1 && one <= 4)
                    offset = 2;//"thousands", "thousand", "thousands"
            }
            printf("%s ", numbers[4][offset]);
        }
        else
        {
            if (hundreds > 0) // якщо число більше за нуль 
                printf("%s ", numbers[3][hundreds - 1]);
            if (tens > 0) // якщо число більше за нуль 
            {
                if (tens > 1) // якщо число більше за один 
                    printf("%s ", numbers[2][tens - 2]);
                else
                {
                    printf("%s ", numbers[1][one]);
                    one = 0;
                }
            }
            if (one > 0) // якщо число більше за нуль 
                printf("%s ", numbers[0][one - 1]);
        }
        if (buffer >= 1000000000) // умова для числа більшого за мільярд 
            buffer %= 1000000000;
        else if (buffer >= 1000000) // умова для числа більшого за мільйон 
            buffer %= 1000000;
        else if (buffer >= 1000) // умова для числа більшого за тисячу
            buffer %= 1000;
        else
            buffer = 0;

        user_number = buffer;
    }

    return 1;
}
