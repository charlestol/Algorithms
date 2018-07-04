//
//  main.cpp
//  CSE100_Lab3
//
//  Created by charles tolentino on 2/15/18.
//  Copyright © 2018 Chazt. All rights reserved.
//

#include <iostream>
#define intLim 2147483646
using namespace std;

int FindMaxCrossingSubArray(int* A, int low, int mid, int high) {
    int leftSum = -1*intLim;
    int rightSum = -1*intLim;
    int sum = 0;
    //int* tuple = new int[3];
    
    for(int i = mid; i >= low; i--) {
        sum = sum + A[i];
        if(sum > leftSum) {
            leftSum = sum;
           // maxLeft = i;
        }
    }
    sum = 0;
    for(int j = mid + 1; j <= high; j++) {
        sum = sum + A[j];
        if(sum > rightSum) {
            rightSum = sum;
            //maxRight = j;
        }
    }
    return leftSum + rightSum;
}

int FindMaxSubArray(int* A, int low, int high) {
    if (high == low){
        return A[low];
    }
    int mid = (low + high)/2;
    int leftSum = FindMaxSubArray(A, low, mid);
    int rightSum = FindMaxSubArray(A, mid+1, high);
    int crossSum = FindMaxCrossingSubArray(A, low, mid, high);
    
    if(leftSum >= rightSum && leftSum >= crossSum)
        return leftSum;
    else if(rightSum >= leftSum && rightSum >= crossSum)
        return rightSum;
    else
        return crossSum;
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
    
    cout << FindMaxSubArray(Sequence, 0, arraySize-1);
    return 0;}
