#include <stdio.h>
#include <conio.h>

typedef struct
{
    int input[2];
} state;

void readtt(state *states, int nstates, int ninps)
{
    int state, inp;
    printf("Enter the state transition:\n");
    for (state = 0; state < nstates; state++)
        for (inp = 0; inp < ninps; inp++)
        {
            printf("(state:%d,%d):", state, inp);
            scanf("%d", &states[state].input[inp]);
        }
}

void dfasimul(state *states, int nstates, char *inpstr)
{
    int i, start;
    start = 0;
    for (i = 0; inpstr[i] != '\0'; i++)
    {
        start = states[start].input[inpstr[i] - '0'];
    }
    if (start == -1)
    {
        printf("DFA halted");
        return;
    }
    else if (start == nstates - 1)
        printf("String is accepted");
    else
        printf("String is not accepted");
}

int main()
{
    state states[100];
    int nstates, ninps;
    char inpstr[20];

    printf("\n\t\t\t SIMULATION OF DFA");
    printf("\n\t\t\t *****************");
    printf("\nEnter the no. of states: ");
    scanf("%d", &nstates);
    printf("Enter the no. of inputs: ");
    scanf("%d", &ninps);
    readtt(states, nstates, ninps);
    printf("\nInitial state: 0\nFinal state: %d", nstates - 1);
    printf("\n\nEnter the string: ");
    scanf("%s", inpstr);
    dfasimul(states, nstates, inpstr);

    return 0;
}
