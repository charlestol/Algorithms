#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <sstream>

using namespace std;

void Insert(vector<list<int> > &hashtable, int k) {
    int m = hashtable.size();
    int val = k % m;
    hashtable[val].push_front(k);
}

void Search(vector<list<int> > &hashtable, int k) {
    int m = hashtable.size();
    int val = (k % m);
    list<int>:: iterator iterate = find(hashtable[val].begin(), hashtable[val].end(), k);
    
    if(iterate == hashtable[val].end())
        cout << k << ":NOT_FOUND;" << endl;
    else
        cout << k << ":FOUND_AT" << val << "," << distance(hashtable[val].begin(), iterate) << ";" << endl;
}

void  Delete(vector<list<int> > &hashtable, int k) {
    int m = hashtable.size();
    int val = (k % m);
    list<int>:: iterator iterate = find(hashtable[val].begin(), hashtable[val].end(), k);
    
    if(iterate == hashtable[val].end())
        cout << k << ":DELETE_FAILED;" << endl;
    else {
        hashtable[val].erase(iterate);
        cout << k << ":DELETED;" << endl;
    }
}

void Print(vector<list<int> > &hashtable){
    int hashSize = hashtable.size();
    
    for(int i = 0; i < hashSize; i++) {
        cout << i << ":";
        for(list<int>::iterator iterate = hashtable[i].begin(); iterate != hashtable[i].end(); ++iterate)
            cout << *iterate << "->";
        cout << ";" << endl;
    }
}

int main(){
    int size = 0, val = 0;
    string input, function;
    vector<list<int>> hashtable; // initialize hashtable

    cin>>size;
    cin >> input;

    hashtable.resize(size);
    
    while (input != "e"){
        if (input != "o"){
            function = input.substr(0,1);
            stringstream convert(input.substr(1,input.size()-1));
            if(!(convert >> val))
                val = -1;
            if(function == "i")
                Insert(hashtable, val);
            else if(function == "s")
                Search(hashtable, val);
            else if(function == "d")
                Delete(hashtable, val);
        }
        else if(input=="o"){
            Print(hashtable);
        }
        cin>>input;
        
    }
}


