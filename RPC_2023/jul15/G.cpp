#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits.h>

using namespace std;

#define opti_io cin.tie(0);ios_base::sync_with_stdio(0)
#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(vi &arr){
    for(int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    return;
}

i64 N, M, x_ini, y_ini, E;
const int INF = 1000000000;
vector< vector<i64> > table(5002, vector<i64>(5002, 0));

int movX [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int movY [] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main(){
    opti_io;

    cin >> N >> M >> x_ini >> y_ini >> E;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> table[i][j];

    x_ini--;
    y_ini--;
    i64 n = N * M;
    vi d(n + 2, INF);
    d[x_ini * M + y_ini] = 0;

    priority_queue< pair<int, int>, vector< pair<int,int> >, greater< pair<int, int> > > q;
    q.push(make_pair(0, x_ini * M + y_ini));

    while(!q.empty()){
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();

        if(d_v != d[v])
            continue;

        int cx = v / M, cy =  v % M;
        for(int i = 0; i < 8; i++){
            int nx = cx + movX[i];
            int ny = cy + movY[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                int to = nx * M + ny;
                int len = i + 1;

                if(d[v] + len < d[to]){
                    d[to] = d[v] + len;

                    if(!table[nx][ny])
                        q.push(make_pair(d[to], to));
                }
            }
        }
    }

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(table[i][j]){
                int c = i * M + j;
                if(d[c] <= E)
                    ans = max(ans, table[i][j]);
            }
        }
    }

    cout << ans << '\n';

    return 0; 
}