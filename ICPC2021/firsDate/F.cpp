#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int h,m,s,ms;
float t_error;

void convert_time(string time){
        h = (time[0] - '0')*10 + time[1] - '0';
        m = (time[3] - '0')*10 + time[4] - '0';
        s = (time[6] - '0')*10 + time[7] - '0';
        ms = (time[9] - '0')*100 + (time[10] - '0')*10 +time[11] - '0';
}


void add_time(){
    int s_error, ms_error;
    s_error = t_error;
    ms_error = (t_error * 1000) - (s_error  * 1000);
    
    ms += ms_error;
    s += s_error;
    if (ms > 999){
        ms -= 1000;
        s++;
    }

    if (s >59){
            s-= 60;
            m++;
            if (m> 59){
                m-= 60;
                h++;
            }
        }

}

string change_time(string time){
    time[0] = '0' + h/10;
    time[1] = '0' + h % 10;

    time[3] = '0' + m/10;
    time[4] = '0' + m % 10;

    time[6] = '0' + s/10;
    time[7] = '0' + s % 10;

    time[9] = '0' + ms/100;
    time[10] = '0' + ((ms%100) /10);
    time[11] = '0' + ms % 10;

    return time;
}

void fix_time(string start, string end){
    convert_time(start);
    add_time();
    string n_start = change_time(start);
    convert_time(end);
    add_time();
    string n_end = change_time(end);
    cout << n_start << " --> "<< n_end << '\n';
}

int main() {
	
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, query;
    
    float time;
    string start, arrow , end, sub;
    cin >> n >> t_error;
    for(int i = 0; i < n; i++){
        cin >> query;
        getline(cin, start);
        cin >> start >>arrow >> end;
        cout << query<<'\n';
        fix_time(start, end);
        //---------------------------------------------
      	getline(cin >> ws, sub);
        cout << sub<< '\n' ;
       
        getline(cin, sub);
        if ( sub[0] > 31) cout << sub << '\n';
        cout << '\n';
    }

	return 0;
}



