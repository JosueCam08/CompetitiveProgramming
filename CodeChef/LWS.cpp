// NOT SOLVED
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    int alph_size = 'z' - 'a' + 2;

    vector< vector< vector<int> > > dp (n, vector< vector<int> > (alph_size, vector<int> (alph_size, 0) ) );

    for(int j = 'a'; j <= 'z'; j++)
        for(int k = 'a'; k <= 'z'; k++)
            if(j <= s[n - 1] || k >= s[n - 1])
                dp[n - 1][j - 'a'][k - 'a'] = 1;

    for(int i = n - 2; i >= 0; i--)
        for(int j = 'a'; j <= 'z'; j++)
            for(int k = 'a'; k <= 'z'; k++){
                dp[i][j - 'a'][k - 'a'] = dp[i + 1][j - 'a'][k - 'a'];
                if(s[i] >= j)
                    dp[i][j - 'a'][k - 'a'] = max(dp[i][j - 'a'][k - 'a'], 1 + dp[i + 1][s[i] - 'a'][k - 'a']);
                if(s[i] <= k)
                    dp[i][j - 'a'][k - 'a'] = max(dp[i][j - 'a'][k - 'a'], 1 + dp[i + 1][j - 'a'][s[i] - 'a']);
            }
    cout << dp[0][0]['z' - 'a'] << '\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    string s;
    while(T--)
        solve();

    return 0;
}