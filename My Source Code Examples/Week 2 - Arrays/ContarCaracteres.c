#include <stdio.h>

int main(void)
{
    int tamanhoString(char string[]);
    char stringUsuario[20];
    
    printf("Digite uma palavra(string): \n");
    scanf("%s", stringUsuario);
    
    int num = tamanhoString(stringUsuario);
    
    printf("A string %s possui %i caracteres \n", stringUsuario, num);

    return 0;
}

int tamanhoString(char string[])
{
    int numCaracteres = 0;
    
    while(string[numCaracteres] != '\0')
    {
        ++numCaracteres;
    }
    return numCaracteres;
}