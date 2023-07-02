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

int n, m;
vector <string> mat(501);
string word = "snuke";

struct dataBFS
{
    int x;
    int y;
    int t;
};

int GmovX[] = {-1, 0, 1, 0};
int GmovY[] = {0, 1, 0, -1};

bool solve(vector<int> &movX, vector<int> &movY){
    dataBFS v;
    v.x = 0;
    v.y = 0;
    v.t = 1;

    if(mat[0][0] != 's')
        return false;

    vector < vector<bool> > vist(501, vector<bool>(501, false));
    stack <dataBFS> cola;
    cola.push(v);

    while(!cola.empty()){
        dataBFS cnode = cola.top();
        cola.pop();

        //cout << cnode.x << " " << cnode.y << " " << mat[cnode.x][cnode.y] << " " << cnode.t << '\n';
        if(cnode.x == n - 1 && cnode.y == m - 1)
            return true;

        for(int i = 0; i < 4; i++){
            int cx = cnode.x + movX[i];
            int cy = cnode.y + movY[i];
            if(cx >= 0 && cy >= 0 && cx < n && cy < m && !vist[cx][cy]){
                if(mat[cx][cy] == word[cnode.t % 5]){
                    dataBFS aux;
                    aux.x = cx;
                    aux.y = cy;
                    aux.t = cnode.t + 1;
                    cola.push(aux);
                    vist[cx][cy] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> mat[i];

    for(int i = 0; i < 4; i++){
        vector<int> movX;
        vector<int> movY;
        for(int j = 0; j < 9; j++){
            movX.push_back(GmovX[j + i % 4]);
            movY.push_back(GmovY[j + i % 4]);
        }
        if(solve(movX, movY)){
            cout << "Yes\n";
            return 0;
        }
    }
    
    cout << "No\n";
    
    return 0;
}