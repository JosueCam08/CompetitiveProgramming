#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;

    long long coins, k;
    while(t--){
        cin >> coins >> k;

        int bs = 0;
        for(int i = 0; i <= 30; i++)
            if( (coins&(1 << i)) )
                bs = i;
        if(bs < k)
            cout << coins + 1 << '\n';
        else
            cout << (1<<k) << '\n';
    }

    return 0;
}