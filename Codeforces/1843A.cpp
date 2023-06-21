#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N;
    cin >> N;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int i = 0, j = N - 1, ans = 0;
    while(i < j){
        ans += arr[j] - arr[i];
        i++; j--;
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