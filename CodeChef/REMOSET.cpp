#include <iostream>

using namespace std;

#define MOD 1000000007

int64_t binpow(int64_t x, int64_t p){
    x %= MOD;
    long long res = 1;
    while(p > 0){
        if((p & 1))
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        p >>= 1;
    }
    return res;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int64_t n;
        cin >> n;

        int64_t cpar = 0, v;
        for(int i = 0; i < n; i++){
            cin >> v;
            if(v % 2 == 0)
                cpar++;
        }

        int64_t x = 1;
        for(int i = 0; i < cpar; i++){
            x = (x * 2) % MOD;
        }
        
        if(cpar == n)
            x--;
        
        cout << x << '\n';
    }
    return 0;
}