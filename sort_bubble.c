
#include <stdio.h>

void printArr(int*, int);
void bubbleSort(int*, int);

int main() {
    int arr[5] = {12,4,67,2,1};
    int size = sizeof(arr)/sizeof(int);
    printArr(arr, size);
    bubbleSort(arr, size);
    printArr(arr, size);
    return 0;
}

void printArr(int* _arr, int _size) {
    for (int i = 0; i < _size; i++) {
        printf("%d ", _arr[i]);
    }
    printf("\n");
}
void bubbleSort(int* _arr, int _size) {
    int temp;
    int isSorted = 0;     // initializing is sorted
    for (int i = 0; i < _size - 1; i++) { 
        isSorted = 1;     // let array be sorted

        for (int j = 0; j < _size - i - 1; j++) {
            if (_arr[j] > _arr[j + 1]) {    // if program gets inside this if condition...
                isSorted = 0;               //  array is not already sorted
                int temp = _arr[j];
                _arr[j] = _arr[j + 1];
                _arr[j + 1] = temp;
            }
        }
        
        if (isSorted)   // if array is sorted -> break
            break;      // come out of the program
    }
}