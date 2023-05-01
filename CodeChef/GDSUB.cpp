#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long ll;
#define MOD 1000000007

int N, K;
vector<ll> rep;

vector< vector< ll > > dp(1008, vector< ll > (1008, -1));

ll solve(int k, int j){
    if(dp[k][j] != -1)
        return dp[k][j];
    dp[k][j] = (solve(k, j - 1) % MOD + (rep[j - 1] * solve(k - 1, j - 1) % MOD)) % MOD;
    return dp[k][j];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    vector< int > arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int cont = 1;
    for(int i = 0; i < N - 1; i++){
        if(arr[i] == arr[i + 1])
            cont++;
        else{
            rep.push_back(cont);
            cont = 1;
        }
    }
    rep.push_back(cont);

    int n = rep.size(), nk = min(n, K);

    for(int i = 0; i <= n; i++)
        dp[0][i] = 1;
    for(int k = 1; k <= nk; k++)
        dp[k][0] = 0;

    ll ans = 0;
    for(int i = 0; i <= nk; i++)
        ans += solve(i, n) % MOD;

    cout << (ans % MOD) << '\n';

    return 0;
}