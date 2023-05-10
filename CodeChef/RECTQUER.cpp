#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector< vector<int> > > bucket (302, vector< vector<int> > (302, vector<int> (11, 0)));
vector< vector<int> > mat(302, vector<int> (302));
int N, Q;

void fill_bucket(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= 10; k++){
                bucket[i][j][k] = bucket[i-1][j][k] + bucket[i][j-1][k] - bucket[i-1][j-1][k];
            }
            bucket[i][j][mat[i][j]]++;
        }
    }
    return;
}

int solve(int x_1, int y_1, int x_2, int y_2){
    int ans = 0;
    for(int k = 1; k <= 10; k++)
        if(bucket[x_2][y_2][k] - bucket[x_2][y_1 - 1][k] - bucket[x_1 - 1][y_2][k] + bucket[x_1 - 1][y_1 - 1][k] > 0)
            ans++;
    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> mat[i][j];

    fill_bucket();

    cin >> Q;
    int x_1, y_1, x_2, y_2;
    while(Q--){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        cout << solve(x_1, y_1, x_2, y_2) << '\n';
    }

    return 0;
}