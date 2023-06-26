#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

#define opti_io cin.tie(0);ios_base::sync_with_stdio(0)
#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(i64 n, vi &arr){
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

int main(){
    //opti_io;

    i64 N;
    string s;

    std::cin >> N;
    std::cin >> s;

    stack<char> p;
    i64 c = 0;

    for(int i = 0; i < N; i++){
        if(s[i] == '('){
            c++;
            p.push(s[i]);
            continue;
        }
        if(s[i] == ')'){
            if(c){
                while(p.top() != '(')
                    p.pop();
                p.pop();
                c--;
            }else{
                p.push(s[i]);
            }
            continue;
        }
        if(s[i] != '(' && s[i] != ')'){
            p.push(s[i]);
        }
    }
    
    vector<char> ans(p.size());
    int it = 0;
    while(!p.empty()){
        ans[it] = p.top();
        it++;
        p.pop();
    }

    for(int i = ans.size() - 1; i >= 0; i--)
        std::cout << ans[i];
    std::cout << '\n';

    return 0;
}