#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <unordered_map>

using namespace std;

#define opti_io cin.tie(0);ios_base::sync_with_stdio(0)
#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(vi &arr){
    for(int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    return;
}

int main(){
    opti_io;

    int N, M, C, it;
    cin >> N >> M;

    vi P(N);
    vector< bitset<100> > F(N);

    for(int i = 0; i < N; i++){
        cin >> P[i] >> C;

        while(C--){
            cin >> it;
            F[i][it - 1] = 1;
        }
    }

    bool flag = false;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(P[i] >= P[j] && (F[i] & F[j]) == F[i] && (P[i] > P[j] || F[i] != F[j]))
                flag = true;

    if(flag)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}