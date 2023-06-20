#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef int64_t i64;

int main(){

    int N;
    cin  >> N;

    switch (N % 5)
    {
    case 0:
        cout << N << '\n';
        break;
    
    case 1:
        cout << N - 1 << '\n';
        break;
    
    case 2:
        cout << N - 2 << '\n';
        break;

    case 3:
        cout << N + 2 << '\n';
        break;

    case 4:
        cout << N + 1 << '\n';
        break;
    }
    
    return 0;
}