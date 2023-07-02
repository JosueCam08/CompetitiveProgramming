#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n = 8;
    vi arr(n);

    readvi(n, arr);

    bool flag = true;
    for(int i = 1; i < n; i++)
        if(arr[i] < arr[i - 1])
            flag = false;

    for(int i = 0; i < n; i++)
        if(arr[i] < 100 || arr[i] > 675)
            flag = false;

    for(int i = 0; i < n; i++)
        if(arr[i] % 25 != 0)
            flag = false;

    if(flag)
        cout << "Yes\n";
    else
        cout << "No\n";
    
    return 0;
}