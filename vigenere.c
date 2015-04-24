/*
 * Vigenere.c - Matt J. Gabell
 * for cs50x pset2. Command line
 * program that encrypts text
 * using Vigenere cipher.
 * Usage: ./vigenere <keyword>
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Error message used by validation.
    string error = "Usage: ./vigenere <keyword>\n";

    // Validates the keyword argument by checking whether it is present.
    if (argc != 2)
    {
        printf("%s", error);
        return 1;
    }

    // Checks that keyword does not contain characters other than alphabetic.
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("%s", error);
            return 1;
        }
    }

    /*	Store length of keyword in variable 'keylength'.
        Set up an array prototype to store ASCII values
        converted to alphabetic indices. */
    int keylength = strlen(argv[1]);
    int keyarray[keylength], keychar;

    /*  Loop through each character in the keyword, converting it from ASCII
        to an alphabet index and then storing that index in an array. */
    for (int i = 0; i < keylength; i++)
    {
        keychar = argv[1][i];
        if (islower(keychar))
        {
            keyarray[i] = keychar - 97;
        }
        if (isupper(keychar))
        {
            keyarray[i] = keychar - 65;
        }
    }

    // Prompts the user for the text they want to be encrypted.
    string text = GetString();
    // Declare varibles used in cipher.
    int cchar, wrap, j;
    j = 0;

    /*  Loops through each character in the text, ignores
        non alphabetic characters, leaving them untouched.
        Then checks whether the current character is upper
        or lower case. Each alphabetic character is then
        converted from ASCII to alphabet index. The forumla
            ci = (pi + kj) % 26
        is then used to compute the vigenere cipher. The index
        is then converted back to ASCII and printed to the user. */
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                cchar = text[i] - 65;
                wrap = j % keylength;
                cchar = (cchar + keyarray[wrap]) % 26;
                cchar = cchar + 65;
                printf("%c", cchar);
            }
            if (islower(text[i]))
            {
                cchar = text[i] - 97;
                wrap = j % keylength;
                cchar = (cchar + keyarray[wrap]) % 26;
                cchar = cchar + 97;
                printf("%c", cchar);
            }
        // Increments j by 1 on if an alphabetic character was encrypted.
            j++;

        }
        // Non-alphabetic characters are untouched.
        else
        {
            printf("%c", text[i]);
        }
    }
    // Print a new line.
    printf("\n");
    return 0;
}
