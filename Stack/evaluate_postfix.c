#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 100

char postfix[100];
float result_stack[100];
int top = -1;

int is_operator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

float evaluate_postfix(char *postfix) {
    for (int i = 0; i < strlen(postfix); i++) {
        char val = postfix[i];
        if(val == ' ')
            continue;
        if (is_operator(val)) {
            float val2 = result_stack[top--];
            float val1 = result_stack[top--];
            switch (val) {
                case '+':
                    result_stack[++top] = val1 + val2;
                    break;
                case '-':
                    result_stack[++top] = val1 - val2;
                    break;
                case '*':
                    result_stack[++top] = val1 * val2;
                    break;
                case '/':
                    result_stack[++top] = val1 / val2;
                    break;
                case '^':
                    result_stack[++top] = pow(val1, val2);
                    break;
            }
        } else {
            top++;
            result_stack[top] = (float) (val - '0');
        }
    }
    return result_stack[top];
}

void main() {
    printf("Enter your Postfix Expression:");
    gets(postfix);
    float result = evaluate_postfix(postfix);
    printf("Result: %.2f\n", result);

}
