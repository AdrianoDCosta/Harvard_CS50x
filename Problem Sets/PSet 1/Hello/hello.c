#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's yout name? \n"); // Variable 'name' type string 
    printf("hello, %s\n", name); //command to print in screen | %s expression to plug in variable
}
