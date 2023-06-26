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

    string s;
    cin >> s;

    sort(s.begin(),s.end());
    reverse(s.begin(), s.end());

    cout << s << '\n';
    return 0;
}