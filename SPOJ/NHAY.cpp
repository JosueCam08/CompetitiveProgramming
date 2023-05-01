#include <iostream>
#include <vector>
#include <string>

using namespace std;

void kmp_dynamic(vector<int> &pi, string &s){
     for(int i = pi.size(); i < s.size(); i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            j++;
        pi.push_back(j);
    }
    return;
}

int main(){

    int n;
    string s, t;
    while(cin >> n){
        cin >> s >> t;
        s = s + '#' + t;
        
        vector<int> pi(1, 0);
        kmp_dynamic(pi, s);

        bool flag = true;
        for(int i = 0; i < t.size(); i++){
            if(n == pi[n + i + 1]){
                cout << i - n + 1 << '\n';
                flag = false;
            }
        }

        if(flag)
            cout << '\n';
    }
    
    return 0;
}