// crc

#include <stdio.h>
void generateCRC(int data[], int g[], int n, int n1)
{
    int crc[(n1 + n - 1)];
    int i, j, k;
    for (i = 0; i < n1; i++)
        crc[i] = data[i];
    for (i = n1; i < (n1 + n - 1); i++)
        crc[i] = 0;
    printf("\n");
    for (i = 0; i < n1; i++)
    {
        if (crc[i] == 1)
        {
            for (j = i, k = 0; j < i + n; j++, k++)
                crc[j] = (crc[j]) ^ (g[k]);
        }
        else
        {
            for (j = i; j < i + n; j++)
                crc[j] = (crc[j]) ^ (0);
        }
    }
    for (i = 0; i < n1; i++)
        crc[i] = data[i];
    printf("CRC: ");
    for (i = 0; i < (n1 + n - 1); i++)
        printf("%d", crc[i]);
    printf("\n");
}
void checkCRC(int crc[], int g[], int n, int n1)
{
    int i, j, k;
    int data[(n1 - n + 1)];
    for (i = 0; i < (n1 - n + 1); i++)
    {
        data[i] = crc[i];
        printf("%d", data[i]);
    }
    printf("\n");
    for (i = 0; i < n1 - n + 1; i++)
    {
        if (crc[i] == 1)
        {
            for (j = i, k = 0; j < i + n; j++, k++)
                crc[j] = (crc[j]) ^ (g[k]);
        }
        else
        {
            for (j = i; j < i + n; j++)
                crc[j] = (crc[j]) ^ (0);
        }
    }
    int count = 0;
    for (i = (n1 - n + 1); i < n1; i++)
    {
        if (crc[i] == 0)
            count++;
    }
    if (count == (n - 1))
    {
        printf("Codeword is correct!!\n");
        printf("Data: ");
        for (i = 0; i < (n1 - n + 1); i++)
            printf("%d", data[i]);
        printf("\n");
    }
    else
        printf("Codeword is incorrect\n");
}
void main()
{
    int i, choice, n, n1 = 0;
    printf("Enter generating functions length: ");
    scanf("%d", &n);
    int g[n];
    printf("Enter generating function: ");
    for (i = 0; i < n; i++)
        scanf("%d", &g[i]);
    do
    {
        printf("\nMENU\n1.To generate crc\n2.To check crc\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter data length: ");
            scanf("%d", &n1);
            int data[n1];
            printf("Enter data: ");
            for (i = 0; i < n1; i++)
                scanf("%d", &data[i]);
            generateCRC(data, g, n, n1);
        }
        else if (choice == 2)
        {
            printf("Enter crc length: ");
            scanf("%d", &n1);
            int crc[n1];
            printf("Enter CRC: ");
            for (i = 0; i < n1; i++)
                scanf("%d", &crc[i]);
            checkCRC(crc, g, n, n1);
        }
        else
            printf("Exit\n");
    } while (choice < 3 && choice > 0);
}