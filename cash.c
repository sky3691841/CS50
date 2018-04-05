#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //make sure user input non-negative
    float change;
    int cents, count, leftover, quarter_count, dime_count, nickel_count, penny_count;

    do
    {
        printf("How much change is owed?\nNote: 4.21 represents 4 dollars and 21 cents.\n");
        change = get_float();
    }
    while (change < 0);

    //convert changes to cents
    cents = round(change * 100);

    //calculation of coins
    quarter_count = cents / 25;
    leftover = cents % 25;

    dime_count = leftover / 10;
    leftover = leftover % 10;

    nickel_count = leftover / 5;
    leftover = leftover % 5;

    penny_count = leftover;

    count = quarter_count + dime_count + nickel_count + penny_count;

    //print the result
    printf("%i\n", count);
}
