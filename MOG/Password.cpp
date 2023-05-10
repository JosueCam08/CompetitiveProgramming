#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

vector<int> KMP(string s){
    int n = (int) s.size();
    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    vector<int> pi = KMP(s);

    int maxi = 0;
    for(int i = 1; i < s.size() - 1; i++)
        maxi = max(maxi, pi[i]);

    int j = pi[s.size() - 1];
    while(j > 0){
        if(j <= maxi){
            for(int i = 0; i < j; i++)
                cout << s[i];
            cout << '\n';
            break;
        }
        j = pi[j - 1];
    }

    if(j == 0)
        cout << "Just a legend\n";


    return 0;
}