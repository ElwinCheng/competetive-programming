#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int moves[5][4] = {{2,1,0,2},{1,1,1,1},{1,0,0,1},{0,3,0,0},{0,0,2,1}};
int dp[31][31][31][31];
int processed[31][31][31][31];

bool rec(int a, int b, int c, int d){
	int na, nb, nc, nd, nf = 0, nw = 0;
	bool state;
	//cout << a << " "<< b << " "<< c << " "<< d << " ";
	for (auto n : moves){
		
		na = a - n[0];
		nb = b - n[1];
		nc = c - n[2];
		nd = d - n[3];
		
		if (na < 0 || nb < 0 || nc < 0 || nd < 0){ 
			nf ++;
			continue;
		}
		else if (processed[na][nb][nc][nd]){
			state = dp[na][nb][nc][nd];
			}
		else {
			state = rec(na, nb, nc, nd);
			}
		if (!state){
			processed[a][b][c][d] = 1;
			dp[a][b][c][d] = 1;
			//cout << "1\n";
			return 1;
			}
		nw++;
		}
		
		processed[a][b][c][d] = 1;
		if (nw + nf == 5){ 
			dp[a][b][c][d] = 0;
			//cout << "0\n";
			return 0;
			}
		return 1;
			
		
	}
	
int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, a, b, c, d;
	cin >> t;
    while(t--){
		cin >> a >> b >> c >> d;
		memset(dp, 0, sizeof(dp));
		memset(processed, 0, sizeof(processed));
		if (rec(a,b,c,d)) cout << "Patrick\n";
		else cout << "Roland\n";
		/*for (int i = 0; i <=30; i ++){
			for (int j = 0; j <=30; j ++){
				for (int u = 0; u <=30; u ++){
					for (int v = 0; v <=30; v ++){
						if (processed[i][j][u][v]){
							cout << i << " " << j << " " << u << " " << v << " " << dp[i][j][u][v] << "\n";
							}
			}
			}
			}
			}*/
		}
	/*for (auto z : processed){
		for (auto x : z){
			for (auto v : x : processed){
				for (auto q : v){
					cout << 
			}
			}	
			}			
		}*/
	}