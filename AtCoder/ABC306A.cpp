#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define ifor(a, b) for(int i = a; i < b; i++)

typedef int64_t i64;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    i64 N;
    string s;

    cin >> N >> s;

    ifor(0, N){
        cout << s[i] << s[i];
    }
    cout << '\n';

    return 0;
}
