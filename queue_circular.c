 
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int cq[MAX_SIZE];
int rare = -1, front = -1;

void insert_elem();
void delete_elem();
void display_elem(); 

int main() {
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
    if ((rare+1) % MAX_SIZE == front) 
        printf("Overflow.\n");
    else {
        int n;
        printf("Enter an element: ");
        scanf("%d", &n);
        if(rare == -1 && front == -1) {
            rare ++;
            front ++;
        }
        else 
            rare = (rare + 1) % MAX_SIZE;
        cq[rare] = n;
    }
}
void delete_elem() {
    int n;
    if (rare == -1 && front == -1) 
        printf("Empty queue.\n");
    else {
        n = cq[front];
        if (front == rare) {
            front == -1;
            rare == -1;
        }
        else 
            front = (front + 1) % MAX_SIZE;
        printf("Deleted elem is: %d", n);
    }
}
void display_elem() {
    if (rare == -1 && front == -1) 
        printf("Empty queue\n");
    else {
        // int i = rare;
        for(int i = front; i != rare; i = (i + 1) % MAX_SIZE) {
            printf("%5d", cq[i]);
        }
        printf("%5d", cq[i]);
    }
}
 