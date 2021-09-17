
#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, x, k;
    cin >> n >> x >> k;

    long long ans = 0, points, pp, sum, aux;
    points = min((n - 1) ,(k / x));
    pp = max((long long)1, n - points);
    sum = ( (n - pp) * (n - pp - 1) ) / 2;
    ans = points * pp + sum;
    cout << ans << '\n';
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }


    return 0;
}