/*
* Date: 07 / 09 / 2021
* Link: https://omegaup.com/arena/Competencia-Abierta-2021-1/practice/#problems/Taxis-2021-Fase-2-Examen-1
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

int ans[100000 + 1];

/*struct nodo
{
    int num;
    nodo *anterior;
    nodo *siguiente;
}*ini, *fin;
*/
struct dato
{
    int persona;
    int dia;
    bool entrada = false;
};

bool sortArr(dato A, dato B){
    if(A.dia < B.dia)
        return true;
    if(A.dia > B.dia)
        return false;
    return A.entrada;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    dato a, b;
    cin >> n;

    dato arr [(4 * n) + 1];
    for(int i = 0; i < 2 * n; i += 2){
        cin >> a.dia >> b.dia;
        a.persona = b.persona = i / 2;
        a.entrada = true;
        arr[i] = a; arr[i + 1] = b;
    }

    sort(arr, arr + (2 * n), sortArr);

    list<int>taxis;
    int contTaxis = 0;

    for(int i = 0; i < (2 * n); i++){
        if(arr[i].entrada){
            if(taxis.empty()){
                contTaxis++;
                ans[ arr[i].persona ] = contTaxis;
            }else{
                ans[ arr[i].persona ] = taxis.front();
                taxis.pop_front();
            }
        }else{
            taxis.push_back( ans[ arr[i].persona ] );
        }
    }

    cout << contTaxis << '\n';
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}