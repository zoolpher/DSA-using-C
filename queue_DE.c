#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int DEqueue[MAX_SIZE];
int rare = -1, front = -1;

void initialize();
void display_elem();
void insert_front();
void insert_rare();
void delete_front();
void delete_rare();

int main() {
    int ch;
    while(1) {
        printf("\n1- to initialize.\n");
        printf("2- to display.\n");
        printf("3- to insert in front.\n");
        printf("4- to insert in rare.\n");
        printf("5- to delete from front.\n");
        printf("6- to delete from rare.\n");
        printf("0- to EXIT.\n");
        printf("Enter your choice:\t");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                initialize();
                break;
            case 2:
                display_elem();
                break;
            case 3:
                insert_front();
                break;
            case 4:
                insert_rare();
                break;
            case 5:
                delete_front();
                break;
            case 6:
                delete_rare();
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

void initialize() {
    if (rare == MAX_SIZE - 1 && front == -1)
        printf("\nQueue is full.");
    else {   
        int n;
        printf("Enter an element: ");
        scanf("%d", &n);
        rare ++;
        DEqueue[rare] = n;
    }
}

void display_elem() {
    if (rare == -1) 
        printf("\nQueue Underflow.");
    else {
        printf("\nElements in the queue are: ");
        for(int i = rare; i > front; i--) {
            printf("%d\t", DEqueue[i]);
        }
    }
}

void insert_rare() {
    if (rare == MAX_SIZE - 1)
        printf("\nQueue is full to insert in rare.");
    else {
        int n;
        printf("Enter an element: ");
        scanf("%d", &n);
        rare ++;
        DEqueue[rare] = n;
    }
}
void insert_front() {
    if (front == -1)
        printf("\nQueue is full to insert in front.");
    else {
        int n;
        printf("Enter an element: ");
        scanf("%d", &n);
        DEqueue[front] = n;
        front--;
    }
}
void delete_front() {
    if (rare == -1) 
        printf("\nEmpty queue to delete from front.");
    else {
        front ++;
        int del = DEqueue[front];
        printf("\nDeleted element is: %d", del);
        if (front == rare) {
            front = -1;
            rare = -1;
        }
    }
}
void delete_rare() {
    if(rare == -1) 
        printf("\nEmpty queue to delete from front.");
    else {
        int del = DEqueue[rare];
        rare --;
        printf("\nDeleted element is: %d", del);
        if (front == rare) {
            front = -1;
            rare = -1;
        }
    }    
}