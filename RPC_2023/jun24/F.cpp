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

vi arr;
vi st(4 * 1000000, 0);

void update(i64 node, i64 l, i64 r, i64 idx, i64 v){
    if(l == r){
        st[node] += v;
        return;
    }
    if(l <= idx && r >= idx)
        st[node] += v;
    i64 m = (l + r) / 2;
    if(idx <= m)
        update(node * 2, l, m, idx, v);
    else
        update(node * 2 + 1, m + 1, r, idx, v);
    return;
}

i64 query(i64 node, i64 l, i64 r, i64 cl, i64 cr){
    if(l == cl && r == cr)
        return st[node];
    if(cr < cl || l > cr || r < cl)
        return 0;
    i64 m = (l + r) / 2;
    return query(node * 2, l, m, cl, min(m, cr)) + query(node * 2 + 1, m + 1, r, max(m + 1, cl), cr);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    i64 n;
    cin >> n;

    arr.assign(n, 0);
    readvi(n, arr);

    for(int i = 0; i < n; i++){
        update(1, 1, n, i + 1, arr[i]);
    }

    i64 t;
    cin >> t;
    char op;
    i64 l, r, v;
    while(t--){
        cin >> op;
        if(op == 'U'){
            cin >> r >> v;
            update(1, 1, n, r, v);
        }else{
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}