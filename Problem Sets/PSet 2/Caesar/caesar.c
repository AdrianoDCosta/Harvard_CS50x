#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2 && isdigit(*argv[1]))
    {   
// Verificação para chave não numérica
        int lengargv = strlen(argv[1]);
        for (int i = 0; i < lengargv; i ++)
        {
            int z = isalpha(argv[1][i]);
            if (z != 0)
            {
                printf("Usage: ./caesar key \n");
                return 1;
            }
        } // aqui obtém o valor de KEY ceasar
        int k = atoi(argv[1]);
        string gettext = get_string("plaintext: "); // obtém o texto
        printf("ciphertext: ");

        for (int i = 0, n = strlen(gettext) ; i < n; i++)// Iterar texto simples
        {
            if (gettext[i] >= 'A' && gettext[i] <= 'Z') // se estiver entre maiúsculas A e Z
            {
                printf("%c", (((gettext[i] - 'A') + k) % 26) + 'A');
            }
            else if (gettext[i] >= 'a' && gettext[i] <= 'z')// se estiver em minúsculas a a z
            {
                printf("%c", (((gettext[i] - 'a') + k) % 26) + 'a'); // imprime as letras minúsculas
            }
            else
            {
                printf("%c", gettext[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
