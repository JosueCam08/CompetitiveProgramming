/*
* Date: 22 / 08 / 2021
* Link: https://codeforces.com/contest/1465/problem/A
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    int cont = 0, it = n - 1;
    while( it >= 0 && s[it--] == ')')
        cont++;

    if(cont > s.size() - cont)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}