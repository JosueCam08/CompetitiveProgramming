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
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(i64 n, vi &arr){
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

int main(){
    opti_io;
    
    int t;
    cin >> t;

    int cA, cB, cAB, c0, n;
    string s;

    while(t--){
        cin >> n;

        cA = cB = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            if(s == "A")
                cA++;
            if(s == "B")
                cB++;;
        }

        cout << n - min(cA, cB) << '\n';
    }
    return 0;
}