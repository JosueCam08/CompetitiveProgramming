#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(){
    int N;
    cin >> N;

    vector<int> childs(N);

    for(int i = 0; i < N; i++)
        cin >> childs[i];

    sort(childs.begin(), childs.end());

    int sum = 0, i = 0;
    while(i < N && sum + childs[i] < N){
        sum += childs[i];
        i++;
    }

    return i;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << '\n';

    return 0;
}