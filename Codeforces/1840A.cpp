#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(){
    int n;
    string s;

    cin >> n >> s;

    char save;
    bool flag = true;

    for(int i = 0; i < s.size(); i++){
        save = s[i];
        i++;
        while(s[i] != save)
            i++;
        cout << save;
    }
    cout << '\n';
    return; 
}

int main(){

    int t;
    cin >> t;

    while (t--)
        solve();
    

    return 0;
}