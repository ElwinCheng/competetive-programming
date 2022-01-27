#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

void solve(){
	
	}
	
int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, fst, scnd;
    cin >> n;
    int dp[n+1][n+1]; // largest riceball of length column starting at position row (first riceball is position 1)
    bool cnctd[n+1][n+1]; // if riceball(s) of length column starting at position row is able to be combined
    memset(cnctd, 0, sizeof(cnctd));
    memset(cnctd[1], 1, sizeof(cnctd[1]));
    for (int i = 1; i <= n; i++){
		cin >> dp[1][i];
		cnctd[1][i] = 1;
		}
	for (int i = 1; i < n; i++){
		if (dp[1][i] == dp[1][i+1]){
			dp[2][i] = 2*dp[1][i];
			cnctd[2][i] = 1;
			} 
		else dp[2][i] = max(dp[1][i], dp[1][i+1]);
		}
	for (int i = 3; i <= n; i++){
		for (int j = 1; j <= n-i+1; j++){
			for (int v = 1; v < i; v++){ // iterate and check if two same size riceballs are adjacent
				fst = dp[v][j], scnd = dp[i-v][j+v];
				if (fst == scnd && cnctd[v][j] && cnctd[i-v][j+v]){
					dp[i][j] = fst + scnd;
					cnctd[i][j] = 1;
					}
				} // iterate and check if two riceballs with same size are 1 apart
			for (int v = 1; v <= i-2; v++){  // length of first rice ball
				for (int u = 1; u < i-v; u++){ // length of middle riceball
					fst = dp[v][j], scnd = dp[(i-v)-u][j+v+u];
					//cout << fst << " " << scnd << " " << cnctd[v][j] << " " << cnctd[(i-v)-u][j+v+u] << " " << cnctd[u][j+v] << " ";
					if (fst == scnd && cnctd[v][j] && cnctd[(i-v)-u][j+v+u] && cnctd[u][j+v]){ // check if all three parts are connected
						dp[i][j] = fst + scnd + dp[u][j+v];
						cnctd[i][j] = 1;
						}
					}
				}
			if (!cnctd[i][j]) dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]);
			}
		}
	/*for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n-i+1; j++){
			cout << dp[i][j] << " ";

			}
			cout << "\n";
		}*/
	cout << dp[n][1];
	}