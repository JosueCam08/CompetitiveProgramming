/*
* Date: 17 / 08 / 2021
* Link: https://codeforces.com/problemset/problem/1559/A
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int arr[n];
    int mini, itmin = 0, maxi, itmax = 0;

    cin >> arr[0];
    mini = maxi = arr[0];
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        if(arr[i] < mini){
            mini = arr[i];
            itmin = i;
        }
        if(arr[i] > maxi){
            maxi = arr[i];
            itmax = i;
        }
    }

    int aux;
    while (maxi != mini)
    {
        for(int i = 0; i <= abs(itmin - itmax)/2; i++){
            aux = arr[min(itmax, itmin) + i] & arr[max(itmax, itmin) - i];
            arr[min(itmax, itmin) + i] = aux;
            arr[max(itmax, itmin) - i] = aux;
        }

        maxi = mini = arr[0];
        itmin = itmax = 0;
        for (int i = 1; i < n; i++){
            if(arr[i] < mini){
                mini = arr[i];
                itmin = i;
            }
            if(arr[i] > maxi){
                maxi = arr[i];
                itmax = i;
            }
        }   
    }
    cout << mini << '\n';
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

}
