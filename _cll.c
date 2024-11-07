#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *add;
}; struct Node* start = NULL, *new, *temp;

void create();
void display();

void insert_start();  // insertion section
void insert_mid();
void insert_end();

void delete_start();  // deletion section
void delete_mid();
void delete_end();

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
                insert_end();
                break;
            case 5:
                insert_mid();
                break;
            case 6:
                delete_start();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_mid();
                break;
            case 9:
                search();
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
    if (start != NULL)
        printf("Circular linked list already created.\n");
    else {
        int n;
        printf("Enter the first element: ");
        scanf("%d", &n);
        start = (struct Node*)(malloc(sizeof(struct Node)));
        start -> data = n;
        start -> add = start;  //*** 
    }
}

void display() {
    if (start == NULL) 
        printf("Empty Circular Linked List.\n");
    else {
        temp = start;
        do {
            printf("%d -> ", temp -> data);
            temp = temp -> add;
        } while (temp != start);   //
        printf("NULL\n");
    }
}

void insert_start() {
    if (start == NULL) 
        printf("Circular Linked List not created.\n");
    else {
        int n;
        printf("Enter an element: ");
        scanf("%d", &n);
        temp = start;
        do {
            temp = temp -> add;
        } while (temp -> add != start);
        new = (struct Node*)(malloc(sizeof(struct Node)));
        new -> data = n;
        new -> add = temp -> add; 
        temp -> add = new;
        start = new;
    }
}

void insert_end() {
    if (start == NULL)
        printf("List not created.\n");
    else {
        int n;
        printf("Enter an element: ");
        scanf("%d", &n);
        new = (struct Node*)(malloc(sizeof(struct Node)));
        temp = start;
        do {
            temp = temp -> add;
        } while (temp -> add != start);
        new -> data = n;
        new -> add = start;
        temp -> add = new;
    }
}

void insert_mid() {
    if (start == NULL)
        printf("Linst not created.\n");
    else {
        int n, pos, counter;
        printf("\nEnter the position of new Node: ");
        scanf("%d", &pos);    // let pos = n
        new = (struct Node*)(malloc(sizeof(struct Node)));
        
        if (pos == 1) {
            printf("You r at starting of list\n");
            insert_start();
        }
        else {
            temp = start;
            counter = 1;
            while (counter < pos - 1 && temp -> add != start) {
                temp = temp -> add;
                counter ++;   // exit at (n-1)
            };
            
            if (counter < pos - 1) {
            //  (n-1) !< (n-1)   
                printf("*Invalid Position*");
                return; 
            }
            // else ((pos-1) = counter = (n-1))
            printf("Enter the element: ");
            scanf("%d", &n);
            new -> data = n;
            new -> add = temp -> add;
            temp -> add = new;
        }
    }
}

void delete_start() {
    if (start == NULL)
        printf("List not created.\n");
    else if (start == start -> add) { // add of start is start for one Node
        free(start);
        start = NULL;
    }
    else {
        temp = start;
        while (temp -> add != start) {
            temp = temp -> add; 
        }
        start = start -> add;
        free(temp -> add); 
        temp -> add = start;
    }
}

void delete_end() {
    if (start == NULL)
        printf("List not created.");
    else if (start == start -> add) {
        free(start);
        start = NULL;
    }
    else {
        temp = start;
        while (temp -> add -> add != start) {
            temp = temp -> add;
        }
        free(temp -> add);        
        temp -> add = start;
    }
}

void delete_mid() {
    if (start == NULL)
        printf("List not created.");
    else {
        int pos, counter;
        printf("Enter the position on Node u want to delete: ");
        scanf("%d", &pos);
        if (pos == 1) 
            delete_start();
        else {
            temp = start;
            counter = 1;
            while (counter < pos - 1 && temp -> add != start) {
                temp = temp -> add;
                counter ++;
            }
            if (counter < pos - 1 || temp -> add == start) {
                printf("**Not enough Nodes.**\n");
            }
            else {
                struct Node* temp2 = temp -> add;
                temp -> add = temp2 -> add;
                free(temp2);
            }
        }
    }
}

void search() {
    if (start == NULL)
        printf("List not created.");
    else {
        temp = start;
        int elem;
        printf("\nEnter an element to search: ");
        scanf("%d", &elem);
        int counter = 1;
        do {
            if (temp -> data == elem) {
                printf("%d found at position: %d.\n", elem, counter);
                return;
            }
            temp = temp -> add;
            counter ++;
        } while (temp != start);
        printf("%d not present in the List.", elem);
    }
}