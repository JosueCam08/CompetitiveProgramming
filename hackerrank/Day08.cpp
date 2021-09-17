#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map<string, int> mapa;
    int n, number;
    string name;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> name >> number;
        mapa[name] = number;
    }
    
    while(cin >> name){
        if(mapa[name] == 0)
            cout << "Not found" << '\n';
        else
            cout << name << "=" << mapa[name] <<  '\n';
    }
    return 0;
}