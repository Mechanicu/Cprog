#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char GRAPH[15][70];

GRAPH graph = 
{
"                                                    ",
"                       ############                 ",
"                  #####------------##               ",
"                ## ------------------#######        ",
"                #---------###---------------####### ",
"              ##+++++++++#   ##++++++++++++++++++++#",
"              #>>>>>>>>>#      #<<<<<<<<<<<<<<<<<## ",
"               #/////////#    #]]]]]]]]]]]]]]]]]#   ",
"                #*********####*****************#    ",
"                 ####^^^^^^^^^^^^^^^^^^^^^#####     ",
"                     #```````````````````#          ",
"                      ###### ~~~~~~~~####           ",
"                            #########               ",
"                                                    ",
"$"
};

const char boundary_color = '#';
const char fill_color = '.';

void draw(GRAPH g)
{
    int i = 0;
    
    while (true)
    {
        if (g[i][0] == '$') break;

        printf("%s\n", g[i++]);
    }
}

void boundaryfill(GRAPH g, int seedx, int seedy)
{
    char *p = &g[seedy][seedx];
    if (*p == boundary_color || *p == fill_color) return;

    *p = fill_color;
    boundaryfill(g, seedx - 1, seedy);
    boundaryfill(g, seedx + 1, seedy);
    boundaryfill(g, seedx, seedy - 1);
    boundaryfill(g, seedx, seedy + 1);
}

int main()
{
    draw(graph);

    boundaryfill(graph, 35, 5);

    draw(graph);

    return 0;
}