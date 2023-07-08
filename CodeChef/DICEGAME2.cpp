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

    vi A(3), B(3);

    int t;
    cin >> t;

    while(t--){
        readvi(3, A); readvi(3, B);

        revsortvi(A);
        revsortvi(B);

        if(A[0] + A[1] == B[0] + B[1])
            cout << "Tie\n";
        else
            if(A[0] + A[1] > B[0] + B[1])
                cout << "Alice\n";
            else
                cout << "Bob\n";
    }
    return 0;
}