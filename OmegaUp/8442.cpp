#include <iostream>
#include <vector>

using namespace std;

long long arr[1000002];
int N;

int solve(int arg1, int arg2){
    int cont = abs(arg1) + abs(arg2);

    int dif = (arr[1] + arg2) - (arr[0] + arg1);  
    int ant = arg2;
    for(int i = 1; i < N - 1; i++){
        bool flag = false;
        for(int j = -1; j <= 1; j++){
            if( (arr[i + 1] + j) - (arr[i] + ant) == dif ){
                ant = j;
                flag = true;
                if(j != 0)
                    cont++;
                break;
            }
        }
        if(!flag)
            return INT_MAX;
    }

    return cont;
}

int main(){

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    if(N == 1){
        cout << 0 << '\n';
        return 0;
    }

    int ans = INT_MAX;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            ans = min(ans, solve(i, j));

    cout << ((ans == INT_MAX) ? -1 : ans) << '\n';
    return 0;
}