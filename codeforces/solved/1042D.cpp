/*
* Date: 17 / 09 / 2021
* Link: https://codeforces.com/problemset/problem/1042/D
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll t, arr[200000 + 1];

ll solve(int ini, int fin){
    if(ini >= fin){
        if(arr[ini] < t)
            return 1;
        return 0;
    }

    int mid = (ini + fin) / 2;
    vector<ll> leftArr;
    vector<ll> rightArr;

    ll ansL = solve(ini, mid), ansR = solve(mid + 1, fin);

    leftArr.push_back(arr[mid]);
    for(int i = mid - 1, j = 0; i >= ini; i--, j++)
        leftArr.push_back(arr[i] + leftArr[j]);

    rightArr.push_back(arr[mid + 1]);
    for(int i = mid + 2, j = 0; i <= fin; i++, j++)
        rightArr.push_back(arr[i] + rightArr[j]);

    sort(leftArr.begin(), leftArr.end());
    reverse(leftArr.begin(), leftArr.end());
    sort(rightArr.begin(), rightArr.end());
    

    ll itL, itR;
    ll ans = 0;
    for(itL = 0, itR = 0; itL < leftArr.size() && itR < rightArr.size(); ){
        if(leftArr[itL] + rightArr[itR] < t)
            itR++;
        else{
            ans += itR;
            itL++;
        }
    }
    ans += (leftArr.size() - itL) * itR;

    return ans + ansL + ansR;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> t;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(0, n - 1);
    /*cout << 200000 << " " << 100000000000000 * 2 << '\n';
    for(int i = 0; i < 200000; i++)
        cout << 1000000000 << " ";*/

    return 0;
}