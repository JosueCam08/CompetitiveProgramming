#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, ans = 0;
    cin >> n;

    while(n){
        ans += n;
        n /= 2;
    }

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