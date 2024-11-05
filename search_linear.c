#include <stdio.h>

// works only for sorted array

int linear_search(int arr[], int size, int elem);

int main() {
    int arr[] = {12, 23, 34, 45, 56, 67, 78};
    int size = sizeof(arr) / sizeof(int);
    int elem;
    printf("Enter the element u want to search: ");
    scanf("%d", &elem);
    int searched_pos = linear_search(arr, size, elem);
    
    if (searched_pos == -1) 
        printf("Element not present in the array.");
    else 
        printf("Element found at poistion %d", searched_pos + 1);
    return 0;
}

int linear_search(int arr[], int size, int elem) {
    for (int i = 0; i <= size; i++) {
        if (arr[i] == elem) 
            return i;
    }
    return -1;
}