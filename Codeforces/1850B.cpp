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
        i64 n;
        cin >> n;

        int a, b;
        vector< pair<int, int> > arr;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            if(a > 10)
                continue;
            arr.push_back(make_pair(-b, i + 1));
        }

        sortvi(arr);

        cout << arr[0].second << '\n';
    }

    return 0;
}