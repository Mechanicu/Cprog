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
    date dob;
} student;

int main()
{
    student s = {1000, "Lao Bai", MALE,
        {2001, 12, 31}
    };
    student *p = &s;

    printf("%u,%s,%s,%u\n", s.sid, p->name, s.gender == MALE ? "Male" : "Female",
    p->dob.year);

    return 0;
}