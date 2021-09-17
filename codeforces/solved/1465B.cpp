/*
* Date: 22 / 08 / 2021
* Link: https://codeforces.com/contest/1465/problem/B
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, aux;
    cin >> n;
    bool flag = true;
    n--;
    while(flag){
        flag = false;
        n++;
        //cout << n << '\n'; 
        aux = n;
        while(aux != 0){
            int m = aux % 10;
            if( m && n % m != 0){
                flag = true;
                break;
            }
            aux /= 10;
        }

    }
    cout << n << '\n';
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}