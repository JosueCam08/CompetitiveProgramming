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

i64 n, m, h;

struct player
{
    i64 problems;
    i64 penalty;
    i64 index;
};

player getInfo(vi &arr, i64 index){
    player c;
    i64 penalty = 0;
    i64 problems = 0, time = 0;;

    sortvi(arr);

    for(auto v : arr){
        if(time + v > h)
            break;
        problems++;
        penalty += time + v;
        time += v;
    }

    c.index = index;
    c.penalty = penalty;
    c.problems = problems;

    return c;
}

bool check(player A, player B){
    if(A.problems == B.problems)
        if(A.penalty == B.penalty)
            return A.index < B.index;
        else
            return A.penalty < B.penalty;
    return A.problems > B.problems;
}

void solve(){
    cin >> n >> m >> h;

    vi arr(m);
    vector<player> ans;
    for(int i = 0; i < n; i++){
        readvi(m, arr);
        ans.push_back(getInfo(arr, i));
    }

    sort(ans.begin(), ans.end(), check);

    for(int i = 0; i < n; i++){
        if(ans[i].index == 0)
            cout << i + 1 << '\n';
    }

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