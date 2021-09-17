/*
* Date: 20 / 08 / 2021
* Link: https://codeforces.com/problemset/problem/1560/B
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b, c, aux;
    cin >> a >> b >> c;

    aux = min(a, b);
    b = max(a, b);
    a = aux;

    int mid = b - (a - 1), d, tam;
    tam = (mid * 2) - 2;

    if(c > tam || b > tam){
        cout << -1 << endl;
        return;
    }

    if( ((b - 1) == a || (b + 1) == a) && (a != 1 && b != 2)){
        cout << -1 << endl;
        return;
    }

    if(c >= mid){
        cout << 1 + (c - mid) << endl;
    }else{
        cout << mid + (c - 1)  << endl;
    }
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