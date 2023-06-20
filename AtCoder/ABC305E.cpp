#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef int64_t i64;

#define fori(a, b) for(int i = a; i < b; i++)


priority_queue< pair<i64, i64> > pq;

int main(){

    i64 N, M, K;
    cin >> N >> M >> K;

    vector< vector<i64> > adj(N + 1);

    i64 a, b;
    fori(0, M){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<i64> d(N + 1, -1);
    priority_queue< pair<i64, i64> > pq;
    i64 k, h;
    fori(0, K){
        cin >> k >> h;
        d[k] = h;
        pq.push(make_pair(h, k));
    }

    i64 to, len;
    while(!pq.empty()){
        to = pq.top().second;
        len = pq.top().first;
        pq.pop();

        if(d[to] != len)
            continue;


        for(i64 v : adj[to]){
            if(len - 1 > d[v]){
                d[v] = len - 1;
                pq.push(make_pair(len - 1, v));
            }
        }
    }

    i64 ans = 0;
    for(int i = 1; i <= N; i++)
        if(d[i] >= 0)
            ans++;

    cout << ans << '\n';
    for(int i = 1; i <= N; i++)
        if(d[i] >= 0)
            cout << i << " ";
    cout << '\n';

    return 0;
}