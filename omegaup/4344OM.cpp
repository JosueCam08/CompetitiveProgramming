/*
* Date: 06/04/2021
* Link: https://omegaup.com/arena/problem/Sofia-y-Griff/
* Finished: No
*/
#include <bits/stdc++.h>

using namespace std;
bool visitado[500][500];
int arr[502];


int main(){

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int>sum[n + 1];


    for(int i = 0; i < n; i++){
        sum[i].push_back( arr[i] );
        visitado[i][arr[i]] = true;
    }
        

    int vectam;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            vectam = sum[j].size();
            for(int s = 0; s < vectam; s++){
                if( !visitado[j][ sum[j][s] + arr[i] ] && sum[j][s] + arr[i] <= k  ){
                    sum[j].push_back( sum[j][s] + arr[i] );
                    visitado[j][ sum[j][s] + arr[i] ] = true;
                }
            }
        }
    }

    queue <int> cola;
    set<int>conj;
    cola.push(0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < sum[i].size(); j++){
            for(int s = i + 1; s < n; s++){
                if( sum[i][j] + arr[s] == k && conj.find(sum[i][j]) == conj.end() ){
                    cola.push(sum[i][j]);
                    conj.insert(sum[i][j]);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < sum[n-1].size(); i++){
        if(sum[n-1][i] == k && conj.find(sum[n-1][i]) == conj.end()){
            cola.push(sum[n-1][i]);
            conj.insert(sum[n-1][i]);
        }
    }

    cout << cola.size() << '\n';
    while(!cola.empty()){
        cout << cola.front() << " ";
        cola.pop();
    }
   return 0;
}