#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef int64_t i64;

i64 N;
vector<i64> arr;

i64 bs(i64 ini, i64 fin, i64 busca){
    if(ini == fin)
        return (N - ini) * busca;
    i64 mid = (ini + fin) / 2;
    if(arr[mid] < busca)
        return bs(mid + 1, fin, busca);
    return bs(ini, mid, busca);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    arr.assign(N + 1, __LONG_LONG_MAX__);

    i64 mini = __LONG_LONG_MAX__, maxi = -1;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        mini = min(arr[i], mini);
        maxi = max(arr[i], maxi);
    }

    sort(arr.begin(), arr.end());

    i64 amount = 0, tuition;
    for(i64 i = mini; i <= maxi; i++){
        i64 r = bs(1, N, i);
        if(r > amount){
            amount = r;
            tuition = i;
        }
    }

    cout << amount << " " << tuition << '\n';

    return 0;
}