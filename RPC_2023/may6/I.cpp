#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>

using namespace std;

int movY [] = {1, 0, 0, 0, 1, -1, 1, 1};
int movX [] = {0, 1, 1, 1, 1, 1, 1, 0};

int n, N;

long long mat [(1 << 10) + 1][(1 << 10) + 1];
long long visitado [(1 << 10) + 1][(1 << 10) + 1];

bool solve(){
    set<long long> numbers;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            bool fig = true;

            if(mat[i][j] == 0){
                numbers.insert(0);
                continue;
            }

            if(!visitado[i][j]){
                if(numbers.count(mat[i][j]) > 0){
                    return false;
                }
                numbers.insert(mat[i][j]);

                for(int k = 0; k < 4; k++){
                    int c1x = i + movX[k];
                    int c1y = j + movY[k];
                    int c2x = i + movX[4 + k];
                    int c2y = j + movY[4 + k];
                    if(c1x >= 0 && c2x >= 0 && c1y < N && c2y < N){
                        //cout << "->(" << i << "," << j << ") " << "(" << c1x << "," << c1y << ") " << "(" << c2x << "," << c2y << ")\n";
                        if(mat[i][j] == mat[c1x][c1y] && mat[c2x][c2y] == mat[i][j]){
                            fig = false;
                            visitado[c1x][c1y] = 1;
                            visitado[c2x][c2y] = 1;
                        }
                    }
                }

                if(fig){
                    return false;
                }
            }
        }
    }

    if(numbers.count(0) != 1){
        return false;
    }
        
    return true;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    N = (1 << n);

    for(int i = 0; i < (1 << n); i++)
        for(int j = 0; j < (1 << n); j++){
            cin >> mat[i][j];
        }

    cout << solve() << '\n';
    return 0;
}