/*
* Date: 16 / 09 / 2021
* Link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3086
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    int fugas = 0, km = 0, antkm = 0;
    double gasperkm = (double)n/100.0, gas = 0.0, aux = 0.0, maxGas = 0.0;
    string s;

    while (1)
    {
        cin >> km >> s;
        gas += (double)(km - antkm) * (gasperkm + fugas);
        antkm = km;

        if(s == "Fuel"){
            cin >> s >> aux;
            gasperkm = aux/100;
            continue;
        }

        if(s == "Leak"){
            fugas++;
            continue;
        }

        if(s == "Gas"){
            cin >> s;
            maxGas = max(maxGas, gas);
            gas = 0;
            continue;
        }

        if(s == "Mechanic"){
            fugas = 0;
            continue;
        }

        if(s == "Goal"){
            maxGas = max(maxGas, gas);
            cout << fixed << setprecision(3) << maxGas << '\n';
            return;
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    string s;

    cin >> n >> s >> s >> n;
    while (n)
    {   
        solve(n);
        cin >> n >> s >> s >> n;
    }
    

    return 0;
}