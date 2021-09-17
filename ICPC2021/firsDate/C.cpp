#include <bits/stdc++.h>

using namespace std;

int ans[1000000 + 2];
bool visitados[1000000 + 2];

void criba(){
    visitados[1] = true;
    for(int i = 2; i * i <= 1e6; i++){
        if(!visitados[i]){
            for(int j = i * i; j <= 1e6; j += i)
                visitados[j] = true;
        }
    }
    for(int i = 1; i <= 1e6; i++)
        ans[i] = ans[i - 1] + !visitados[i];
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, a, b;
    cin >> t;

    criba();

    while(t--){
        cin >> a >> b;
        cout << ans[b] - ans[a - 1] << '\n';
    }

    return 0;
}