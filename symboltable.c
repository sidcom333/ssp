# include<stdio.h>
# include<conio.h>
# include<string.h>

struct syt
{
    char v[10], t[10];
    int s;
} st[50];

char *tt[] = {"int", "float", "long", "double", "short"};
int vt[5] = {2, 4, 6, 8, 1};

FILE *fp;

void main()
{
    char *fn, u[20], t[20], s[100], *p;
    int i = 0, j, k, l, y, sp = 0;

    clrscr();

    printf("\n Enter file name: ");
    scanf("%s", fn);

    printf("\n The given file name is %s", fn);

    fp = fopen(fn, "r");

    printf("\nSymbol table maintenance");
    printf("\n\tVariable\tType\t\tsize\n");

    while (!feof(fp))
    {
        fscanf(fp, "%s", s);
        for (i = 0; i < 5; i++)
        {
            if (strcmp(s, tt[i]) == 0)
            {
                fscanf(fp, "%s", s);
                p = strchr(s, ',');
                if (p)
                {
                    j = 0;
                    while (s[j] != ',')
                        j++;
                    for (k = 0; k < j; k++)
                        t[k] = s[k];
                    t[k] = '\0';
                    printf("\n%10s\t%10s\t%10d", t, tt[i], vt[i]);
                    strcpy(st[sp].v, t);
                    strcpy(st[sp].t, tt[i]);
                    st[sp].s = vt[i];
                    sp++;
                kjk:
                    y = j;
                    j++;
                    while (s[j] != '\0' && s[j] != ',')
                        j++;
                    for (l = y; l < j; l++)
                        t[l - 2] = '\0';
                    printf("\n%10s\t%10s\t%10d", t, tt[i], vt[i]);
                    strcpy(st[sp].t, tt[i]);
                    st[sp].s = vt[i];
                    sp++;
                    if (s[j] == ',')
                        goto kjk;
                }
                else
                {
                    printf("\n%10s\t%10s\t%10d", s, tt[i], vt[i]);
                    strcpy(st[sp].v, t);
                    strcpy(st[sp].t, tt[i]);
                    st[sp].s = vt[i];
                }
            }
        }
    }

    fclose(fp);

    for (i = 0; i < sp; i++)
        strcpy(t, st[i].v);

    k = 0;
    for (j = 0; j < strlen(t); j++)
    {
        if (t[i] != ',')
        {
            u[k] = u[j];
            k++;
        }
        u[k] = '\0';
        strcpy(st[i].v, u);
    }

    for (i = 0; i < sp - 2; i++)
        for (j = i + 1; j < sp; j++)
        {
            if (strcmp(st[i].v, st[j].v) == 0)
                printf("\n\nMultiple Declaration for %s", st[i].v);
        }

    getch();
}
