// producerconsumer
#include <stdio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty = 3, x = 0;
void main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int semSignal(int);
    printf("1.Producer\n2.Consumer\n3.Exit");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty");
            break;
        case 3:
            exit(0);
            break;
        }
    }
}
int wait(int s)
{
    return (--s);
}
int semSignal(int s)
{
    return (++s);
}
void producer()
{
    mutex = wait(mutex);
    full = semSignal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d", x);
    mutex = semSignal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = semSignal(empty);
    printf("\nConsumer consumes the item %d", x);
    x--;
    mutex = semSignal(mutex);
}
