#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef int64_t i64;

void solve(){
    i64 N;
    cin >> N;

    vector<i64> A(N), B(N);
    set<i64> min_elements;
    multiset<i64> arr;
    map<i64, vector<i64> > index;


    for(int i = 0; i < N; i++){
        cin >> A[i];
        index[A[i]].push_back(i);
        min_elements.insert(A[i]);
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
        index[B[i]].push_back(i);
        min_elements.insert(B[i]);
    }

    i64 k = 0, ans;
    
    for(int i = 0; i < N; i++)
        arr.insert(min(A[i], B[i]));
    auto itmin = arr.begin(), itmax = arr.end();
    ans = *(--itmax) - *(itmin);

    for(auto cmin : min_elements){
        if(k++ == N)
            break;

        
        bool flag = false;
        for(int i = 0; i < index[cmin].size(); i++){
            if(max(A[index[cmin][i]], B[index[cmin][i]]) != cmin){
                arr.erase(cmin);
                arr.insert(max(A[index[cmin][i]], B[index[cmin][i]]));
            }else{
                flag = true;
                break;
            }
        }

        if(flag)
            break;

        auto itmin = arr.begin(), itmax = arr.end();
        ans = min(ans, *(--itmax) - *(itmin));
    }

    cout << ans << '\n';
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