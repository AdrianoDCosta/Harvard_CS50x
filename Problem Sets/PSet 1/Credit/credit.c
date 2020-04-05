/* 
:: Valid creditcard numbers for test ::

AMEX
    378282246310005 
MASTERCARD
    5105105105105100
VISA
    4012888888881881
*/

#include <stdio.h>
#include <cs50.h>

int main()
{
    long long number = get_long_long("What's your credit card number? "); // requesting entry of the card number
    int sumdouble = 0, sumevens = 0, numdigits = 0, n1 = 0, n2 = 0;

    while (number > 0)
    {
        n2 = n1;
        n1 = number % 10;

        if (numdigits % 2 != 0)
        {
            int multiple = 2 * n1;
            sumdouble += (multiple / 10) + (multiple % 10);   
        }
        else
        {
            sumevens += n1;
        }
        number /= 10;
        numdigits++;
    }
    bool valid = (sumdouble + sumevens) % 10 == 0;
    int f_two_digits = (n1 * 10) + n2;

    // Valdation of flags
    // VISA credit card validation
    if (n1 == 4 && numdigits >= 13 && numdigits <= 16 && valid)
    {
        printf("VISA\n");
    }
    // MasterCard credit card validation
    else if (f_two_digits >= 51 && f_two_digits <= 55 && numdigits == 16 && valid)
    {
        printf("MASTERCARD\n");
    }
    // AMEX credit card validation
    else if ((f_two_digits == 34 || f_two_digits == 37) && numdigits == 15 && valid)
    {
        printf("AMEX\n");
    }
    // if the user enter a invalid number
    else 
    {
        printf("Sorry, number is INVALID\n");
    }
}
