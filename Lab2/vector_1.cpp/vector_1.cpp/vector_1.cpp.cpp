// vector_1.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void printMemVec(vector <int> & vec, int size) {
    printf("Vector = Each int is worth %lu bytes\n", sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("Value :%i at Memory Location: \n", vec[i]);
    }
}

void incVecBy10(vector <int> & vec, int size) {
    for (int i = 0; i < size; i++) {
        vec[i] += 10;
    }
}


int main()
{
    const int SIZE = 5;
    vector <int> vec1;

    for (int i = 0; i < SIZE; i++) {
        vec1.push_back(100+i);
    }

    printf("Before Increment -------------\n");
    printMemVec(vec1, vec1.size());
    incVecBy10(vec1, vec1.size());
    printf("After Increment --------------\n");
    printMemVec(vec1, vec1.size());

    vec1.pop_back();
    printf("After Pop ---------------------\n");
    printMemVec(vec1, vec1.size());
    vec1.push_back(101);
    vec1.push_back(102);
    printf("After Push --------------------\n");
    printMemVec(vec1, vec1.size());
    return 0;
}


yummy

