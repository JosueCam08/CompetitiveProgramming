#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>

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

    string s;
    i64 N;

    cin >> s >> N;

    i64 sum = 0;
    reverse(s.begin(), s.end());

    for(i64 i = 0; i < s.size(); i++)
        if(s[i] == '1')
            sum |= (long long)1 << i;
    
    if(sum > N){
        cout << -1 << '\n';
        return 0;
    }

    for(i64 i = s.size() - 1; i >= 0; i--)
        if(s[i] == '?' && (sum | ((long long)1 << i)) <= N)
            sum |= ((long long)1 << i);
    
    cout << sum << '\n';
    return 0;
}