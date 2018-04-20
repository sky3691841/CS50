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
        printf("Usage: ./caesar k\n");
        return 1;
    }

    int k = atoi(argv[1]);

    //get plaintext
    printf("plaintext: ");
    string text = get_string();

    //enciper
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] -= 65;                //from ASCII to alphabetic
                text[i] = (text[i] + k) % 26;
                text[i] += 65;                //back to ASCII
            }

            if (islower(text[i]))
            {
                text[i] -= 97;
                text[i] = (text[i] + k) % 26;
                text[i] += 97;
            }

        }
    }

    printf("ciphertext: %s\n", text);

    return 0;
}
