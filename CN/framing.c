// framingC
#include <stdio.h>
#include <string.h>

void charCount()
{
    int n;
    printf("ENTER N: ");
    scanf("%d", &n);
    char str[n][10], res[n][11];
    for (int i = 0; i < n; i++)
    {
        printf("ENTER DATA OF FRAME %d: ", (i + 1));
        scanf("%s", str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int l = strlen(str[i]);
        res[i][0] = l + 1 + '0'; // ascii value conversion
        for (int j = 0; j < l; j++)
        {
            res[i][j + 1] = str[i][j];
        }
        res[i][l + 1] = '\0'; // null char at the end of string
    }
    printf("CHARACTER COUNT FRAMES ARE:\n");
    for (int i = 0; i < n; i++)
    {
        printf("DATA OF FRAME %d: ", (i + 1));
        printf("%s\n", res[i]);
    }
}

void charStuff()
{
    int n;
    printf("ENTER LENGTH OF DATA: ");
    scanf("%d", &n);
    char str[n];
    printf("ENTER DATA: ");
    scanf("%s", str);
    char del[1]; // you cant compare char with string so take this too as a string
    printf("ENTER DELIMITER: ");
    scanf("%s", del);
    int count = 0; // will count number of deli
    for (int i = 0, j = i; i < n; i++)
    {
        if (str[i] == del[0])
            count++;
    }
    int pos = 0;
    char res[n + count];
    for (int i = 0; i < n; i++)
    {
        if (str[i] == del[0])
        {
            res[pos] = '#';
            res[pos + 1] = del[0];
            pos += 2;
        }
        else
        {
            res[pos] = str[i];
            pos++;
        }
    }
    res[pos + count - 1] = '\0';
    printf("%s", res);
}

void bitStuff()
{
    int n;
    printf("ENTER LENGTH OF DATA: ");
    scanf("%d", &n);
    char str[n];
    printf("ENTER DATA: ");
    scanf("%s", str);
    int count = 0;
    char res[50];
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
            count++;
        else
            count = 0;
        if (count == 6)
        {
            res[pos] = '0';
            res[pos + 1] = '1';
            pos += 2;
            count = 0;
        }
        else
        {
            res[pos] = str[i];
            pos++;
        }
    }
    res[pos] = '\0';
    printf("%s", res);
}

int main()
{
    int x;
    printf("1. CHARACTER COUNT\n2. CHARACTER STUFFING\n3. BIT STUFFING\n");
    printf("ENTER YOUR OPTION: ");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        charCount();
        break;
    case 2:
        charStuff();
        break;
    case 3:
        bitStuff();
        break;
    default:
        printf("INVALID OPTION!");
    }
    return 0;
}