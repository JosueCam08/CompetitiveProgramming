#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

#define opti_io cin.tie(0);ios_base::sync_with_stdio(0)
#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(i64 n, vi &arr){
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

int main(){
    opti_io;

    int t;
    cin >> t;

    i64 N, K;
    while(t--){
        cin >> N >> K;

        vi A, B;
        i64 v;
        for(int i = 1; i <= N; i++){
            cin >> v;
            if((1 <= i && i <= (N - K)) || (max(K + 1, N - K + 1) <= i && i <= N))
                A.push_back(v);
            else
                B.push_back(v);
        }

        sortvi(A);

        vi C;
        int itA = 0, itB = 0;
        for(int i = 1; i <= N; i++){
            if((1 <= i && i <= (N - K)) || (max(K + 1, N - K + 1) <= i && i <= N))
                C.push_back(A[itA]), itA++;
            else
                C.push_back(B[itB]), itB++;
        }

        for(int i = 0; i < C.size(); i++)
            cout << C[i] << " \n"[i == (C.size() - 1)];
    }
    return 0;
}