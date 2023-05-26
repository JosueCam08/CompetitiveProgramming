//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef int64_t i64;

i64 N, Q, c;
vector<i64> bit;

i64 sum(i64 idx){
    i64 suma = 0;
    while(idx > 0){
        suma += bit[idx];
        idx -= idx & (-idx);
    }
    return suma;
}

void add(i64 idx, i64 val){
    while(idx <= N){
        bit[idx] += val;
        idx += idx & (-idx);
    }
    return;
}

int main(){ 
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> Q >> c;

    bit.assign(N + 2, 0);
    add(1, c);

    char t;
    i64 l, r, v;
    while(Q--){
        cin >> t;

        if(t == 'Q'){
            cin >> v;
            cout << sum(v) << '\n';
        }else{
            cin >> l >> r >> v;
            add(l, v);
            add(r + 1, -v);
        }
    }

    return 0;
}