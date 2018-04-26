//
//  main.cpp
//  CSELab5
//
//  Created by charles tolentino on 3/1/18.
//  Copyright © 2018 Chazt. All rights reserved.
//

#include <iostream>
#include <vector>
#define length 10
using namespace std;

vector<vector<int>> CountingSort(vector<vector<int>> container, vector<int> tempVec) {
    //Counting vector C
    vector<int> C(length,0);
    vector<vector<int>> newVec;
    newVec.resize(tempVec.size());
    
    for(int i = 0; i < tempVec.size(); i++)
        C[tempVec[i]]++;
    for( int i = 1; i < C.size(); i++)
        C[i] += C[i-1];
    for (int i = 0; i < tempVec.size(); i++)
        newVec[i].resize(length);
    for(int i = tempVec.size()-1; i >= 0; i--) {
        swap(newVec[C[tempVec[i]]-1],container[i]);
        C[tempVec[i]] -= 1;
    }
    return newVec;
}

void RadixSort(vector<vector<int>> container) {
    for (int i = length-1; i >= 0; i--) {
        vector<int> tempVec;
        for (int j = 0; j < container.size(); j++ )
            tempVec.push_back(container[j][i]);
        container = CountingSort(container,tempVec);
    }
    
    // Output values per container
    for(int i = 0; i < container.size(); i++){
        for (int j = 0; j < container[i].size(); j++){
            cout << container[i][j] << ";";
        }
        cout << endl;
    }
    
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> container;
    int val;
    int vecSize = 0;

    // Get the size of each sequence
    cin >> vecSize;
    container.resize(vecSize);
    
    // Read the sequences
    for(int i = 0; i < vecSize; i++) {
        for(int j = 0; j < length; j++) {
            cin >> val;
            container[i].push_back(val);
        }
    }

    RadixSort(container);

    return 0;
}


