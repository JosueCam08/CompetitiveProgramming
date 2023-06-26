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
        std::cin >> arr[i];
    return;
}

int main(){
    //opti_io;

    int N, itb, ite;
    string s1, s2, s;

    std::cin >> N;
    map< string, vector<int> > bucket;
    vector<string> svector;
    bool flag = false;

    for(int i = 0; i < N; i++){
        std::cin >> s1;
        svector.push_back(s1);   
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j)
                continue;
                
            s = svector[i] + svector[j];

            itb = 0; ite = s.size() - 1;
            flag = true;
            while(itb < ite){
                if(s[itb] != s[ite]){
                    flag = false;
                    break;
                }
                itb++;
                ite--;
            }

            if(flag){
                std::cout << "Yes\n";
                return 0;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            s = svector[i] + svector[j];

            itb = 0; ite = s.size() - 1;
            flag = true;
            while(itb < ite){
                if(s[itb] != s[ite]){
                    flag = false;
                    break;
                }
                itb++;
                ite--;
            }

            if(flag){
                std::cout << "Yes\n";
                return 0;
            }
        }
    }

    std::cout << "No\n";
    return 0;
}