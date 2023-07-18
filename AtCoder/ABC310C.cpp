#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <unordered_map>

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

    int N;
    cin >> N;

    unordered_map<string, int> bucket;

    string s, aux;
    cin >> s;

    int ans = 1;

    aux = s;
    reverse(aux.begin(), aux.end());
    bucket[s]++;
    if(s != aux)
        bucket[aux]++;

    for(int i = 1; i < N; i++){
        cin >> s;
        aux = s;
        reverse(aux.begin(), aux.end());

        if(bucket[s] || bucket[aux])
            continue;
        
        ans++;
        bucket[s]++;
        bucket[aux]++;
    }

    cout << ans << '\n';
    return 0;
}