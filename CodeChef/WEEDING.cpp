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

int main(){
    opti_io;

    int t;
    cin >> t;

    i64 N, M, K;
    while(t--){
        cin >> N >> M >> K;

        vi arr(N);
        readvi(N, arr);

        if(arr[N - 1] + K - 1 <= M)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}