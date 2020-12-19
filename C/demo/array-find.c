#include <stdio.h>

int main()
{
    //array
    int score[5];
    int i;
    double avg;
    int max, j;
    
    for (i = 0; i < 5; ++i)
        scanf("%d", &score[i]);

    j = 0;
    max = score[j];
    for (i = 0; i < 5; ++i)
        if (max < score[i])
            max = score[j = i];

    printf("%d@%d", max, j);

    return 0;
}