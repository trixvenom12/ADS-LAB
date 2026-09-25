#include <stdio.h>

int main() {
    int stack[50];
    int top = -1;
    int n, element, i,popCount;

    printf("Enter the size of stack: ");
    scanf("%d", &n);

    
    printf("\nEnter %d elements to push:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &element);

        if (top == n - 1) {
            printf("Stack Overflow\n");
            break;
        }

        top++;
        stack[top] = element;
    }

  
    printf("\nStack after PUSH:\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    printf("\nHow many elements do you want to pop? ");
    scanf("%d", &popCount);

    for (i = 0; i < popCount; i++) {

        if (top == -1) {
            printf("Stack Underflow\n");
            break;
        }

        printf("%d popped from stack\n", element);
        top--;
    }

    return 0;
}

