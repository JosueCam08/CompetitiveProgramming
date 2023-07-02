#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(i64 n, vi &arr){
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

struct datav
{
    i64 a, b, idx;
};

bool check(datav A, datav B){
    i64 rateA = A.a * (B.a + B.b), rateB = B.a * (A.a + A.b);
    if(rateA == rateB)
        return A.idx < B.idx;
    return rateA > rateB;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    i64 n;
    cin >> n;

    vector<datav> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].a >> arr[i].b;
        arr[i].idx = i;
    }

    sort(arr.begin(), arr.end(), check);

    for(int i = 0; i < n; i++)
        cout << arr[i].idx + 1 << " \n"[i == (n - 1)];
    return 0;
}