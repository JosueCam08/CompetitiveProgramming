/*
* Date: 119 / 08 / 2021
* Link: https://codeforces.com/problemset/problem/1560/A
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    vector<int> arr;
    int it = 0, x = 1;

    while (it < 1000)
    {
        if(x % 3 != 0 && x % 10 != 3){
            arr.push_back(x);
            it++;
        }
        x++;
    }

    while (t--)
    {
        cin >> x;
        cout << arr[x - 1] << endl;
    }
    
    

    return 0;
}