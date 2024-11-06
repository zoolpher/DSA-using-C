#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* add;
}; struct node* start = NULL, *new, *prev, *temp, *next;

void create();
void insert_start();
void insert_last() ;
void insert_middle();
void display();
void delete_first();
void delete_last();
void delete_mid();
void search();

int main() {
    int ch;
    while(1) {
        printf("\n1- to create.\n");
        printf("2- to display.\n");
        printf("3- to insert at start.\n");
        printf("4- to insert at last.\n");
        printf("5- to insert in middle.\n");
        printf("6- to delete first element.\n");
        printf("7- to delete last element.\n");
        printf("8- to delete middle element.\n");
        printf("9- to search an element.\n");
        printf("0- to exit the program.\n");
        printf("Enter your choice:\t");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_start();
                break;
            case 4:
                insert_last();
                break;
            case 5:
                insert_middle();
                break;
            case 6:
                delete_first();
                break;
            case 7:
                delete_last();
                break;
            case 8:
                delete_mid();
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


void create() {
    int k;
    printf("Enter a number: ");
    scanf("%d", &k);
    start = (struct node*)(malloc(sizeof(struct node)));
    start -> data = k;
    start -> add = NULL;  
}

void insert_start() {
    int n;
    printf("Enter a number to insert at start: ");
    scanf("%d", &n);
    new = (struct node*)(malloc(sizeof(struct node)));
    if (start == NULL) {
        printf("Linked list was empty");
        new -> data = n;
        new -> add = NULL;
        start = new;
    }
    else {
        new -> data = n;
        new -> add = start;
        start = new;
    }
}

void insert_last() {
    int n;
    printf("Enter an element: ");
    scanf("%d", &n);
    if (start == NULL) {
        printf("Empty linked list");
        start = (struct node*)(malloc(sizeof(struct node)));
        start -> data = n;
        start -> add = NULL;
    }
    else {
        temp = start;
        while (temp -> add != NULL) {
            temp = temp -> add;
        }
        new = (struct node*)(malloc(sizeof(struct node)));
        new -> data = n;
        temp -> add = new;
        new -> add = NULL;
    }
}

void insert_middle() {
    int pos, n;
    // printf("%d", start -> data);     // test code
    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("Enter the value: ");
    scanf("%d", &n);
    if (start == NULL) {
        start = (struct node*)(malloc(sizeof(struct node)));
        start -> data = n;
        start -> add = NULL;
    }
    else { 
        new = (struct node*)(malloc(sizeof(struct node)));
        new -> data = n;
        temp = start;
        int i = 1;
        while (temp -> add != NULL) { 
            if (i == pos-1)
                new -> add = temp -> add;
                temp -> add = new;
                break;
            i += 1;
            temp = temp -> add;
        }
        
        // if (temp -> add != NULL) {
        //     new -> add = temp -> add;
        //     temp -> add = new;
        // }
        // else {
        //     temp -> add = new;
        //     new -> add = NULL;
        // }
    }
}

void display() {
    if (start == NULL)
        printf("Empty linked list\n");
    else {
        temp = start;
        while (temp != NULL) {
            printf("%d -> ", temp -> data);
            temp = temp -> add;
        }
    }
    printf("NULL\n");
}


void delete_first() {
    if (start == NULL) 
        printf("Empty list.\n");
    else {
        temp = start;
        start = temp -> add;
        free(temp);
    }
    display();
}

void delete_last() {
    if (start == NULL)
        printf("Empty List.\n");
    else {
        temp = start;
        while (temp -> add -> add != NULL) {
            temp = temp -> add;
        }
        free(temp -> add -> add);
        temp -> add = NULL;
    }
    display();
}


void delete_mid() {
    if (start == NULL) 
        printf("\nEmpty list.\n");
    else {
        int pos;
        printf("Enter the position to be deleted: ");
        scanf("%d", &pos);
        if (pos == 1) {
            temp = start;
            start = temp -> add;
            free(temp); 
            
        }
        else {
            int i = 1;
            temp = start;
            while (temp -> add != NULL) {
                if (i == pos-1) {
                    temp = temp -> add -> add;
                    free(temp -> add);  
                }
                temp = temp -> add;
                i += 1;
                
            }
        }
    }
}

void search() {
    if (start == NULL) 
        printf("\nEmpty list.\n");
    else {
        int elem, pos;
        printf("\nEnter the element to be searched: ");
        scanf("%d", &elem);
        temp = start;
        pos = 1;
        while (temp -> add != NULL) {
            if (temp -> data == elem) {
                printf("\nElement found at position %d", pos);
                break;
            }
            temp = temp -> add;
            pos++;
        }
        printf("\nElement not found.");
    }
}
