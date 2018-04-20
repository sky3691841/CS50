#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //get key from user
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    //make sure key is alphabetical
    string key = argv[1];

    for (int k = 0, l = strlen(key); k < l; k++)
    {
        if (!isalpha(key[k]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    //get plaintext
    printf("plaintext: ");
    string text = get_string();

    //enciper
    for (int i = 0, j = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] -= 65;  //from ASCII to alphabetic
                int m = j % strlen(key);  //make the key wrap around, use m so program doesn't mess with j

                if (isupper(key[m]))
                {
                    key[m] -= 65;   //from ASCII to alphabetic
                    text[i] = (text[i] + key[m]) % 26;
                    key[m] += 65;  //back to ASCII
                }

                if (islower(key[m]))
                {
                    key[m] -= 97;
                    text[i] = (text[i] + key[m]) % 26;
                    key[m] += 97;
                }

                text[i] += 65;                //back to ASCII
                j++;
            }

            if (islower(text[i]))
            {
                text[i] -= 97;
                int m = j % strlen(key);

                if (isupper(key[m]))
                {
                    key[m] -= 65;
                    text[i] = (text[i] + key[m]) % 26;
                    key[j] += 65;
                }

                if (islower(key[m]))
                {
                    key[m] -= 97;
                    text[i] = (text[i] + key[m]) % 26;
                    key[m] += 97;
                }

                text[i] += 97;
                j++;
            }

        }
    }

    printf("ciphertext: %s\n", text);

    return 0;
}
