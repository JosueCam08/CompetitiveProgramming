/*
* Date: 24 / 08 / 2021
* Link: https://codeforces.com/problemset/problem/1557/A
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<long long> arr;
    long long aux;

    for(int i = 0; i < n; i++){
        cin >> aux;
        arr.push_back(aux);
    }

    sort(arr.begin(), arr.end());

    long long dif = 0, it = n - 2;
    /*if(arr[arr.size() - 1] < 0)
        it = n - 2;
    else{
        for(int i = 0; i < n - 1; i++){
            if(abs(arr[i] - arr[i + 1]) >= dif){
                dif = abs(arr[i] - arr[i + 1]);
                it = i;
            }
        }
    }*/

    double sumA = 0, sumB = 0;
    for(int i = 0; i <= it; i++)
        sumA += arr[i];
    for(int j = it + 1; j < n; j++)
        sumB += arr[j]; 
    
    double ans = ( sumA / (double)(it + 1) ) + ( sumB / (double)( arr.size() - (it + 1) ) );
    cout << fixed << setprecision(6) << ans << '\n';
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