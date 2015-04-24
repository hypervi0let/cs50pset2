#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // Prompts user for name.
    string name = GetString();
    
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] == name[0])
        {
            // Prints initial of first character in string.
            printf("%c", toupper(name[i]));
        }
        if (name[i] == ' ')
        {
            // Prints initial of first character after spaces in string.
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}
