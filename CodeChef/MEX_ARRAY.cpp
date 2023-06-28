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

void solve(){
    int N;
    cin >> N;

    unordered_map<i64, i64> bucket;
    set<i64> blist;

    i64 v;
    for(int i = 0; i < N; i++){
        cin >> v;
        bucket[v]++;
        blist.insert(v);
    }

    vi ans, verase;
    i64 ant = -1;
    while(bucket[0]){
        ant = -1;
        for(auto vb : blist){
            if(vb - ant == 1){
                ant = vb;
                verase.push_back(vb);
            }else{
                break;
            }
        }
        ant++;

        while(!verase.empty()){
            i64 vc = verase[verase.size() - 1];
            bucket[vc]--;
            if(!bucket[vc])
                blist.erase(vc);
            verase.pop_back();
        }

        ans.push_back(ant);
    }

    while(blist.size()){
        i64 vc = *blist.begin();
        bucket[vc]--;
        if(!bucket[vc])
            blist.erase(vc);
        ans.push_back(0);
    }
    
    cout << ans.size() << '\n';
    for(auto va : ans)
        cout << va << " ";
    cout << '\n';

    return;
}

int main(){
    //opti_io;

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}