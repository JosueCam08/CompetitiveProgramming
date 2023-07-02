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

void solve(){
    i64 n, k, x;
    cin >> n >> k >> x;

    if(x != 1){
        cout << "YES\n";
        cout << n << '\n';
        for(int i = 0; i < n; i++)
            cout << 1 << " \n"[i == (n - 1)];
    }else{
        if(k > 1){
            if(k == n){
                cout << "YES\n";
                cout << 1 << '\n' << n << '\n';
            }else{
                if(n % 2 == 0){
                    cout << "YES\n";
                    cout << n / 2 << '\n';
                    for(int i = 0; i < n / 2; i++)
                        cout << 2 << " ";
                    cout << '\n';
                }else{
                    if(k > 2){
                        cout << "YES\n";
                        cout << n / 2 << '\n';
                        for(int i = 0; i < n / 2 - 1; i++)
                            cout << 2 << " ";
                        cout << 3 << '\n';
                    }else{
                        cout << "NO\n";
                    }
                }
            }
        }else{
            cout << "NO\n";
        }
    }
}

int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--)
        solve();
    return 0;
}