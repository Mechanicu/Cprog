#include <stdio.h>

#include "crosslist.h"

int main()
{
    OLNode nodes[] = {
        {1, 1, -3},
        {1, 4, 5},
        {2, 2, -1},
        {3, 1, 8},
        {3, 4, 7}
    };
    CrossList M;

    CreateCrossList(&M, nodes, 3, 4, 5);
    PrintCrossList(&M, 0);
    PrintCrossList(&M, 1);
    DestroyCrossList(&M);

    return 0;
}