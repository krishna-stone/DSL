#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

char stack[100];
int top = -1;

void push(char x) {
    if(top == MAX -1) return;
    stack[++top] = x;
}

char pop() {
    if (top == -1) return '\0';
}

char peek() {
    if(top == -1) return '\0';
    return stack[top];
}

bool isEmpty() {
    return (bool)(top == -1);
}

int precedence(char x){
    if(x == '^') return 3;
    if(x == '*' || x == '/') return 2;
    if(x == '-' || x == '+') return 1;
    return 0;
}

void infixtoPostfix(char *infix){
    char postfix[MAX];
    int i = 0 ,j = 0;
    while(infix[i] != '\0'){
    	char x = infix[i];
    	
    }
}

int main() {
	infixtoPostfix()
}
