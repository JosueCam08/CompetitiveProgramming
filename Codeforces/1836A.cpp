#include <iostream>
#include <vector>

using namespace std;

bool solve(){
    int N;
    vector<int> bucket(101, 0);
    cin >> N;

    int v, maxi = 0;
    for(int i = 0; i < N; i++){
        cin >> v;
        bucket[v]++;
        maxi = max(maxi, v);
    }

    for(int i = 0; i <= maxi; i++){
        if(i == 0){
            if(bucket[i] == 0)
                return false;
        }else{
            if(bucket[i] > bucket[i - 1])
                return false;
        }
    }

    return true;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}