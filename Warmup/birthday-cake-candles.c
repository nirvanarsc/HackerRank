#include <stdio.h>

void birthdayCakeCandles(int ar_count, int *ar)
{
    int max = ar[0];
    int counter = 0;
    for (int i = 0; i < ar_count; i++)
    {
        if (max < ar[i])
        {
            max = ar[i];
        }
    }
    for (int i = 0; i < ar_count; i++)
    {
        if (ar[i] == max)
        {
            counter++;
        }
    }

    printf("%d\n", counter);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 3, 2};
    birthdayCakeCandles(7, arr);
}