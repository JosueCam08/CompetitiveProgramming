#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define ifor(a, b) for(long long i = a; i < b; i++)

typedef long long i64;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    i64 nbit;
    
    unsigned long long ans = 0;
    unsigned long long one = 1, aux;
    ifor(0, 64){
        cin >> nbit;
        aux = (one << i);
        //cout << aux << '\n';
        if(nbit){
            //cout << i << ": " << ans << " + " << (one << i) << " = " << ans + (1 << i) << '\n';
            ans += aux;
        }
    }
    //long long l;
    //l += __LONG_LONG_MAX__;
    //cout << l << '\n';
    cout << ans << '\n';

    return 0;
}
