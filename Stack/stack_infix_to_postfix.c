#include <stdio.h>
#include <string.h>
#define MAX 100
// initializing three character arrays stack to store operator,infix to get input from user,postfix to store our result
char stack[100];
char infix[100];
char postfix[100];
// initialzing a top variable to -1 to indicate an empty stack
int top = -1;

// function to push an element into the stack
void push(char ch)
{
    // addressing stack over flow condition
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}
// function to pop out an element from the stack and return it to the user
char pop()
{
    // addresssing stack under flow condition
    if (top == -1)
    {
        printf("\nStack Underflow");
        return '\0';
    }
    else
    {
        char pop;
        pop = stack[top];
        top--;
        return pop;
    }
}
// function to check the precedence of a specific operator and return it to the user
int precedence(char op)
{
    switch (op)
    {
    // power operator has the highest precedence so return 3
    case '^':
        return 3;
    // * and / has the next higher precedence so return 2
    case '*':
    case '/':
        return 2;
    // + and - has the next higher precedence so return 1
    case '+':
    case '-':
        return 1;
    // apart from any of the above operator is encountered set as 0
    default:
        return 0;
    }
}

// function to create a postfix expression from an infix expression
void in_to_post()
{
    // declaring two variables i -> used in for loop and j-> used in placing things in postfix char array
    int i, j = 0;
    // declaring two characters symbol to place the current value of infix[i] and next used in switch case(check⭐)
    char symbol, next;
    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        //a switch case for addressing various symbols
        switch(symbol){
            //incase of a left paren.. just push it into the stack
            case '(':   
                push(symbol);
                break;
            //⭐incase of a right paren.. pop the element from stack and assign to next and check it is not equal to left paren.. if true put every next to postfix in subsequent positions(that's why i use j++)
            case ')':
                while((next=pop()) != '(')
                    postfix[j++] = next;
                break;
            //same way to address +,-,/,*,^
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                //if opreator in symbol is lower priority than the element in the top of stack and the stack is not empty
                //push all the elements to postfix until the top element in stack have lower priority than symbol
                while(top!= -1 && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++]=pop();
                //finally push that operator to stack
                push(symbol);
                break;
            //by default like any operands(5,A,etc.,) put them in postfix array
            default:
                postfix[j++]=symbol;
        }
    }
    //in some cases the stack may contain some operators left so put them all into the postfix array and delimit it by adding '\0'
    while(top != -1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
void main()
{
    printf("Enter an infix expression:");
    gets(infix);
    in_to_post();
    // printing postfix expression
    printf("Postfix Expression: ");
    for (int i = 0; i < postfix[i]!='\0'; i++)
    {
        printf("%c", postfix[i]);
    }
}