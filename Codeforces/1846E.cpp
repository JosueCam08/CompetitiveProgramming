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

    i64 t;
    cin >> t;

    while(t--){
        i64 ans, c, n;
        bool flag = false;

        cin >> n;

        for(i64 i = 2; i <= 1001; i++){
            c = 1;
            ans = 1;


            i64 ant = 1, it = 0;
            while(ans + ant * i <= 1000000){
                ans += ant * i;
                ant *= i;
                if(it && ans == n)
                    flag = true;
                it++;
            }
        }

        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }   
    return 0;
}