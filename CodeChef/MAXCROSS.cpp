#include <iostream>
#include <vector>

using namespace std;

int N;
vector< vector<char> > mat;

void solve(int dx, int dy, vector< vector<int> > &ans){
    vector< vector<int> > visit (N + 2, vector<int>(N + 2, -1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(visit[i][j] != -1)
                continue;
            if(mat[i][j] == '.'){
                visit[i][j] = 0;
            }
            else{
                int cont = 0, ci = i, cj = j;
                while(mat[ci][cj] == 'X'){
                    cont++;
                    ci = ci + dx;
                    cj = cj + dy;
                }
                ci = i, cj = j;
                while(mat[ci][cj] == 'X'){
                    visit[ci][cj] = cont;
                    ci = ci + dx;
                    cj = cj + dy;
                }
            }
        }
    }
    for(int i = 1; i<= N; i++)
        for(int j = 1; j <= N; j++)
            ans[i][j] = max(ans[i][j], visit[i][j]);

    return;
}

int main(){
    
    cin >> N;
    mat.assign(N + 2, vector<char>(N + 2, '.'));

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> mat[i][j];

    int movX[] = {0, 1, 1, 1};
    int movY[] = {1, 0, 1, -1};

    vector< vector<int> > ans(N + 2, vector<int> (N + 2, 0));
    for(int i = 0; i < 4; i++)
        solve(movX[i], movY[i], ans);

    for(int i = 1; i<= N; i++){
        for(int j = 1; j <= N; j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}