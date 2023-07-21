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
        i64 n, k;
        cin >> n >> k;

        vi arr(n);
        readvi(arr);
        sortvi(arr);

        i64 maxrange = 0, crange = 1;
        for(int i = 0; i < n - 1; i++){
            if(arr[i + 1] - arr[i] <= k){
                crange++;
            }else{
                maxrange = max(maxrange, crange);
                crange = 1;
            }
        }
        maxrange = max(maxrange, crange);

        cout << n - maxrange << '\n';
    }
    return 0;
}