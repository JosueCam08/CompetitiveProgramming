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

int main(){
    opti_io;

    int t;
    cin >> t;

    while(t--){
        int cx, cy;
        bool flag = true;
        char mat[8][8];
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++){
                cin >> mat[i][j];
                if(mat[i][j] != '.'){
                    if(flag){
                        cx = i;
                        cy = j;
                        flag = false;
                    }
                }
            }

        while(cx < 8 && mat[cx][cy] != '.'){
            cout << mat[cx][cy];
            cx++;
        }
        cout << '\n';
    }
    return 0;
}