#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    string s1 = "qwertasdfgzxcvb", s2 = "yuiophjklnm";

    int flag = -1;
    for(int i = 0; i < s1.size(); i++){
        if(s[0] == s1[i])
            flag = 1;
    }

    for(int i = 0; i < s2.size(); i++){
        if(s[0] == s2[i])
            flag = 0;
    }

    for(int i = 1; i < s.size(); i++){
        if(flag == -1)
            break;

        if(flag == 1){
            flag = 0;
            bool auxflag = true;
            for(int j = 0; j < s2.size(); j++){
                if(s[i] == s2[j])
                    auxflag = false;
            }
            if(auxflag){
                flag = -1;
                break;
            }
        }else{
            flag = 1;
            bool auxflag = true;
            for(int j = 0; j < s1.size(); j++){
                if(s[i] == s1[j])
                    auxflag = false;
            }
            if(auxflag){
                flag = -1;
                break;
            }
        }
    }

    if(flag == -1)
        cout << "no" << '\n';
    else
        cout << "yes" << '\n';

    return 0;
}