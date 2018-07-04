#include<iostream>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void print(int **a,int i, int j) {
    if(i == j)
        cout<<"A"<<i-1;
    else {
        cout<<"(";
        print(a,i,a[i][j]);
        print(a,a[i][j]+1, j);
        cout<<")";
    }
}

void Matrix_Chain_Order(int* p, int n) {
    int m[n][n];
    int** s = new int* [n+1];
    int i, j, k, l, q;
    
    for(i = 1;i < (n+1);i++)
        s[i] =  new int [n+1];      // for the print
    
    for(i = 1; i < n)
        m[i][i] = 0;
    for(l = 2; l < n; l++) {    // chain length
        for(i = 1; i < n-1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for(k = i; k < j-1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n-1] << endl;
    print(s,1,n-1);
    cout << endl;
}

int main() {
    int i, n;
    int arr[i+1];
    
    cin>>i;

    for(int k=0;k< i+1 ;k++)
        cin>>arr[k];
    
    n = sizeof(arr)/sizeof(arr[0]);
    
    matMult(arr,n);
    
    return 0;
    
}

