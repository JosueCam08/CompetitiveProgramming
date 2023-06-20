#include <iostream>

using namespace std;

long long solve(){
    long long n, k, g;
    cin >> n >> k >> g;

    if(k == 0)
        return 0;

    if(g == 2)
        return 0;

    long long silvercoins, minpay, peopleminpay, ans = 0;

    silvercoins = k * g;
    minpay = g / 2;
    if(g % 2 == 0)
        minpay--;

    peopleminpay = min(n - 1, silvercoins / minpay);
    n -= peopleminpay;
    ans += peopleminpay * minpay;
    silvercoins -= peopleminpay*minpay;

    if(n == 1){
        if(silvercoins % g <= minpay)
            ans += silvercoins % g;
        else
            ans -= g - (silvercoins % g);
    }else{
        ans += silvercoins;
    }

    return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--)
        cout << solve() << '\n';
    return 0;
}