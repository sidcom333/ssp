#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void main()
{
    FILE *f;
    char x[40], data[40], reg[40];
    int a = 0, b = 0, i, j, result = 0, temp, c, d;
    clrscr();
    printf("\t\tOUTPUT\n");
    printf("I:10\n");
    printf("J:15\n");
    printf("RESULT(I+J):25\n");

    f = fopen("res.cpp", "r");

    while (!feof(f))
    {
        fscanf(f, "%s", x);

        if (strcmp(x, "STOP") == 0)
            exit(0);
        else if (strcmp(x, "MVI") == 0)
        {
            fscanf(f, "%s%s", reg, data);
            if (strcmp(reg, "AREG,") == 0)
                a = atoi(data);
            else if (strcmp(reg, "BREG,") == 0)
                b = atoi(data);
        }
        else
        {
            if (strcmp(x, "ADD") == 0)
            {
                result = a + b;
                printf("\n\ti=%d", a);  // Print i=10
                printf("\n\tj=%d", b);  // Print j=15
                printf("\nResult(i+j)=%d", result);  // Print result(i+j)=25
            }
            else if (strcmp(x, "SUB") == 0)
            {
                result = a - b;
                printf("\n\tI:%d", a);
                printf("\n\tJ:%d", b);
                printf("\nResult(I-J):%d", result);
            }
            else if (strcmp(x, "MUL") == 0)
            {
                result = a * b;
                printf("\nI:%d", a);
                printf("\nJ:%d", b);
                printf("\nresult(I*J):%d", result);
            }
            getch();
        }
    }
    fclose(f);
}
