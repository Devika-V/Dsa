#include <stdio.h>
#define MAX 100

int stack[MAX], tempStack[MAX];
int top = -1, tempTop = -1;

// Push to main stack
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop from main stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

// Push to temp stack
void tempPush(int value) {
    tempStack[++tempTop] = value;
}

// Pop from temp stack
int tempPop() {
    return tempStack[tempTop--];
}

// Peek top of temp stack
int tempPeek() {
    return tempStack[tempTop];
}

// Sort the stack
void sortStack() {
    while (top >= 0) {
        int temp = pop();

        while (tempTop >= 0 && tempPeek() > temp) {
            push(tempPop());
        }

        tempPush(temp);
    }

    // Copy back to original stack
    while (tempTop >= 0) {
        push(tempPop());
    }
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Sorted Stack (Top to Bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    sortStack();
    display();

    return 0;
}
