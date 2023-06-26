#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

vector<long long> arr(200001);

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];


    bool left = true;
    long long lmin = -1, rmin = -1, mid = -1;
    long long maxi = 0;
    for(int i = 0; i < N - 1; i++){
        if(left){
            if(arr[i] <= arr[i + 1]){
                if(lmin == -1)
                    lmin = arr[i];
                continue;
            }else{
                mid = arr[i];
                left = false;
            }
        }else{
            if(arr[i] >= arr[i + 1]){
                continue;;
            }else{
                rmin = arr[i];
                left = true;
                if(lmin != -1)
                    maxi = max(maxi, min(mid - lmin, mid - rmin));
                lmin = rmin = mid = -1;
                i--;
            }
        }
    }

    if(rmin == -1 && mid != -1)
        maxi = max(maxi, min(mid - lmin, mid - arr[N - 1]));

    cout << maxi << '\n';
    return 0;
}