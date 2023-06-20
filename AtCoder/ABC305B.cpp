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

    int sol[] = {0, 3, 1, 4, 1, 5, 9};
    char c1, c2;

    cin >> c1 >> c2;
    if(c2 < c1)
        swap(c1, c2);

    int sum = 0;
    for(int i = c1 - 'A' + 1; i <= c2 - 'A'; i++)
        sum += sol[i];

    cout << sum << '\n';
    return 0;
}