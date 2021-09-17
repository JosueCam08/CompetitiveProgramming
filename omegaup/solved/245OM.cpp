/*
* Date: 25 / 08 / 2021
* Link: https://omegaup.com/arena/problem/DesEdificios/
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    
    long long arr[n + 1];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    long long maxArea = 0, largo, ancho, lastancho, currentarea;
    stack<long long> pstack, hstack;
    for(int i = 0; i < n;  i++){
        lastancho = LONG_MAX;
        while (!pstack.empty() && hstack.top() > arr[i])
        {
            lastancho = pstack.top();
            currentarea = (i - pstack.top()) * hstack.top();
            pstack.pop(); hstack.pop();
            maxArea = max(maxArea, currentarea);
        }

        if(pstack.empty() || arr[i] > hstack.top()){
            hstack.push(arr[i]);
            if(i < lastancho)
                pstack.push(i);
            else    
                pstack.push(lastancho);
        }
    }

    while(!pstack.empty()){
        currentarea = (n - pstack.top()) * hstack.top();
        pstack.pop(); hstack.pop();
        maxArea = max(maxArea, currentarea);
    }

    cout << maxArea;

    return 0;
}