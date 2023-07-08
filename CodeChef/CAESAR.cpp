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
#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(i64 n, vi &arr){
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

void solve(){
    i64 N;
    string A, B, C;

    cin >> N; 
    cin >> A >> B >> C;

    int shift;
    if(B[0] < A[0])
        shift = ('z' - A[0]) + (B[0] - 'a' + 1);
    else
        shift = B[0] - A[0];
    
    for(int i = 0; i < N; i++){
        C[i] -= 'a';
        C[i] += shift;
        C[i] %= 'z' - 'a' + 1;
        C[i] += 'a';
    }

    cout << C << '\n';
    return;
}

int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--)
        solve();
    return 0;
}