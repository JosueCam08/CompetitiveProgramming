#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long N;
    cin >> N;

    vector<long long> arr(N);

    long long sum = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum += abs(arr[i]);
    }

    long long gcount = 0, ccount = 0, csum = 0;;
    for(int i = 0; i < N; i++){
        if(arr[i] <= 0){
            ccount++;
            csum += arr[i];
        }else{
            if(ccount > 0 && csum < 0)
                gcount++;
            ccount = 0;
            csum = 0;
        }
    }

    if(ccount > 0 && csum < 0)
        gcount++;

    cout << sum << " " << gcount << '\n';
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