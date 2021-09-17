/*
* Date: 06/04/2021
* Link: https://codeforces.com/problemset/problem/1499/B?f0a28=1
* Finished: No
*/
#include <iostream>
#include <string>

int main(){
    int n;
    std::string s;
    bool band;

    std::cin >> n;
    while(n--){
        std::cin >> s;

        if(s.length() >= 5){
            std:: cout << "Yes" << '\n';
            continue;
        }

        band = false;
        for(int  i = 0; i < s.length()-2; i++){
            for(int j = i + 2; j < s.length(); j++){
                if( ( s[i] == '0' && s[j] == '0' ) || ( s[i] == '1' && s[j] == '1') || ( s[i] == '0' && s[j] == '1' ) )
                    band = true;
            }
            if(band)
                break;
        }

        if(band)
            std::cout << "Yes" << '\n';
        else
            std::cout << "No" << '\n'; 
    }

    return 0;
}