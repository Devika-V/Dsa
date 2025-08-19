#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push character onto stack
void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop character from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

int main() {
    char str[MAX], reversed[MAX];
    int i;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Push all characters onto stack
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop characters to reverse the string
    for (i = 0; top >= 0; i++) {
        reversed[i] = pop();
    }
    reversed[i] = '\0';

    printf("Reversed string: %s\n", reversed);

    return 0;
}

