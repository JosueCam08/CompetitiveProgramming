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

int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--){
        i64 N, K, M;
        cin >> N >> K >> M;

        i64 dishes[N];
        for(int i = 0; i < N; i++)
            cin >> dishes[i];

        // first -> L
        // second.first -> cost
        // second.second -> R
        vector< pair< i64, pair<i64, i64> > > ranges(M);
        for(int i = 0; i < M; i++)
            cin >> ranges[i].first >> ranges[i].second.second >> ranges[i].second.first;
        sortvi(ranges);

        vi minCost(N, INT_MAX);
        priority_queue< pair<i64, i64> > bucket;
        i64 it = 0;
        for(int i = 1; i <= N; i++){
            while(it < M && ranges[it].first == i){
                bucket.push(make_pair(-ranges[it].second.first, ranges[it].second.second));
                it++;
            }

            while(!bucket.empty() && bucket.top().second < i)
                bucket.pop();

            if(bucket.empty())
                continue;

            minCost[i - 1] = bucket.top().first * (-1);
        }

        i64 dp[N + 1][K + 1];
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= K; j++){
                if(i == 0){
                    dp[i][j] = dishes[i];
                    if(minCost[i] <= j)
                        dp[i][j] = max((i64)0, dp[i][j]);
                }else{
                    dp[i][j] = dishes[i] + dp[i - 1][j];
                    if(minCost[i] <= j)
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - minCost[i]]);
                }

            }
        }

        cout << dp[N - 1][K] << '\n';
    }
    return 0;
}