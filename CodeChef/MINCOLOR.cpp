#include <iostream>
#include <math.h>

using namespace std;

int movX[] = {0, -1, 0, 1};
int movY[] = {-1, 0, 1, 0};

void solve(){
    int N, M;
    cin >> N >> M;

    int x_1, x_2, y_1, y_2;
    cin >> x_1 >> x_2 >> y_1 >> y_2;

    bool flag = ((x_1 + x_2) % 2 == 0);
    int sum = 0, val = 1;
    for(int i = 1 ; i <= N; i++){
        if(flag){
            sum = 1;
            val = 1;
        }else{
            sum = -1;
            val = 2;
        }
        for(int j = 1; j <= M; j++){
            bool neig = true;
            for(int k = 0; k < 4; k++){
                if(i + movX[k] == y_1 && j + movY[k] == y_2)
                    neig = false;
            }
            if(y_1 == i && y_2 == j)
                cout << 2 << " ";
            else 
                if(neig)
                    cout << val << " ";
                else 
                    if(val == 2)
                        cout << 3 << " ";
                    else
                        cout << val << " ";
            val += sum;
            sum *= -1;
        }
        cout << '\n';
        flag = !flag;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}