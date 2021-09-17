/*
* Date: 12 / 09 / 2021
* Link: https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/A2
* Finished: No
*/

#include <bits/stdc++.h>

using namespace std;

#define NUM 1000000007

int solve(){
    long long n, cont = 0, it = 0;
    long long res = 0;
    string s;
    bool hand; // X Left O Right
    
    cin >> n >> s;

    while(s[it] == 'F' && it < n)
        it++;
    
    if(it == n)
        return 0;

    for(long long i = it + 1; i < n; i++){    
        if(s[i] == s[it]){
            it = i;
            continue;
        }
        if(s[i] == 'X' && s[it] == 'O'){
            res = (res +  (it + 1) * (n - i)) % NUM;
            //cout << it << " " << i << " " << n - i << '\n';
            it = i;
            continue;
        }
        if(s[i] == 'O' && s[it] == 'X'){
            res = (res +  (it + 1) * (n - i)) % NUM;
            //cout << it << " " << i << " " << n - i << '\n';
            it = i;
        }
    }

    return res;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
         cout << "Case #" << i << ": " << solve()  << '\n';

    return 0;
}