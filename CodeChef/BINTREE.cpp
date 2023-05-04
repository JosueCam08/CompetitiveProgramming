#include <iostream>

using namespace std;

int getLevel(int n){
    if(n == 1)
        return 0;
    for(int i = 1; i <= 29; i++)
        if((1 << i) <= n && n < (1 << (i + 1)))
            return i;
    return 30;
}

int solve(long long i, long long j){
    int ilevel = getLevel(i), jlevel = getLevel(j);

    if(jlevel < ilevel){
        swap(ilevel, jlevel);
        swap(i, j);
    }

    int cont = jlevel - ilevel;

    while(jlevel != ilevel){
        jlevel--;
        j /= 2;
    }

    while(i != j){
        cont += 2;
        i /= 2;
        j /= 2;
    }

    return cont;
}

int main(){
    int N;
    cin >> N;

    long long i, j;

    while(N--){
        cin >> i >> j;
        cout << solve(i, j) << '\n';
    }

    return 0;
}