#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count = 4;

    if (count > 5)
    {
        printf("%i é maior que 5\n", count);
    } 
    else if (count < 5)
    {
        printf("%i é menor que 5\n", count);
    } 
    else
    {
        printf("%i é igual a 5 \n", count);
    }
}
