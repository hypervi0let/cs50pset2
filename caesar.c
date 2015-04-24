/*
 * Caesar.c - Matt J. Gabell
 * for cs50x pset2. Command line
 * program that encrypts text
 * using Caesar's cipher.
 * Usage: ./caesar <key>
 */
 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{   
    string error = "Please enter a single, positive integer as an argument.";
    
    // Validates argument; existance.
    if (argc != 2)
    {
        printf("%s\n", error);
        return 1;
    }

    // Converts argument from string to integer.
    int key = atoi(argv[1]);
    
    // Validates argument; is positive integer.
    if (key < 0)
    {
        printf("%s\n", error);
        return 1;
    }
    
    // Prompts user for text to be encrypted.
    string text = GetString();
    int pchar;
    int cchar;

    /*  Loops through each character in the text, ignores
    non alphabetic characters, leaving them untouched.
    Then checks whether the current character is upper
    or lower case. Each alphabetic character is then
    converted from ASCII to alphabet index. The forumla
        ci = (pi + k) % 26
    is then used to compute Caesar's cipher. The index
    is then converted back to ASCII and printed to the user. */
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        pchar = text[i];
        
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                cchar = pchar - 65;
                cchar = (cchar + key) % 26;
                cchar = cchar + 65;
                printf("%c", cchar);
            }
            if (islower(text[i]))
            {
                cchar = pchar - 97;
                cchar = (cchar + key) % 26;
                cchar = cchar + 97;
                printf("%c", cchar);
            }
        }
        // Leave non alphabetic characters untouched.
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
