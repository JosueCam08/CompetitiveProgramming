#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool solve(){
    ll o1, o2;
    cin >> o1 >> o2;
    
    ll N = o1 * o2;
    vector<ll> arr(2*N, 0);

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        arr[N + i] = arr[i];
    }

    vector<ll> prefixSum(2*N + 1, 0);
    for(int i = 0; i < 2*N; i++)
        prefixSum[i + 1] = prefixSum[i] + arr[i];

    for(int i = 1; i <= o2; i++){
        int cont = 0;
        for(int j = 1; j <= o1; j++){
            int ini = (j * o2) + i;
            int fin = ini + o2 - 1;

            if(prefixSum[fin] - prefixSum[ini - 1] > o2 / 2)
                cont++;
        }
        if(cont > o1 / 2)
            return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << '\n';

    return 0;
}