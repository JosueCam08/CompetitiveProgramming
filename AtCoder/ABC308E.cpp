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

void readvi(vi &arr){
    for(int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    return;
}

map< pair<char, int>, int > bucket;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vi arr(n);
    readvi(arr);

    string s;
    cin >> s;

    for(int i = 0; i < n; i++)
        if(s[i] == 'X')
            bucket[make_pair(s[i], arr[i])]++;

    i64 ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'M')
            bucket[make_pair(s[i], arr[i])]++;
        if(s[i] == 'X')
            bucket[make_pair(s[i], arr[i])]--;
        if(s[i] == 'E'){
            for(int ii = 0; ii < 3; ii++)
                for(int jj = 0; jj < 3; jj++){
                    if(bucket[make_pair('M', ii)] && bucket[make_pair('X', jj)]){
                        set<int> vMEX;
                        for(int l = 0; l < 4; l++)
                            vMEX.insert(l);
                        vMEX.erase(ii);
                        vMEX.erase(jj);
                        vMEX.erase(arr[i]);
                        ans += (*vMEX.begin()) * bucket[make_pair('M', ii)] * bucket[make_pair('X', jj)];
                    }
                }
        }
    }

    cout << ans << '\n';
    return 0;
}