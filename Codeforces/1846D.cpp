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
 
void readvi(i64 n, vi &arr){
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}
 
int main(){
    opti_io;
 
    int t;
    cin >> t;
 
    i64 n, B, H;
    double ans = 0;
    while(t--){
        cin >> n >> B >> H;
 
        ans = (double)(B * H) / 2.0;
        vi tam(n);
        readvi(n, tam);
        
        i64 nextH = 0;
 
        i64 h;
        double b;
        for(int i = 1; i < n; i++){
            ans += (double)(B * H) / 2.0;
            if(tam[i - 1] + H > tam[i]){
                h = (tam[i - 1] + H) - tam[i];
                b = (double)(h * B) / (double)H;
                ans -= (double)(h * b) / 2.0;
            }
        }
 
        cout << setprecision(7) << ans << '\n';
 
    }
    return 0;
}