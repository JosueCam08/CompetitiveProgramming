#include <bits/stdc++.h>

using namespace std;

string solve(long long k){
    if(k == 1)
        return "2";
    if(k == 2)
        return "(2)^2";
    if( k % 2 == 0){
        string s = "(" + solve(k / 2) + ")^2";
        return s;
    }
    string s = "(2*" + solve(k - 1) + ")";
    return s;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    long long t, k;
    cin >> t;
    while(t--){
        cin >> k;
        cout << solve(k) << '\n';
    }
        
    return 0;
}