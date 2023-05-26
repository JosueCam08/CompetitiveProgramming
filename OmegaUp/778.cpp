#include <iostream>
#include <vector>

using namespace std;

typedef int64_t i64;

i64 n, it = 1;
vector<i64> arr(1002, 0);

struct node{
    i64 v = 0;
    i64 l = -1;
    i64 r = -1;
} arbol[1002];

void build(i64 v, i64 nodo){
    // Caso raiz
    if(it == 1){
        arbol[it++].v = v;
        return;
    }

    // Caso hijo izquierdo
    if(v < arbol[nodo].v){
        if(arbol[nodo].l == -1){
            arbol[nodo].l = it;
            arbol[it++].v = v;
        }else
            build(v, arbol[nodo].l);
        return;
    }

    // Caso hijo derecho
    if(arbol[nodo].r == -1){
        arbol[nodo].r = it;
        arbol[it++].v = v;
    }else
        build(v, arbol[nodo].r);
}

void preOrden(i64 nodo){
    if(nodo == -1)
        return;

    cout << arbol[nodo].v << " ";

    preOrden(arbol[nodo].l);
    preOrden(arbol[nodo].r);
    return;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = n - 1; i >= 0; i--)
        build(arr[i], 1);

    preOrden(1);
    cout << '\n';
    return 0;
}