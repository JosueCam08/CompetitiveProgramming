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

int main(){
    opti_io;

    int t;
    cin >> t;

    vector< vector<char> > table(3, vector<char>(3, '.'));
    while(t--){
        bool flag = false;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                cin >> table[i][j];

        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < 3; j++)
        //         cout << table[i][j] << " ";
        //     cout << '\n';
        // }

        for(int i = 0; i < 3; i++)
            if(table[i][0] != '.' && table[i][0] == table[i][1] && table[i][1] == table[i][2]){
                cout << table[i][0] << '\n';
                flag = true;
                break;
            }

        if(flag)
            continue;

        for(int i = 0; i < 3; i++)
            if(table[0][i] != '.' && table[0][i] == table[1][i] && table[1][i] == table[2][i]){
                cout << table[0][i] << '\n';
                flag = true;
                break;
            }

        if(flag)
            continue;

        if(table[0][0] != '.' && table[0][0] == table[1][1] && table[1][1] == table[2][2]){
            cout << table[0][0] << '\n';
            flag = true;
        }

        if(flag)
            continue;

        if(table[0][2] != '.' && table[0][2] == table[1][1] && table[1][1] == table[2][0]){
            cout << table[1][1] << '\n';
            flag = true;
        }

        if(flag)
            continue;

        cout << "DRAW\n";
    }
    return 0;
}