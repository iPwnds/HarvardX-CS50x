#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Declaring the 2 added methods
bool validateKey(string key);
void encrypt(string plaintext, string key);

int main(int arguments, string input[])
{
    // Checks for exactly 2 arguments when running
    if (arguments != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Checks if the key is valid
    if (!validateKey(input[1]))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Creates a version of the key in all CAPS
    char uppercaseKey[27];
    for (int i = 0; i < 26; i++)
    {
        uppercaseKey[i] = toupper(input[1][i]);
    }
    // NULL terminates the string
    uppercaseKey[26] = '\0';

    // Asks the user for some "plaintext" input
    string plaintext = get_string("plaintext: ");
    // Prints the ciphertext
    printf("ciphertext: ");
    encrypt(plaintext, uppercaseKey);
    printf("\n");

    return 0;
}

// Validates the key
bool validateKey(string key)
{
    // Makes sure the string is 26 characters long
    if (strlen(key) != 26)
    {
        return false;
    }

    // Makes sure the key has no duplicate letters
    bool seen[26] = {false};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }
    return true;
}

// Encrypts the plaintext into ciphertext
void encrypt(string plaintext, string key)
{
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            printf("%c", key[index]);
        }
        else if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
}
