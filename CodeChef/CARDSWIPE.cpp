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
        int n;
        cin >> n;
        vi arr(n);
        readvi(arr);

        int cp = 0, ans = 0;
        vi bucket(n + 1, 0);

        for(int i = 0; i < n; i++){
            if(bucket[arr[i]]){
                bucket[arr[i]] = 0;
                cp--;
            }else{
                bucket[arr[i]] = 1;
                cp++;
            }
            
            ans = max(ans, cp);
        }

        cout << ans << '\n';
    }
    return 0;
}