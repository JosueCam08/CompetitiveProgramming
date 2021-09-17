/*
* Date: 29 / 08 / 2021
* Link: https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
* Finished: 
*/

#include <bits/stdc++.h>

using namespace std;

bool isVowels(char c){
    if( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    return false;
}

int solve(){
    string s;
    cin >> s;

    map<char, int> letters;
    char maxV, maxC;
    int contV = 0, contC = 0, nV = 0, nC = 0;

    for(int i = 0; i < s.length(); i++){
        letters[ s[i] ]++;
        if( isVowels(s[i]) ){
            nV++;
            if( letters[ s[i] ] > contV ){
                contV = letters[ s[i] ];
                maxV = s[i];
            }
        }else{
            nC++;
            if( letters[ s[i] ] > contC ){
                contC = letters[ s[i] ];
                maxC = s[i];
            }
        }
    }

    int ansV, ansC;
    ansV = nC + (nV - contV) * 2;
    ansC = nV + (nC - contC) * 2;
    return min(ansV, ansC);
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