#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSubsuquence(string s1, string s2){
    int n = s1.size(), m = s2.size();
    int i = 0, j = 0;
    while(i < n && j < m){
        if(s1[i] == s2[j])
            j++;
        i++;
    }
    if(j == m)
        return true;
    return false;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;

    string s1, s2;
    while(t--){
        cin >> s1 >> s2;
        if(isSubsuquence(s1, s2) || isSubsuquence(s2, s1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}