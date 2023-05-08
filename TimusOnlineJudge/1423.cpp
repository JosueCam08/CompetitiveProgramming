#include <bits/stdc++.h>

using namespace std;

vector<int> KMP(string s){
    int n = (int) s.size();
    vector<int> pi(n, 0);

    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    return pi;
}

int main(){
    int N;
    string s, t;

    cin >> N >> s >> t;

    s = s + " " + t + t;
    vector<int> pi = KMP(s);

    bool flag = true;
    for(int i = N + 1; i < pi.size(); i++){
        if(pi[i] == N){
            cout << (i - (2 * N)) << '\n';
            flag = false;
            break;
        }
    }

    if(flag)
        cout << -1 << '\n';
    return 0;
}