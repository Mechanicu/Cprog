#include<stdbool.h>
#define MAX_LENGTH 50

#define kinderfisher
#ifdef kinderfisher
typedef struct kingderfisher
{
    char id[MAX_LENGTH];
    int weight;
    int length;
    char name[MAX_LENGTH];
    bool Is_carnivorous;
    bool Is_Marine;
    char color[MAX_LENGTH];
    int speed;
}INFO, *INFOPTR;
#endif

#ifdef  rabbit
typedef struct rabbit
{
    char id[MAX_LENGTH];
    int weight;
    int length;
    char name[MAX_LENGTH];
    bool Is_carnivorous;
    bool Is_Marine;
    char coat_color[MAX_LENGTH];
    int age;

}INFO, *INFOPTR;
#endif

#ifdef hippopotamus
typedef struct hippopotamus
{
    char id[MAX_LENGTH];
    int weight;
    int length;
    char name[MAX_LENGTH];
    bool Is_carnivorous;
    bool Is_Marine;
    int age;
    char living_area[MAX_LENGTH];
}INFO, *INFOPTR;
#endif 