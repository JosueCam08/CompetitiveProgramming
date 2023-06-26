#include <iostream>
using namespace std;

int check(int p1, int lp1, int p2, int lp2){
    if(p1 == 11 && p2 == 11) return 0;
    if(lp1 == 11 &&  p2 > lp2) return 0;
    if(lp2 == 11 &&  p1 > lp1) return 0;
    if(p1 == lp1 && p2 == lp2) return 2;
    if (p1 < lp1 || p2 < lp2) return 0;
    return 1;
}

int main() {
	int n, p1 = 0, p2 = 0, lp1 = 0, lp2 = 0, i = 0, aux;
	bool play = true;
	string s;
	cin >> n;
	int fi = n;
	
	while(p1 == 0 && p2 == 0 && i < n){
	    cin >> s;
	    if(s[1] == '-'){
            p1 = stoi(s.substr(0, 1));
            p2 = stoi(s.substr(2, s.length() - 2));
        }
    
        else{
            p1 = stoi(s.substr(0, 2));
            p2 = stoi(s.substr(3, s.length() - 3));
        }
        
        
	    i++;
	}
	
	if( ((p1 + p2)%4 == 3) || (p1 + p2)%4 ==0) swap(p1, p2);
	
	aux = check(p1, lp1, p2, lp2);
	if (aux == 0){
	  play = false;
	  fi = i;  
	}
	
	for(i; i < n; i++){
	    if(play == false) break;
	    cin >> s;
	    lp1 = p1;
	    lp2 = p2;
	    
	    
	    if(s[1] == '-'){
            p1 = stoi(s.substr(0, 1));
            p2 = stoi(s.substr(2, s.length() - 2));
        }
    
        else{
            p1 = stoi(s.substr(0, 2));
            p2 = stoi(s.substr(3, s.length() - 3));
        }
        
        
        if( ((p1 + p2)%4 == 3) || (p1 + p2)%4 ==0) swap(p1, p2);
        
	    aux = check(p1, lp1, p2, lp2);
	    
	    
	    if(aux == 0){
	        play = false;
	        fi = i+1;
	        break;
	    }
	} 
	
	if(play) cout << "ok" << endl;
	else cout << "error " << fi << endl;
	
	return 0;
}