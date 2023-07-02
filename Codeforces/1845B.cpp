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

i64 solution(){
    i64 xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    i64 sumx = 0, sumy = 0;

    if( (xa - xb <= 0 && xa - xc <= 0) || (xa - xb >= 0 && xa - xc >= 0) )
        sumx = min(abs(xa - xb), abs(xa - xc));
    if( (ya - yb <= 0 && ya - yc <= 0) || (ya - yb >= 0 && ya - yc >= 0) )
        sumy = min(abs(ya - yb), abs(ya - yc));

    return sumx + sumy + 1;
}   


int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--)
        cout << solution() << '\n';
    return 0;
}