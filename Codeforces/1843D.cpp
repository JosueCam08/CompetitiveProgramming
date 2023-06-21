#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;

vector<i64> childs;
vector<bool> visitados;

i64 getChilds(i64 node, vector< vector<i64> > &adj){
    visitados[node] = 1;
    for(auto v : adj[node])
        if(!visitados[v])
            childs[node] += getChilds(v, adj);
            
    if(!childs[node])
        childs[node] = 1;
    return childs[node];
}

void solve(){
    i64 n;

    cin >> n;
    vector< vector<i64> > adj(n + 1);

    i64 u, v;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    childs.assign(n + 1, 0);
    visitados.assign(n + 1, 0);
    getChilds(1, adj);

    i64 q;
    cin >> q;
    
    while(q--){
        cin >> u >> v;
        cout << childs[u] * childs[v] << '\n';
    }
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--)
        solve();
    return 0;
}