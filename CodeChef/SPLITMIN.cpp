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
        i64 N;
        cin >> N;

        i64 a, b;
        vector< pair<i64, i64> > arr;

        for(int i = 0; i < N; i++){
            cin >> a >> b;
            arr.push_back(make_pair(a, i));
            arr.push_back(make_pair(b, i));
        }

        revsortvi(arr);

        i64 ans = INT_MAX;
        vector< bool > bucket(100000 * 3, false);

        for(int i = 0; i < N * 2 - 1; i++){
            if(arr[i].second == arr[i + 1].second){
                bucket[arr[i].second] = true;
                continue;
            }

            ans = min(ans, arr[i].first - arr[i + 1].first);
            if(bucket[arr[i].second])
                break;
            bucket[arr[i].second] = true;
        }

        cout << ans << '\n';
    }

    return 0;
}