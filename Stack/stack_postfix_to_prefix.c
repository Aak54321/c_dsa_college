#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX][MAX], str[MAX], pop1[MAX], pop2[MAX];
char postfix[MAX];
int top = -1;
void push(char *str)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        strcpy(stack[top], str);
    }
}
void pop(char *pop1)
{
    if (top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        strcpy(pop1, stack[top]);
        top--;
    }
}
void pope()
{
    printf("Enter your Postfix Expression:");
    gets(postfix);
    for (int i = 0; i < strlen(postfix); i++)
    {
        char symbol[2] = {postfix[i], '\0'};
        switch (postfix[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            pop(pop1);
            pop(pop2);
            strcpy(str, symbol);
            strcat(str, pop2);
            strcat(str, pop1);
            push(str);
            break;
        default:
            push(symbol);
        }
    }
}
void main()
{
    pope();
    printf("Your Prefix Expression: %s", stack[0]);
}