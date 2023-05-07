#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

vector<long long> arr(1000001);

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> idx;
    for(int i = 1; i < N - 1; i++){
        if(arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
            idx.push_back(i);
    }

    long long maxi = -1;
    for(int i = 0; i < idx.size(); i++){
        int l = idx[i] - 1;
        int r = idx[i] + 1;
        long long cont = 1;
        while(l >= 0 && r < N && arr[l] == arr[r] && arr[l + 1] > arr[l]){
            cont += 2;
            l--;
            r++;
        }
        if(cont != 1)
            maxi = max(maxi, cont);
    }

    cout << maxi << '\n';
    return 0;
}