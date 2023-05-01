#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;

    cin >> t;

    while(t--){
        string s;
        stack<char> pila;

        cin >> s;
        int flag = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                pila.push(s[i]);
            else{
                if( !pila.empty() && 
                    ((s[i] == ')' && pila.top() == '(') ||
                    (s[i] == ']' && pila.top() == '[') ||
                    (s[i] == '}' && pila.top() == '{')) ){
                        pila.pop();
                    }else{
                        cout << "NO\n";
                        flag = 0;
                        break;
                    }
            }
        }

        if(flag && !pila.empty())
            cout << "NO\n";

        if(flag && pila.empty())
            cout << "SI\n";
    }

    return 0;
}