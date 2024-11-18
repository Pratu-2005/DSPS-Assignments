#include <stdio.h>
#define STACK_SIZE 30  

char stack[STACK_SIZE];
int top = -1;

void push(char x) {
    if (top < STACK_SIZE - 1) {
        stack[++top] = x;
    } else {
        printf("stack overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("stack underflow\n");
        return '\0';  
    }
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return -1;
    }
}

void infixToPostfix(char infix[]) {
    char c;
    int i = 0;
    printf("The Postfix Expression is: ");
    
    while (infix[i] != '\0') {
        c = infix[i];
        
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            printf("%c", c);
        }
        
        else if (c == '(') {
            push(c);
        }
        
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", pop());
            }
            if (top != -1) {
                pop();  
            }
        }
        
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
        i++;
    }
    
    
    while (top != -1) {
        printf("%c", pop());
    }
    
    printf("\n");
}

int main() {
    char infix[STACK_SIZE];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}