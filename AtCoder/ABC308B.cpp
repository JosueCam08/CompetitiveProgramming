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

    int n, m;
    cin >> n >> m;
    
    vector<string> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector< pair<string, int> > prices(m);
    int p0;
    for(int i = 0; i < m; i++)
        cin >> prices[i].first;

    cin >> p0;
    for(int i = 0; i < m; i++)
        cin >> prices[i].second;

    map< string, int > mapa;
    for(int i = 0; i < m; i++)
        mapa[prices[i].first] = prices[i].second;

    i64 ans = 0;
    for(int i = 0; i < n; i++){
        if(mapa[arr[i]])
            ans += mapa[arr[i]];
        else
            ans += p0;
    }

    cout << ans << '\n';
    return 0;
}