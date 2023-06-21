#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

#define opti_io cin.tie(0);ios_base::sync_with_stdio(0)
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(i64 n, vi &arr){
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

void solve(){
    i64 n, m, h;
    cin >> n >> m >> h;

    vector<i64> cars(n);
    vector<i64> outles(m);

    readvi(n, cars);
    readvi(m, outles);

    sort(cars.begin(), cars.end());
    sort(outles.begin(), outles.end());

    reverse(cars.begin(), cars.end());
    reverse(outles.begin(), outles.end());

    i64 ans = 0;
    for(int i = 0; i < min(n, m); i++)
        ans += min(cars[i], outles[i] * h);

    cout << ans << '\n';
}

int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--)
        solve();
    return 0;
}