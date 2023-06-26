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

    int xdia, xmes, xanio, ydia, ymes, yanio, date;
    cin >> xdia >> xmes >> xanio >> date >> ydia >> ymes >> yanio;

    i64 dias = max((yanio - xanio) - 1, 0) * (12 * 30);

    if(xanio == yanio){
        dias += max(((ymes - xmes) - 1), 0) * 30;
        if(xmes == ymes)
            dias += ydia - xdia;
        else
            dias += (30 - xdia) + ydia;
    }else{
        dias += 30 * (12 - xmes);
        dias += 30 - xdia;
        dias += (ymes - 1) * 30;
        dias += ydia;
    }

    //cout << dias << '\n';
    int ans = dias % 7;
    ans += date;
    ans %= 7;
    if(!ans)
        ans = 7;
    cout << ans << '\n';
    return 0;
}