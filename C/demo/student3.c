#include <stdio.h>
#include <string.h>

typedef char GENDER;
const GENDER MALE = 'M';
const GENDER FEMALE = 'F';

typedef struct
{
    unsigned year, month, day;
} date;

typedef struct 
{
    unsigned sid;
    char name[32];
    GENDER gender;
    //date dob;
} student;

void bubble_sort(student a[], int len)
{
    int i, j;
    student t;

    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j)
            if (strcmp(a[j].name, a[j+1].name) > 0)
            { // block
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

int main()
{
    student s[5] = {
        {1000, "Ken", MALE},
        {1001, "Zoe", FEMALE},
        {1002, "David", MALE},
        {1003, "Linda", FEMALE},
        {1004, "Phoebe", FEMALE}
    };
    int i;
    student *p;

    bubble_sort(s, 5);
    p = s;
    for (i = 0; i < 5; ++i, ++p)
        printf("%u,%s,%s\n", p->sid, p->name, p->gender == MALE ? "Male" : "Female");

    return 0;
}