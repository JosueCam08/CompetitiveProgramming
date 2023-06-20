#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define fori(a, b) for(int i = a; i < b; i++)

typedef int64_t i64;

i64 N;
vector<i64> X;
vector<i64> Y;
vector< vector<i64> > dp;

i64 solve(i64 pos, i64 stomatch){
    if(pos > N)
        return 0;
    if(dp[pos][stomatch] != INT_MIN)
        return dp[pos][stomatch];

    dp[pos][stomatch] = solve(pos + 1, stomatch);
    if(!X[pos])
        dp[pos][stomatch] = max(dp[pos][stomatch], solve(pos + 1, X[pos]) + Y[pos]);
    else
        if(!stomatch)
            dp[pos][stomatch] = max(dp[pos][stomatch], solve(pos + 1, 1) + Y[pos]);
    return dp[pos][stomatch];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    X.assign(N + 1, 0);
    Y.assign(N + 1, 0);

    for(int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i];

   dp.assign(N + 1, vector<i64> (2, INT_MIN));

   cout << solve(1, 0) << '\n';

    return 0;
}
