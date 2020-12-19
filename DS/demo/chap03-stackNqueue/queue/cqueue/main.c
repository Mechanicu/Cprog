#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"

Queue q, *Q = &q;

void produce(Queue *Q)
{
    int p;
    
    if (IsFull(Q))
    {
        printf("Cannot produce because repository is full\n");
        return;
    }

    p = rand() % 1000;
    printf("Producer produced an int: %d\n", p);
    EnterQueue(Q, p);
}

void consume(Queue *Q)
{
    if (IsEmpty(Q))
    {
        printf("No product\n");
        return;
    }

    QueueElementType x;
    DeleteQueue(Q, &x);
    printf("Consumer consumed a product: %d\n", x);
}

int main()
{
    int i, p, threshold = 50;

    printf("Please type in the probility of production(0~89):");
    scanf("%d", &threshold);
    threshold = threshold % 90 + 10;

    srand(time(NULL));

    InitQueue(Q);

    for (i = 0; i < 20; ++i)
    {
        p = rand() % 100;

        if (p < threshold) 
            produce(Q);
        else
            consume(Q); 
    }

    DestroyQueue(Q);

    return 0;
}