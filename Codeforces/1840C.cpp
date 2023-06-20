#include <iostream>
#include <vector>

using namespace std;

typedef int64_t i64;

int main(){

    int t;
    cin >> t;

    i64 n, k, q;
    while(t--){
        cin >> n >> k >> q;
        vector<i64> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        int ini = 0, fin = 0;
        i64 ans = 0;
        i64 p;
        for(int i = 0; i < n; i++){
            if(a[i] <= q)
                fin++;
            else{
                p = (fin - ini);
                p = max(p - k + 1, (i64)0);
                ans += (p * (p + 1)) / 2;

                ini = fin = i + 1;
            }
        }

        p = (fin - ini);
        p = max(p - k + 1, (i64)0);
        ans += (p * (p + 1)) / 2;

        cout << ans << '\n';
        
    }
    return 0;
}