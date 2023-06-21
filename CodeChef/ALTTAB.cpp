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
typedef int64_t i64;
typedef vector<i64> vi;

int main(){
    opti_io;

    int n;
    cin >> n;

    stack<string> programs;
    set<string> bucket;
    string s;

    for(int i = 0; i < n; i++){
        cin >> s;
        programs.push(s);
    }

    while(!programs.empty()){
        s = programs.top();
        programs.pop();

        if(bucket.count(s))
            continue;
        bucket.insert(s);

        int m = s.size();
        cout << s[m - 2] << s[m - 1];
    }

    cout << '\n';

    return 0;
}