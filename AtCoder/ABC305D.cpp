#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef int64_t i64;

vector<i64> arr, sumPrefix;

i64 bs(i64 l, i64 r, i64 b){
    if(l == r)
        return l - 1;
    i64 m = (l + r) / 2;
    if(arr[m] <= b)
        return bs(m + 1, r, b);
    return bs(l, m, b);
}

int main(){

    i64 N;
    cin >> N;

    arr.resize(N + 1, 0);
    sumPrefix.resize(N + 1, 0);

    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    for(int i = 3; i <= N; i++){
        if(i % 2 == 1)
            sumPrefix[i] = sumPrefix[i - 1] + (arr[i] - arr[i - 1]);
        else
            sumPrefix[i] = sumPrefix[i - 1];
    }

    i64 Q;
    cin >> Q;

    i64 l, r, bl, br, ans;
    while(Q--){
        cin >> l >> r;
        bl = bs(1, N, l);
        br = bs(1, N, r);

        if(bl % 2 == 0)
            ans = sumPrefix[bl] + (l - arr[bl]);
        else
            ans = sumPrefix[bl];

        if(br % 2 == 0)
            ans = (sumPrefix[br] + (r - arr[br])) - ans;
        else
            ans = sumPrefix[br] - ans;

        cout << ans << '\n';
    }

    return 0;
}