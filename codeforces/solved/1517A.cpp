/*
* Date: 21 / 08 / 20211
* Link: https://codeforces.com/problemset/problem/1517/A
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin >> n;

    if(n < 2050){
        cout << -1 << '\n';
        return;
    }

    long long n2050 = 2050, ans = 0, contdig = 0, aux;

    aux = n;
    while(aux != 0){
        contdig++;
        aux /= 10;
    }

    for(int i = 0; i < contdig - 4; i++)
        n2050 *= 10;

    //cout << "case: " << n << " start: " << n2050 << '\n';
    while (n2050 >= 2050)
    {   
        
        ans += n/n2050;
        n = n % n2050;
        n2050 /= 10;
        //cout << n << " " << n2050  << '\n';
    }
    
    if(n != 0)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
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