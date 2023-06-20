#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <limits>

using namespace std;

typedef int64_t i64;

int main(){

    int n, m;
    cin >> n >> m;

    pair<int, int> p1 = make_pair(INT_MAX, INT_MAX), p2 = make_pair(INT_MIN, INT_MIN);
    vector< vector <char> > mat(n + 2, vector<char> (m + 2));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '#'){
                p1.first = min(p1.first, i);
                p1.second = min(p1.second, j);
                p2.first = max(p2.first, i);
                p2.second = max(p2.second, j);
            }
        }

        if(mat[p1.first + 1][p1.second - 1] == '#')
            p1.second--;
        if(mat[p2.first - 1][p2.second + 1] == '#')
            p2.second++;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                if(i >= p1.first && i <= p2.first && j >= p1.second && j <= p2.second && mat[i][j] == '.'){
                    cout << i << " " << j << '\n';
                    return 0;
                }
            }
    
    return 0;
}