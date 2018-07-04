//
//  main.cpp
//  CSE100_Lab1
//
//  Created by charles tolentino on 1/18/18.
//  Copyright © 2018 Chazt. All rights reserved.
//

#include <iostream>
using namespace std;

void insertionSort(int* inArr, int inSize) {
    int j, key = 0;
    
    for (int i = 1; i < inSize; i++) {
        key = inArr[i];
        j = i - 1;
        while (j >= 0 && inArr[j] > key) {
            inArr[j+1] = inArr[j];
            j = j - 1;
        }
        inArr[j+1] = key;
        
        //print
        for (int k = 0; k < i + 1; k++)
            cout << inArr[k] << ";";
        cout << endl;
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
    
    insertionSort(Sequence, arraySize);
    
    return 0;
}

