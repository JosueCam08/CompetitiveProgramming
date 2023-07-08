#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>

using namespace std;

#define opti_io cin.tie(0);ios_base::sync_with_stdio(0)
#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(vi &arr){
    for(int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    return;
}

i64 bs(i64 l, i64 r, i64 k, vi &arr){
    if(l == r)
        return l;
    i64 m = (l + r) / 2;
    if(k <= arr[m])
        return bs(l, m, k, arr);
    return bs(m + 1, r, k, arr);
}

void solve(){
    i64 n, q;
    cin >> n >> q;

    vi arr(n);
    readvi(arr);

    sortvi(arr);

    vi prefixSum(n);

    i64 cn = n - 1;
    prefixSum[0] = ((cn - 1) * cn) / 2;
    for(int i = 1; i < n; i++){
        cn = n - i - 1;
        prefixSum[i] = prefixSum[i - 1] + ((cn - 1) * cn) / 2;
    }

    i64 k;
    while(q--){
        cin >> k;
        cout << arr[bs(0, n - 1, k, prefixSum)] << '\n';
    }
}

int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--)
        solve();
    return 0;
}