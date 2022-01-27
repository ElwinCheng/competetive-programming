#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;


	
int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, k, w;
    cin >> t;
    while(t--){
		int pin, tot = 0;
		cin >> n >> k >> w;
		int rq[n+1];
		int dp[k+1][n+1];
		rq[0] = 0;
		for (int i = 1; i <= n; i++){
			cin >> pin;
			tot += pin;
			rq[i] = tot;
			}	
		memset(dp[0], 0, sizeof(dp[0]));
		for (int i = 1; i <= k; i++){
			for (int j = 0; j <= n; j++){
				if (j >= i*w) dp[i][j] = max((rq[j] - rq[j-w]) + dp[i-1][j-w], dp[i][j-1]);
				else dp[i][j] = 0;
				}
				
			}
		/*for (int i = 0; i <= k; i++){
			for (int j = 0; j <= n; j++){
				cout << dp[i][j] << " ";
				}
				cout << "\n";
			}*/
		cout << dp[k][n] << "\n";
		}
    
	}