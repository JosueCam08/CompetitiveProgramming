#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

#define sortvi(arr) sort(arr.begin(), arr.end())
#define revsortvi(arr) sortvi(arr);reverse(arr.begin(), arr.end())
typedef int64_t i64;
typedef vector<i64> vi;

void readvi(i64 n, vi &arr){
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

void outputP(map<char, int>& myMap){
    vector< pair<int, char> > rep(myMap.size());

    int i = 0;
    for(auto v : myMap){
        rep[i] = make_pair(-v.second, v.first);
        i++;
    }

    sort(rep.begin(), rep.end());
    //reverse(rep.begin(), rep.end());

    int save = rep[0].first;

    i = 0;
    while(rep[i].first == save){
        cout << rep[i].second << " ";
        i++;
    }
    cout << '\n';
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    string s;
    vector< string > arr(100, "");

    int maxi = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++)
            arr[j] += s[j];
        maxi = max(maxi, (int)s.size());
    }

    for(int i = 0; i < maxi; i++){
        cout << i + 1 << ": ";

        vector< pair<int, char> > bucket(200, make_pair(0, 0));

        for(int j = 0; j < arr[i].size(); j++){
            bucket[arr[i][j]].first--;
            bucket[arr[i][j]].second = arr[i][j];
        }

        sort(bucket.begin(), bucket.end());

        vector<char> ans;
        ans.push_back(bucket[0].second);
        int it = 1;
        while(bucket[it].first == bucket[it - 1].first){
            ans.push_back(bucket[it].second);
            it++;
        }
        
        for(int k = 0; k < ans.size(); k++)
            cout << ans[k] << " \n"[k == (int)(ans.size() - 1)];
    }
}