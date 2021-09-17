/*
* Date: 12 / 09 / 2021
* Link: https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/B
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N, M, A, B;
    cin >> N >> M >> A >> B;

    if( A < (N + M - 1) || B < (N + M - 1) ){
        cout << "Impossible" << '\n';
        return;
    }

    int mat[N + 1][M + 1];
    for(int i = 1; i < N - 1; i++){ // Llenar todo el cuadro excepto bordes
        for(int j = 1; j < M - 1; j++)
            mat[i][j] = 2;
    }

    for(int j = 1; j < M - 1; j++) // Llenar fila uno de numeros grandes
        mat[0][j] = 2;
    for(int i = 1; i < N - 1; i++) // Llenar columnas 0 y M - 1
        mat[i][0] = mat[i][M - 1] = 1;
    for(int j = 0; j < M; j++) // Llenar fila N - 1
        mat[N - 1][j] = 1;

    mat[0][0] = A - (M + N - 2);
    mat[0][M - 1] = B - (M + N - 2);

    cout << "Possible" << '\n';
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cout << mat[i][j] << " ";
        cout << '\n';
    }
    return;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}