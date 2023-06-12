#include<stdio.h>
#include<string.h>
#define MAX 100
char prefix[MAX],infix[MAX],stack[MAX];
int top = -1;
void push(char ch){
    if(top == MAX - 1){
        printf("\nStack Overflow");
    }
    else{
        top++;
        stack[top]=ch;
    }
}
char pop(){
    if(top == -1){
        printf("\nStack Underflow");
        return '\0';
    }
    else{
        char ch = stack[top];
        top--;
        return ch;
    }
}
int precedence(char op){
    switch(op){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
void in_to_pre(){
    int i,j=0;
    char symbol,next;
    //⭐Change no.1 traverse infix in a reverse manner
    for(int i=strlen(infix)-1;i>=0;i--){
        symbol=infix[i];
        switch(symbol){
            //⭐Change no.2 swap the left and right parenthesis did in previous conversion
            case')':
                push(symbol);
                break;
            case '(':
                while((next=pop()) != ')')
                    prefix[j++]=next;
                    break;
            case'+':
            case'-':
            case'*':
            case'/':
            case'^':
                //⭐Change no. 3 don't use equal because equal priority can be stacked together
                while(top != -1 && precedence(stack[top]) > precedence(symbol))
                    prefix[j++]=pop();
                push(symbol);
                break;
            default:
                prefix[j++]=symbol;
                break;
        }
    }
    while(top!= -1){
        prefix[j++]=pop();
    }
    prefix[j]='\0';
}
void main(){
    printf("Enter your Infix Expression:");
    gets(infix);
    in_to_pre();
    printf("Your Prefix Expression is:");  
    //⭐Print the expression in reverse manner
    for(int i=strlen(prefix)-1;i>=0;i--){
        printf("%c",prefix[i]);
    }
}