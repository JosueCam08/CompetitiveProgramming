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

#define ifor(a, b) for(int i = a; i < b; i++)

typedef int64_t i64;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    i64 N;
    cin >> N;

    vector<i64> arr(3 * N + 1);

    ifor(1, 3*N + 1){
        cin >> arr[i];
    }

    vector<i64> vis(N + 1, false);
    vector< pair<i64, i64> > ans(N + 1, make_pair(4 * N, N + 1));

    ifor(1, 3 * N + 1){
        if(vis[arr[i]]){
            ans[arr[i]].first = i;
            ans[arr[i]].second = arr[i];
            vis[arr[i]] = false;
        }else{
            vis[arr[i]] = true;
        }
    }

    sort(ans.begin(), ans.end());

    ifor(0, N)
        cout << ans[i].second << " \n"[i == (N - 1)];

    return 0;
}
