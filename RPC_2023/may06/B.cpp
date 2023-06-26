#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

ll arr[2501];
int N, k;

bool orderedArr(){
    bool  flag = true;
    for(int i = 0; i < N - 1; i++){
        if(arr[i] > arr[i + 1]){
            return false;
        }
    }
    return flag;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> k;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    if(orderedArr()){
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= N - k; j++)
            sort(arr + j, arr + j + k);
        if(orderedArr()){
            cout << i + 1 << '\n';
            break;
        }
    }

    return 0;
}