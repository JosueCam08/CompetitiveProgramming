#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;

vector<i64> arr;
i64 N;

bool valid(i64 t){
    i64 tini = 0, tfin = N - 1, vini = arr[0] + t, vfin = arr[N - 1] - t;

    while(tini < N && abs(vini - arr[tini]) <= t)
        tini++;

    while(tfin >= 0 && abs(vfin - arr[tfin]) <= t)
        tfin--;
    
    if(tfin < tini)
        return true;

    if(arr[tfin] - arr[tini] <= 2 * t)
        return true;
    
    return false;
}

i64 bs(i64 l, i64 r){
    if(l == r)
        return l;
    i64 m = (l + r) / 2;
    if(!valid(m))
        return bs(m + 1, r);
    return bs(l, m);
}

i64 solve(){
    cin >> N;

    arr.resize(N, 0);
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    return bs(0, arr[N - 1]);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << '\n';

    return 0;
}