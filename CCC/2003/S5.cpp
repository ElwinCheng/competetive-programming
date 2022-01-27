#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;


void solve(){
	
	int a, b, r, c, d, x, y, w, ans = 100001;
	cin >> c >> r >> d;
	vector<pair<int,int>> g[c+1];
	bool processed[c+1] = {0};
	int dist[c+1] = {0};
	int dest[d];
	priority_queue<pair<int,int>> pq;
	while(r--){
		cin >> x >> y >> w;
		g[x].pb(mp(y,w));
		g[y].pb(mp(x,w));
		}
	for (int i = 0; i < d; i++){
		cin >> dest[i];
		} 
	pq.push(mp(0,1));
	dist[1] = 100001;
	while(!pq.empty()){
		a = pq.top().second;
		//cout << a << "\n";
		pq.pop();
		if (processed[a]) continue;
		processed[a] = 1;		
		for (auto u : g[a]){
			b = u.first;
			w = u.second;
			//out << w << " " << dist[a] << " " <<  dist[b];
			if (w > dist[b] && dist[a] > dist[b] ){
				//cout << "made it\n";
				dist[b] = min(w, dist[a]);
				pq.push(mp(dist[b], b));
				}
			}
		}
	for (int u : dest){
		//cout << dist[u] << "\n";
		if (dist[u] < ans){
			ans = dist[u];
			}
		}
	
	cout << ans;
	}
	
int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
	}