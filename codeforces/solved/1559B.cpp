/*
* Date: 18 / 08 / 2021
* Link: https://codeforces.com/problemset/problem/1559/B
* Finished: Yes
*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    string s;

    cin >> n >> s;

    int it = 0;
    if(s[0] == '?'){
        while (it + 1 < n && s[it + 1] == '?')
            it++;
        if(it == (n - 1)){
            for(int i = 0; i < n; i++)
                if(i % 2 == 0)
                    s[i] = 'R';
                else
                    s[i] = 'B';
            cout << s << endl;
            return;
        }else{
            if((it + 1) % 2 == 0){
                if(s[it + 1] == 'R'){
                    for(int i = 0; i <= it; i++)
                        if(i % 2 == 0)
                            s[i] = 'R';
                        else
                            s[i] = 'B';
                }else{
                    for(int i = 0; i <= it; i++)
                        if(i % 2 == 0)
                            s[i] = 'B';
                        else
                            s[i] = 'R';
                }
            }else{
                if(s[it + 1] == 'B'){
                    for(int i = 0; i <= it; i++)
                        if(i % 2 == 0)
                            s[i] = 'R';
                        else
                            s[i] = 'B';
                }else{
                    for(int i = 0; i <= it; i++)
                        if(i % 2 == 0)
                            s[i] = 'B';
                        else
                            s[i] = 'R';
                }
            }
        }
    }
    
    it++;
    int j;
    while(it < n){
        while(it < n && s[it] != '?')
            it++;
        if(it == n){
            cout << s << endl;
            return;
        }

        j = it;
        while(it + 1 < n && s[it + 1] == '?')
            it++;
        
        if(s[j - 1] == 'R'){
            for(int i = j; i <= it; i++){
                if( i % 2 == j % 2)
                    s[i] = 'B';
                else
                    s[i] = 'R';
            }
        }else{
            for(int i = j; i <= it; i++){
                if( i % 2 == j % 2)
                    s[i] = 'R';
                else
                    s[i] = 'B';
            }
        }
        it++;
    }
    cout << s << endl;
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}