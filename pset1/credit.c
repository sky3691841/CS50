#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long card_num;

    //get user input
    do
    {
        printf("Please enter your credit card number\n");
        card_num = get_long_long();
    }
    while (card_num <= 0 || card_num > 9999999999999999);

    //check length of num
    int count = 0;

    long long temp_num = card_num; //used to calculate card_num

    while (temp_num > 0)
    {
        temp_num = temp_num / 10;
        count ++;
    }

    //if the number doesn't have the right amount of digits, return invalid
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
    }

    //apply Luhn's algorithm
    int sum = 0;
    temp_num = card_num;    //reset value of temp_num

    for (int i = 1; i <= count; i++)
    {
        int digit = temp_num % 10;
        //Multiply every other digit by 2
        //starting with the number’s second-to-last digit
        if (i % 2 == 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        //sum of all digits
        sum += digit;

        temp_num /= 10;
    }

    //check the validity of num according to Luhn's algo
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }

    //identify card company
    temp_num = card_num;

    //find the first two digits of card_num
    while (temp_num > 100)
    {
        temp_num /= 10;
    }

    int company_id = temp_num;

    if ((company_id == 34 || company_id == 37) && (count == 15))
    {
        printf("AMEX\n");
    }
    else if (company_id < 56 && company_id > 50 && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((company_id / 10 == 4) && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
