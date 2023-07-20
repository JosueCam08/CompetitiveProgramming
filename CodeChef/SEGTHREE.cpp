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

        vi data(N);
        readvi(data);

        i64 ans = INT_MAX;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){

                    vi arr(data);
                    arr[0] += i;
                    arr[1] += j;
                    arr[2] += k;

                    if((arr[0] + arr[1] + arr[2]) % 3 != 0)
                        continue;
                    
                    i64 cans = i + j + k;
                    for(int ii = 3; ii < N; ii++){
                        i64 ca = arr[ii - 3] % 3;
                        i64 cb = arr[ii] % 3;
                        if(ca > cb){
                            arr[ii] += ca - cb;
                            cans += ca - cb;
                        }
                        if(ca < cb){
                            arr[ii] += (3 - cb) + ca;
                            cans += (3 - cb) + ca;
                        }
                    }

                    ans = min(ans, cans);
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}