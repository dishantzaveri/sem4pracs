// disc scheduling

// 6) SSTF
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("%d=>", initial);
    while (count != n)
    {
        int min = 1000, d, index;
        for (i = 0; i < n; i++)
        {
            d = abs(RQ[i] - initial);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        TotalHeadMoment = TotalHeadMoment + min;
        initial = RQ[index];
        RQ[index] = 1000;
        count++;
        printf("%d=>", initial);
    }
    printf("end");
    printf("\nTotal head movement is %d", TotalHeadMoment);
    return 0;
}

// 7)SCAN
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("Enter total disk size\n");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("%d\t", RQ[i]);
    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i]) // given pointer to first track
        {
            index = i;
            break;
        }
    }
    printf("\n%d=>", initial);
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            printf("%d=>", RQ[i]);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial); // calculate the movement
            initial = RQ[i];                                          // move pointer forward
        }
        TotalHeadMoment = TotalHeadMoment + abs(size - RQ[i - 1] - 1);
        printf("%d=>", size - 1);
        initial = size - 1;
        for (i = index - 1; i >= 0; i--)
        {
            printf("%d=>", RQ[i]);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            printf("%d=>", RQ[i]);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i + 1] - 0);
        printf("0=>");
        initial = 0;
        for (i = index; i < n; i++)
        {
            printf("%d=>", RQ[i]);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    printf("end");
    printf("\nTotal head movement is %d", TotalHeadMoment);
    return 0;
}

// 8)CScan
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("Enter total disk size\n");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("%d\t", RQ[i]);
    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i]) // given pointer to first track
        {
            index = i;
            break;
        }
    }
    printf("\n%d=>", initial);
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            printf("%d=>", RQ[i]);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial); // calculate the movement
            initial = RQ[i];                                          // move pointer forward
        }
        TotalHeadMoment = TotalHeadMoment + abs(size - RQ[i - 1] - 1);
        printf("%d=>", size - 1);
        TotalHeadMoment = TotalHeadMoment + abs(size - 1);
        printf("0=>");
        initial = 0;
        for (i = 0; i < index; i++)
        {
            printf("%d=>", RQ[i]);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            printf("%d=>", RQ[i]);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i + 1] - 0);
        printf("0=>");

        TotalHeadMoment = TotalHeadMoment + abs(size - 1);

        printf("%d=>", size - 1);

        initial = size - 1;

        for (i = n - 1; i >= index; i--)

        {

            printf("%d=>", RQ[i]);

            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);

            initial = RQ[i];
        }
    }

    printf("end");

    printf("\nTotal head movement is %d", TotalHeadMoment);

    return 0;
}

// 9)Look
#include <stdio.h>

#include <stdlib.h>

int main()

{

    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;

    printf("Enter the number of Requests\n");

    scanf("%d", &n);

    printf("Enter the Requests sequence\n");

    for (i = 0; i < n; i++)

        scanf("%d", &RQ[i]);

    printf("Enter initial head position\n");

    scanf("%d", &initial);

    printf("Enter total disk size\n");

    scanf("%d", &size);

    printf("Enter the head movement direction for high 1 and for low 0\n");

    scanf("%d", &move);

    /*logic for sort the request array */

    for (i = 0; i < n; i++)

    {

        for (j = 0; j < n - i - 1; j++)

        {

            if (RQ[j] > RQ[j + 1])

            {

                int temp;

                temp = RQ[j];

                RQ[j] = RQ[j + 1];

                RQ[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)

        printf("%d\t", RQ[i]);

    int index;

    for (i = 0; i < n; i++)

    {

        if (initial < RQ[i])

        {

            index = i;

            break;
        }
    }

    printf("\n%d=>", initial);

    // if movement is towards high value

    if (move == 1)

    {

        for (i = index; i < n; i++)

        {

            printf("%d=>", RQ[i]);

            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);

            initial = RQ[i];
        }

        for (i = index - 1; i >= 0; i--)

        {

            printf("%d=>", RQ[i]);

            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);

            initial = RQ[i];
        }
    }

    // if movement is towards low value

    else

    {

        for (i = index - 1; i >= 0; i--)

        {

            printf("%d=>", RQ[i]);

            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);

            initial = RQ[i];
        }

        for (i = index; i < n; i++)

        {

            printf("%d=>", RQ[i]);

            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);

            initial = RQ[i];
        }
    }

    printf("end");

    printf("\nTotal head movement is %d", TotalHeadMoment);

    return 0;
}

// 10)Clook
#include <stdio.h>

#include <stdlib.h>

int main()

{

    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;

    printf("Enter the number of Requests\n");

    scanf("%d", &n);

    printf("Enter the Requests sequence\n");

    for (i = 0; i < n; i++)

        scanf("%d", &RQ[i]);

    printf("Enter initial head position\n");

    scanf("%d", &initial);

    printf("Enter total disk size\n");

    scanf("%d", &size);

    printf("Enter the head movement direction for high 1 and for low 0\n");

    scanf("%d", &move);

    /*logic for sort the request array */

    for (i = 0; i < n; i++)

    {

        for (j = 0; j < n - i - 1; j++)

        {

            if (RQ[j] > RQ[j + 1])

            {

                int temp;

                temp = RQ[j];

                RQ[j] = RQ[j + 1];

                RQ[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)

        printf("%d\t", RQ[i]);

    int index;

    for (i = 0; i < n; i++)

    {

        if (initial < RQ[i])

        {

            index = i;

            break;
        }
    }

    printf("\n%d=>", initial);

    // if movement is towards high value

    if (move == 1)

    {

        for (i = index; i < n; i++)

        {

            printf("%d=>", RQ[i]);

            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);

            initial = RQ[i];
        }

        for (i = 0; i < index; i++)

        {

            printf("%d=>", RQ[i]);

            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);

            initial = RQ[i];
        }
    }

    // if movement is towards low value

    else

    {

        for (i = index - 1; i >= 0; i--)

        {

            printf("%d=>", RQ[i]);

            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);

            initial = RQ[i];
        }

        for (i = n - 1; i >= index; i--)

        {

            printf("%d=>", RQ[i]);

            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);

            initial = RQ[i];
        }
    }

    printf("end");

    printf("\nTotal head movement is %d", TotalHeadMoment);

    return 0;
}