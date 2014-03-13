/* caesar.c
 * by Nick Abbott
 *
 * encrypts messages using Caesar's cipher and displays the
 * result
 *
 * Usage: ./caesar key
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
        printf("Usage: ./caesar <key>");
        return 1;
    }
    int k = atoi(argv[1]);
    string msg = GetString();  
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        char byte = msg[i];
        int ciphertext = byte;
        if (isalpha(byte))
        {
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
