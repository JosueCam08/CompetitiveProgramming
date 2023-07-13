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
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(vi &arr){
    for(int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    return;
}

string solve(){
    i64 N;
    cin >> N;

    string s;
    cin >> s;

    if(N % 3 == 1)
        return "YES\n";

    vector< vector<int> > bucket(200);
    for(int i = 0; i < s.size(); i++)
        bucket[s[i]].push_back(i);

    for(int k = 'a'; k <= 'z'; k++){
        if(bucket[k].size() >= 2){
            int l = N + 1, r = -1;
            for(int i = 0; i < bucket[k].size(); i++){
                if(bucket[k][i] % 3 == 0)
                    l = min(l, bucket[k][i]);
                if((N - bucket[k][i] - 1) % 3 == 0)
                    r = max(r, bucket[k][i]);
                }
            if(l < r){
                return "YES\n";
            }
        }
    }
    return "NO\n";
}

int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--)
        cout << solve();
    return 0;
}