#include <iostream>
#include <vector>

using namespace std;

typedef int64_t i64;

void solve(){
    i64 N, B;
    cin >> N >> B;

    vector<i64> arr(N);

    for(int i = 0; i < N; i++) cin >> arr[i];

    i64 c = (1 << 30) - 1, cont = 0;
    for(int i = 0; i < N; i++){
        if((arr[i]&B) == B){
            cont++;
            c &= arr[i];
        }
    }

    if(c == B && cont)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}