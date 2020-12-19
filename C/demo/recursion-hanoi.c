// hanoi(n, src, dest, aux)

// hanoi(n, a, b, c)

//     hanoi(n-1, a, c, b)
//     a -> b
//     hanoi(n-1, c, b, a)

#include <stdio.h>

void move(char src, char dest)
{
    printf("%c ---> %c\n", src, dest);
}

void hanoi(int n, char src, char dest, char aux)
{
    if (n == 1)
    {
        move(src, dest);
        return;
    }

    hanoi(n - 1, src, aux, dest);
    move(src, dest);
    hanoi(n - 1, aux, dest, src);
}

int main()
{
    int n = 3;
    const char src = 'a', dest = 'b', aux = 'c';
    hanoi(n, src, dest, aux);
    
    return 0;
}