#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;
typedef int64_t i64;

i64 n, m, q;

bool valid(i64 it, vector< pair<i64, i64> >& vranges, vector<i64>& vq){
    vector<i64> vps(n + 1, 0);

    for(int i = 0; i <= it; i++)
        vps[vq[i]]++;
    
    for(int i = 1; i <= n; i++)
        vps[i] += vps[i - 1];

    i64 rsize, cunos;
    for(int i = 0; i < m; i++){
        rsize = vranges[i].second - vranges[i].first + 1;
        cunos = vps[vranges[i].second] - vps[vranges[i].first - 1];
        rsize -= cunos;
        if(cunos > rsize)
            return true;
    }
    return false;
}

i64 bs(i64 l, i64 r,  vector< pair<i64, i64> >& vranges, vector<i64>& vq){
    if(l == r)
        return l;
    i64 m = l + ((r - l) / 2);
    if(!valid(m, vranges, vq))
        return bs(m + 1, r, vranges, vq);
    return bs(l, m, vranges, vq);
}

void solve(){
    cin >> n >> m;

    vector< pair<i64, i64> > vranges(m);

    for(int i = 0; i < m; i++)
        cin >> vranges[i].first >> vranges[i].second;
    
    cin >> q;

    vector<i64> vq(q);
    for(int i = 0; i < q; i++)
        cin >> vq[i];

    i64 ans = bs(0, q - 1, vranges, vq);
    if(ans == q - 1)
        if(valid(q - 1, vranges, vq))
            cout << q << '\n';
        else
            cout << -1 << '\n';
    else
        cout << ans + 1 << '\n';
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