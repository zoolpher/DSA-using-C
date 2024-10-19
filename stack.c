
#include <stdio.h>

#define MAX 5

int stk[MAX];
int top = -1;

void push();
void pop();
void display();

int main() {
    // printf("\n1- to create.\n");
    int ch;
    while(1) {
        printf("\n1- to insert.\n");
        printf("2- to delete.\n");
        printf("3- to display.\n");
        printf("0- to exit the program.\n");
        printf("Enter your choice:\t");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("Please enter a valid choice.");
                break;
        }
    }
    return 0;
}

void push() {
    if (top == MAX - 1) 
        printf("\nQverflow.");
    else {
        int n;
        printf("\nEnter the element to insert:\t");
        scanf("%d", &n);
        top ++;
        stk[top] = n;
    }
}

void pop() {
    if (top == -1) 
        printf("\nUnderflow.");
    else {
        int n;
        int temp = stk[top];
        top --;
        printf("\nDeleted element is %d.\n", temp);
    }
}

void display() {
    if (top == -1) 
        printf("\nUnderflow.");
    else {
        for (int i = top; i >= 0; i--) {
            printf("%d\t", stk[i]);
        } 
    } 
}
