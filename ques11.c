// A program to simulate Bankers Algorithm for Deadlock Prevention

#include <stdio.h>

void main()
{
    int cl[10][10], al[10][10], av[10], i, j, m, n, ne[10][10], flag = 0;
    clrscr();

    printf("\nEnter the matrix");
    scanf("%d %d", &m, &n);

    printf("\nEnter the claim matrix:");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cl[i][j]);
        }
    }

    printf("\nEnter allocated matrix:");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &al[i][j]);
        }
    }

    printf("\nThe need matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            ne[i][j] = cl[i][j] - al[i][j];
            printf("\t%d", ne[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter available matrix:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &av[i]);
    }

    printf("Claim matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%d", cl[i][j]);
        }
        printf("\n");
    }

    printf("\nAllocated matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%d", al[i][j]);
        }
        printf("\n");
    }

    printf("Available matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", av[i]);
    }

    for (i = 0; i < m; i++)
    {
        flag = 1;
        for (j = 0; j < n; j++)
        {
            if (av[j] < ne[i][j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    if (flag == 1)
        printf("\nSafe State\n");
    else
        printf("\nUnsafe State\n");

    getch();
}
