#include <stdio.h>

int main()
{
    //array
    int score[] = {3, 5, 2, 1, 4, 9};
    int i;
    //double avg;
    int max, j;
    
    // for (i = 0; i < 5; ++i)
    //     scanf("%d", &score[i]);

    j = 0;
    max = score[j];
    for (i = 0; i < 5; ++i)
        if (max < score[i])
            max = score[j = i];

    max = score[0];
    for (i = 0; i < 5; ++i)
        if (max < score[i] && i != j)
            max = score[i];

    printf("%d", max);

    return 0;
}