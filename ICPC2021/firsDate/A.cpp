#include <bits/stdc++.h>

using namespace std;

long long B, N;
double sumAreas = 0.0;
vector< pair<long long, long long> > bolsas; // first -> weight secod -> price

bool compare( pair<long long, long long> A, pair<long long, long long>B ){
    if( double( A.first * B.second <  A.second * B.first ) )
        return true;
    else
        return false;
}

long long dp(long long pos, long long peso, long long total){
    if(pos >= B || peso >= sumAreas){
        if(peso >= sumAreas)
            return total;
        else
            return LONG_MAX;
    }
    long long div = (sumAreas - peso) / bolsas[pos].first;

    long long c1 = dp(pos + 1, peso + (bolsas[pos].first * div), total + (bolsas[pos].second * div));
    long long c2 = dp(pos + 1, peso + (bolsas[pos].first * (div + 1)), total + (bolsas[pos].second * (div +  1)));
    long long c3 = dp(pos + 1, peso, total);
    return min( c1, min(c2, c3) );
}

double areaTriangulo(long long A, long long B, long long C){
    double s = (double)(A + B + C) / 2.0;
    double ans = sqrt(s*(s - A)*(s - B)*(s - C));
    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    cin >> B >> N;

    long long a,b, c;
    
    for(int i = 0; i < B; i++){
        cin >> a >> b;
        bolsas.push_back(make_pair((a * 30), b));
    }

    
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        sumAreas += areaTriangulo(a, b, c);
    }
    sort(bolsas.begin(), bolsas.end(), compare);
    cout << dp(0, 0, 0) << '\n';




    return 0;
}