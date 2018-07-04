//
//  main.cpp
//  CSE100_Lab2
//
//  Created by charles tolentino on 1/29/18.
//  Copyright © 2018 Chazt. All rights reserved.
//

#include <iostream>
#define intLim 2147483647
using namespace std;

void merge(int* Arr, int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1+1];
    int R[n2+1];
    
    for(i = 0; i < n1; i++)
        L[i] = Arr[low + i];
    for(j = 0; j < n2; j++)
        R[j] = Arr[mid + 1 + j];
    
    L[n1] = intLim;
    R[n2] = intLim;
    
    i = 0;
    j = 0;
    
    for(k = low; k <= high; k++) {
        if(L[i] <= R[j])
            Arr[k] = L[i++];
        else
            Arr[k] = R[j++];
    }
}

void mergeSort(int *Arr, int low, int high) {
    int mid;
    
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(Arr, low, mid);
        mergeSort(Arr, mid + 1, high);
        merge(Arr, low, mid, high);
    }
}
int main(int argc, const char * argv[]) {
    int* Sequence;
    int arraySize = 1;
    
    // Get the size of the sequence
    cin >> arraySize;
    Sequence = new int[arraySize];
    
    // Read the sequence
    for(int i=0; i<arraySize; i++)
        cin >> Sequence[i];
    
    mergeSort(Sequence, 0, arraySize-1);
    
    for(int i = 0; i < arraySize; i++)
        cout << Sequence[i] << ";";
    return 0;
}

