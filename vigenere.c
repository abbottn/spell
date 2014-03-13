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
        printf("Usage: ./vigenere <key>\n");
        return 1;
    }
    else
    {
        /* check for nonalphabetical input */
        string keycode;
        keycode = argv[1];
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(keycode[i]))
            {
                continue;
            }
            else
            {
                printf("Usage: ./vigenere <key>\n");
                return 1;
            }
        }
    }
    
    /* Passed validation, start encryption */
    int keylength = strlen(argv[1]);
    string key;
    key = argv[1];
    int alphacount = 0;
    string plain = GetString(); 
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        char byte = plain[i];
        int ciphertext = byte;
        if (isalpha(byte))
        {
            int k;
            int j = alphacount % keylength;
            alphacount++;
            int ascii = key[j];
            if (isupper(byte))
            {
                if (ascii >= 97)
                {
                    k = ascii - 97;
                }
                else
                {
                    k = ascii - 65;
                }
                int plaintext = byte;
                int alphatext = plaintext - 65;
                int enchiper = (alphatext + k);
                ciphertext = ((enchiper % 26) + 65);
            }
            else
            {
                
                if (ascii >= 97)
                {
                    k = ascii - 97;
                }
                else
                {
                    k = ascii - 65;
                }
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
