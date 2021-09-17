#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll N, M, Q, xE, yE;
char mapa[1001][1001];
ll sol[1001][1001];
bool visitados[1001][1001];

int arrX[] = {0, 1, 0, -1};
int arrY[] = {-1, 0, 1, 0};

struct cord
{
    int x;
    int y;
    int p;
};

queue<cord>cola;

void BFS(ll iniX, ll iniY){
    cord actual;
    actual.x = iniX;
    actual.y = iniY;
    actual.p = 0;
    cola.push(actual);
    visitados[iniX][iniY] = true;
    sol[iniX][iniY] = 0;
    ll cx, cy;

    while(!cola.empty()){
        actual = cola.front();
        cola.pop();

        for(int i = 0; i < 4; i++){
            cx = actual.x + arrX[i];
            cy = actual.y + arrY[i];
            if( cx > 0 && cx <= N && cy > 0 && cy <= M && !visitados[cx][cy] && mapa[cx][cy] == '.' ){
                cord aux;
                aux.x = cx;
                aux.y = cy;
                aux.p = actual.p + 1;
                sol[cx][cy] = aux.p;
                visitados[cx][cy] = true;
                cola.push(aux);
            }
        }
    }
}

char querry(int x, int y){
    if(mapa[x][y] == '#')
        return 'W';
    if(mapa[x][y] == 'X')
        return 'X';
    if(mapa[x][y] == 'E')
        return 'E';
    if(mapa[x][y] == '.'){
        if(sol[x][y] == 0)
            return '?';
        else{
            for (int i = 0; i < 4; i++)
            {
                if( x + arrX[i] > 0 && x + arrX[i] <= N && y + arrY[i] > 0 && y + arrY[i] <= M && sol[x + arrX[i]][y + arrY[i]] == sol[x][y] - 1){
                    if(i == 0)
                        return 'L';
                    if(i == 1)
                        return 'D';
                    if(i == 2)
                        return 'R';
                    return 'U';
                }
            }
            
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> mapa[i][j];
            if(mapa[i][j] == 'E'){
                xE = i;
                yE = j;
            }
        }
    }

    BFS(xE, yE);
    //cout << "sol de 1 1 :" << sol[1][1] << '\n';

    /*for(int i = 1; i <=  N; i++){
        cout << '\n';
        for(int j = 1; j <= M; j++)
            cout << sol[i][j] << " ";
    }
    cout << '\n';*/

    cin >> Q;
    ll a, b;
    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        cout << querry(a, b) << '\n';
    }
    return 0;
}