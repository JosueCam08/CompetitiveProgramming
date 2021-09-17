/*
* Date: 12 / 09 / 2021
* Link: https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/A1
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

int solve(){
    int n, cont = 0, it = 0;
    string s;
    bool hand; // X Left O Right

    cin >> n >> s;

    while(s[it] == 'F' && it < n)
        it++;

    if(it == n)
        return 0;

    if(s[it] == 'X')
        hand = true;
    else
        hand = false;

    for(int i = it + 1; i < n; i++){
        if(s[i] == 'X' && !hand){
            cont++;
            hand = true;
            continue;
        }
        if(s[i] == 'O' && hand){
            cont++;
            hand = false;
        }
    }
    return cont;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
        cout << "Case #" << i << ": " << solve() << '\n';

    return 0;
}