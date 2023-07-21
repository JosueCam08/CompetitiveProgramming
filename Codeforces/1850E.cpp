#include <iostream>
#include <math.h>
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
typedef unsigned long long i64;
typedef vector<i64> vi;

void readvi(vi &arr){
    for(int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    return;
}

i64 arr[100000 * 3];
i64 n, c;

bool check(i64 w){
    i64 suma = 0;
    for(int i = 0; i < n; i++)
        suma += (unsigned long long)(arr[i] + w + w) * (arr[i] + w + w);
    if(suma < c)
        return false;
    return true;
}

i64 bs(i64 l, i64 r){
    if(l == r)
        return l;
    i64 m = (l + r) / 2;
    if(!check(m))
        return bs(m + 1, r);
    return bs(l, m); 
}

int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--){
        cin >> n >> c;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        i64 sq = sqrt(n) + 1;
        cout << bs(1, (unsigned long long)1000000000 / sq)  << '\n';
    }
    return 0;
}