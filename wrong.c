/* vigenere.
 * by Nick Abbott
 *
 * encrypts messages using Vigenere's cipher and displays the
 * result
 *
 * Usage: ./vigenere key
 */
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere <key>");
        return 1;
    }
    else
    {
        /* check for nonalphabetical input */
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1]))
                continue;
            else
            {
                printf("Usage: ./vigenere <key>");
                return 1;
            }
        }
    }
    string user_key = argv[1];
    char key[strlen(user_key)];
    for (int j = 0, m = strlen(user_key); j < m; j++)
    {
        char byte;
        byte = argv[j];
        key[j] = byte;
    }
    int m = strlen(key);
    int alphacount = 0;
    string plain = GetString();
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        char byte = plain[i];
        int ciphertext = byte;
        if (isalpha(byte))
        {
            alphacount++;
            int j = alphacount % m;
            int k = atoi(key[j]);
            if (isupper(byte))
            {
                int plaintext = byte;
                int alphatext = plaintext - 65;
                int enchiper = (alphatext + k);
                ciphertext = ((enchiper % 26) + 65);
            }
            else
            {
                int plaintext = byte;
                int alphatext = plaintext - 97;
                int enchiper = (alphatext + k);
                ciphertext = ((enchiper % 26) + 97);
            }
        }
        printf("%c", ciphertext);
    }
    printf("\n");
    return 0;
}
