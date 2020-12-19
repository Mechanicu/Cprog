#include <stdio.h>

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

int main()
{
    student s[3] = {
        {1000, "Ken", MALE},
        {1001, "Zoe", FEMALE},
        {1002, "David", MALE}
    };
    int i;
    student *p;

    p = s;
    for (i = 0; i < 3; ++i, ++p)
        printf("%u,%s,%s\n", p->sid, p->name, p->gender == MALE ? "Male" : "Female");

    return 0;
}