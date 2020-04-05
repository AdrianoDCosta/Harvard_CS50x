#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    // Open CSV File
    FILE *file = fopen("Phonebook.csv", "a");
    if (!file)
    {
        return 1;
    }

    // Get name, lastname, city and number
    string name = get_string("Name: ");
    string lastname = get_string("Last name: ");
    string number = get_string("Number: ");

    // Print to file
    fprintf(file, "%s,%s,%s\n", name, lastname, number);

    // Close file
    fclose(file);
}