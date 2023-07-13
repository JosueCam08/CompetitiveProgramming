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

int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--){
        i64 N, M;
        cin >> N >> M;

        vi arr(M);
        readvi(arr);
        revsortvi(arr);
        
        i64 csize = arr[0];
        for(int i = 1; i < M; i++)
            csize = max(arr[i] - (N - csize), (i64)0);

        cout << csize << '\n';
    }
    return 0;
}