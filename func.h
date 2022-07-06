#include <stdio.h>
#include <limits.h>
#include <math.h>

char* numbers[7][10] = { "one", "two", "three", "four", "five", "six","seven","eight", "nine", "",
                    "ten", "eleven", "twelve", "thirteen","fourteen", "fifteen", "sixteen", "seventeen", "eighteen","nineteen",
                    "twenty", "thirty", "fourty", "fifty", "sixty","seventy", "eighty", "ninety", " ", " ",
                    "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred", "",
                    "thousands", "thousand", "thousands", "", "", "", "", "", "", "",
                    "millions", "million", "millions", "", "", "", "", "", "", "",
                    "billions", "billion", "billions" };

int transform(int user_number){ 
    if (user_number < INT_MIN || user_number > INT_MAX) {
        return 0;
    }

    printf("\nYour converted number: ");
  
    if (user_number == 0) printf("Zero"); 

    if (user_number < 0) 
    {
        printf("Minus ");
        user_number *= -1;
    }

    while (user_number > 0) 
    {
        int one = 0, tens = 0, hundreds = 0, buffer = user_number;
        if (user_number >= 1000000000)   
            user_number /= 1000000000;
        else if (user_number >= 1000000) 
            user_number /= 1000000;
        else if (user_number >= 1000) 
            user_number /= 1000;

        if (user_number >= 100) 
        {
            hundreds = user_number / 100;
            user_number %= 100;
        }
        if (user_number >= 10) 
        {
            tens = user_number / 10;
            user_number %= 10;
        }
        one = user_number;

        if (buffer >= 1000000000) 
        {
            int offset = 0;

            if (hundreds > 0)
                printf("%s ", numbers[3][hundreds - 1]);
            if (tens > 0) 
            {
                if (tens > 1) 
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
                    offset = 2;
            }
            printf("%s ", numbers[6][offset]);
        }


        else if (buffer >= 1000000) 
        {
            int offset = 0;

            if (hundreds > 0) 
                printf("%s ", numbers[3][hundreds - 1]);
            if (tens > 0) 
            {
                if (tens > 1) 
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
            if (one > 0)
            {
                printf("%s ", numbers[0][one - 1]);
                if (one == 1)
                    offset = 1;
                else if (one > 1 && one <= 4)
                    offset = 2;
            }
            printf("%s ", numbers[5][offset]);
        }
        else if (buffer >= 1000) 
        {
            int offset = 0;

            if (hundreds > 0) 
                printf("%s ", numbers[3][hundreds - 1]);
            if (tens > 0) 
            {
                if (tens > 1) 
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
                    offset = 2;
            }
            printf("%s ", numbers[4][offset]);
        }
        else
        {
            if (hundreds > 0) 
                printf("%s ", numbers[3][hundreds - 1]);
            if (tens > 0) 
            {
                if (tens > 1) 
                    printf("%s ", numbers[2][tens - 2]);
                else
                {
                    printf("%s ", numbers[1][one]);
                    one = 0;
                }
            }
            if (one > 0)
                printf("%s ", numbers[0][one - 1]);
        }
        if (buffer >= 1000000000) 
            buffer %= 1000000000;
        else if (buffer >= 1000000) 
            buffer %= 1000000;
        else if (buffer >= 1000) 
            buffer %= 1000;
        else
            buffer = 0;

        user_number = buffer;
    }

    return 1;
}
