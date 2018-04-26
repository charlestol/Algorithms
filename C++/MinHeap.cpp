#include <iostream>
using namespace std;

void MinHeapify(int* Arr, int index, int heapSize) {
    int l = (index*2) + 1;
    int r = (index*2);
    int smallest = index;
    
    if(l < heapSize && Arr[l] > Arr[index])
        smallest = l;
    if(r < heapSize && Arr[r] > Arr[smallest])
        smallest = r;
    if(smallest != index) {
        swap(Arr[index], Arr[smallest]);
        MinHeapify(Arr, smallest, heapSize);
    }
}

void BuildMinHeap(int* Arr, int ArrSize) {
    for(int i = (ArrSize/2) - 1; i >= 0; i--)
        MinHeapify(Arr, i, ArrSize);
}

void Heapsort(int* Arr, int ArrSize) {
    BuildMinHeap(Arr, ArrSize);
    for(int i = ArrSize-1; i >= 0; i--) {
        swap(Arr[0],Arr[i]);
        ArrSize--;
        MinHeapify(Arr, 0, ArrSize);
    }
}

int main(int argc,char **argv) {
    
    int* Sequence;
    int arraySize = 1;
    
    // Get the size of the sequence
    cin >> arraySize;
    Sequence = new int[arraySize];
    
    // Read the sequence
    for(int i=0; i<arraySize; i++)
        cin >> Sequence[i];
    
    Heapsort(Sequence, arraySize);
    
    for(int i = 0; i < arraySize; i++)
        cout << Sequence[i] << ";";
    
    // Free allocated space
    delete[] Sequence;
    
}

