//
//  main.cpp
//  Lab4.2
//
//  Created by charles tolentino on 3/1/18.
//  Copyright © 2018 Chazt. All rights reserved.
//

#include <iostream>
using namespace std;

int Partition(int* Arr, int p, int r) {
    int x = Arr[r];
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(Arr[j] <= x) {
            i++;
            swap(Arr[i], Arr[j]);
        }
    }
    swap(Arr[i+1], Arr[r]);
    return i + 1;
}

int Rand_Part(int* Arr, int p, int r) {
    int i = rand() % (r - p + 1) + p;
    swap(Arr[r], Arr[i]);
    return Partition(Arr, p, r);
}

void Rand_Quicksort(int* Arr, int p, int r) {
    int q;
    if(p < r) {
        q = Rand_Part(Arr, p, r);
        Rand_Quicksort(Arr, p, q-1);
        Rand_Quicksort(Arr, q+1, r);
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
    
    Rand_Quicksort(Sequence, 0, arraySize-1);
    
    for(int i = 0; i < arraySize; i++)
        cout << Sequence[i] << ";";
    
    // Free allocated space
    delete[] Sequence;
    
    return 0;
}
