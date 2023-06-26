#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, coffe = 0;
    string s;

    cin >> N >> s;

    int ans = 0;;
    for(int i = 0; i < N; i++){
        if(s[i] == '1'){
            coffe = 2;
            ans++;
        }else if(coffe > 0){
            ans++;
            coffe--;
        }
    }

    cout << ans << '\n';
    return 0;
}