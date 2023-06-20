#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define ifor(a, b) for(int i = a; i < b; i++)

typedef int64_t i64;

i64 N, K, Q, ans = 0;
multiset<i64> X;
multiset<i64> Y;
vector<i64> A;

void balance(){

    while(X.size() < K && !Y.empty()){
        auto ity = Y.end(); ity--;
        ans += (*ity);
        X.insert((*ity));
        Y.erase(ity);
    }

    if(Y.empty())
        return;

    auto itx = X.begin(), ity = Y.end(); ity--;
    i64 vx = (*itx), vy = (*ity);
    while(vx < vy){
        ans += vy - vx;
        X.erase(itx);
        Y.erase(ity);
        X.insert(vy);
        Y.insert(vx);

        itx = X.begin(); ity = Y.end(); ity--;
        vx = (*itx); vy = (*ity);
    }

    return;
}

void add(i64 v){
    Y.insert(v);
    balance();
    return;
}

void erase(i64 v){
    auto x = X.find(v);
    if(x != X.end()){
        ans -= (*x);
        X.erase(x);
    }else{
        Y.erase(Y.find(v));
    }
    balance();
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K >> Q;

    for(int i = 0; i < K; i++)
        X.insert(0);
    for(int i = K; i < N; i++)
        Y.insert(0);

    A.assign(N + 1, 0);

    i64 i, nv;
    while(Q--){
        cin >> i >> nv;

        add(nv);
        erase(A[i]);
        A[i] = nv;

        cout << ans << '\n';
    }

    return 0;
}
