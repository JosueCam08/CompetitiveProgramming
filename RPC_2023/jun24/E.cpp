#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <climits>

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

struct Edge
{
    int u, v, w;
};


bool compareEdges(Edge A, Edge B){
     return A.w < B.w;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector <string> arr;
    string s;

    for(int i = 0; i < n; i++){
        cin >> s;
        arr.push_back(s);
    } 

    vector<int> tree_id(n);
    vector<Edge> result;
    vector<Edge> edges;

    Edge newedge;
    int mini = INT_MAX, cont = 0, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        mini = INT_MAX;
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            cont = 0;
            for(int it = 0; it < k; it++){
                cont += abs((int)arr[i][it] - (int)arr[j][it]);
            }
            newedge.u = i; newedge.v = j; newedge.w = cont;
            edges.push_back(newedge);
        }
    }

    for(int i = 0; i < n; i++)
        tree_id[i] = i;

    sort(edges.begin(), edges.end(), compareEdges);

    i64 cost = 0;
    for(Edge e : edges){
        if(tree_id[e.u] != tree_id[e.v]){
            cost += e.w;
            result.push_back(e);
        }

        int oid = tree_id[e.u], nid = tree_id[e.v];
        for(int i = 0; i < n; i++){
            if(tree_id[i] == oid)
                tree_id[i] = nid;
        }
    }

    int ans = 0;
    for(Edge e : result)
        ans = max(ans, e.w);

    cout << ans << '\n';
    return 0;
}