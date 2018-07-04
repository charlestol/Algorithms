#include <iostream>
#include <limits.h>

using namespace std;

void Print_Cut_Rod_Solution(int* p, int n, int* r, int* s) {
    cout << r[n] << endl;
    while(n > 0) {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << "-1" << endl;
}

void Extended_Bottom_Up_Cut_Rod(int* p, int n) {
    int* r = new int[n+1];
    int* s = new int[n+1];
    int q;
    r[0] = 0;
    for(int i = 1; i <= n; i++) {
        q = INT_MIN;
        for(int j = 1; j <= i; j++) {
            if(q < p[j] + r[i - j]) {
                q = p[j] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
    }
    Print_Cut_Rod_Solution(p, n, r, s);
}

int main(int argc,char **argv) {
    
    // Get the size of the sequence
    int n = 1;
    int* p;
    
    cin >> n;
    
    p = new int[n+1];
    //read p;
    p[0] = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> p[i];
    }
    
    Extended_Bottom_Up_Cut_Rod(p,n);
    
    // Free allocated space
    delete[] p;
    
    return 1;
}

