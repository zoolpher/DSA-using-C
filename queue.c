#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int rare = -1, front = 0;

void insert_elem();
void delete_elem();
void desplay_elem();

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
                insert_elem();
                break;
            case 2:
                delete_elem();
                break;
            case 3:
                display_elem();
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

void insert_elem() {
    int n;
    if (rare == MAX_SIZE)
        printf("Over flow.\n");
    else {
        printf("Enter the element u want to isnert:\t");
        scanf("%d", &n);
        // rare ++;
        // queue[rare] = n;   
        queue[++rare] = n; 
    }
}
void delete_elem() {
    if (rare < front)
        printf("Underflow.\n");
    else {
        int n = queue[front];
        printf("The deleted element is: %d", n);
        front ++;
    } 
}
void display_elem() {
    if (rare < front) 
        printf("Queue Underflow.\n");
    else {
        printf("Elements in the queue are: ");
        for(int i = rare; i>= front; i--) {
            printf("%d\t", queue[i]);
        }
    } 
}