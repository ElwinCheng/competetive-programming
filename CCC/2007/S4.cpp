#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int n;
vector<int> td[10000], bu[10000];

int bfs(){
	if (n == 1) return 1;
	int dp[10000] = {0};
	dp[n] = 1;
	bool visited[10000] = {0};
	priority_queue<int> q;
	q.push(n);
	visited[n] = 1;
	while(!q.empty()){
		int s = q.top();
		//cout << s << "\n";
		q.pop();
		for (auto k : td[s]) dp[s] += dp[k];
		for (auto u : bu[s]){
			//cout << u << " ";
			if (visited[u]) continue;	
			visited[u] = 1;
			q.push(u);
			}
		//cout << count << "\n";
		}
	return dp[1];
	
	}

void solve(){
	cin >> n;
	int x, y;
	while(cin >> x >> y){
		if (x == 0) break;
		td[x].pb(y);
		bu[y].pb(x);
		}
	cout << bfs();
	
	}
	
int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
	}