#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;


	
int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int cost = 0;
    while(n != 1){
		//cout << n << "\n";
		if (n%2 == 0){
			n /= 2;
			cost++;
			}
		else {
			for(int i = 3; i <= n; i += 2){
				//cout << "* " << i << " ";
				if (n % i == 0){
					int dif = n/i;
					cost += (n-dif)/dif;
					n -= dif;
					break;
					}
				}
		}
		}
	cout << cost;
	}