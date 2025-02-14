// array_1.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printMemArr(int* arr, int size) {
    printf("Array - Each int is worth %lu bytes\n", sizeof(arr[0]));
    for (int i = 0; i < size; i++) {
        printf("Value :%i at Memory Location: %p\n", arr[i], arr + i);
    }
}

void incArrBy10(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 10;
    }
}

int main()
{

    const int SIZE = 5;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = 100 + i;
    }

    printf("Before-------------\n");
    printMemArr(arr, SIZE);
    incArrBy10(arr, SIZE);
    printf("After--------------\n");
    printMemArr(arr, SIZE);
    return 0;
}
