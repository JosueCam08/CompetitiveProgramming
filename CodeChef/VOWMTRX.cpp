#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>

using namespace std;

#define opti_io cin.tie(0);ios_base::sync_with_stdio(0)
#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
#define MOD 1000000007
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(vi &arr){
    for(int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    return;
}

void solve(){
    i64 N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    i64 cnt = 0, celem = 1;
    vi vans;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            if(cnt == K){
                cnt = 1;
                vans.push_back(celem);
                celem = 1;
            }else{
                cnt++;
            }
        }else{
            if(cnt == K)
                celem++;
        }
    }

    i64 ans = 1;
    for(i64 v : vans)
        ans = (ans * v) % MOD;
    cout << ans << '\n';
}

int main(){

    int t;
    cin >> t;

    while(t--)
        solve();
    return 0;
}