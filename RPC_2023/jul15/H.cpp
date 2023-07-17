#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits.h>

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

i64 L, T;
vector< vector<i64> > teachers(5002);
vector< vector<i64> > dp(5002, vector<i64>(5002, -1));

i64 fdp(i64 it, i64 k){
    if(k == L)
        return 0;
    if(it == T)
        return LONG_MAX;
    if(dp[it][k] != -1)
        return dp[it][k];

    dp[it][k] = fdp(it + 1, k);
    for(int i = 0; i < min((i64)3, L - k); i++)
        dp[it][k] = min(dp[it][k], fdp(it + 1, k + i + 1) + teachers[it][i]);

    return dp[it][k];
}

int main(){
    opti_io;

    cin >> L >> T;

    i64 v;
    for(int i = 0; i < T; i++){
        for(int j = 0; j < 3; j++){
            cin >> v;
            teachers[i].push_back(v);
        }
    }

    cout << fdp(0, 0) << '\n';

    for(int i = 0; i <= L; i++){
        for(int j = 0; j <= L; j++)
            cout << dp[i][j] << " ";
        cout << '\n';
    }

    return 0;
}