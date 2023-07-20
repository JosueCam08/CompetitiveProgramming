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

        i64 sum = 0;
        vi arr(N);

        for(int i = 0; i < N; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        sortvi(arr);

        cout << sum << " ";
        for(int i = 0; i < N - 1; i++){
            sum -= arr[i];
            cout << sum << " \n"[i == (N - 2)];
        }
    }
    return 0;
}