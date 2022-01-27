#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, w, d; cin >> n >> w >> d;
	vector<int> adj[n+1];
	int route[n];
	bool visited[n+1];
	int dist[n+1];
	for (int i = 0; i < w; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 0; i < n; i++){
		cin >> route[i];
	}
	for (int i = 0; i < d; i++){
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		int a, b; cin >> a >> b;
		swap(route[a-1], route[b-1]);
		queue<pair<int,int>> q;
		q.push({1,0});
		visited[1] = 1;
		while(!q.empty()){
			int a = q.front().first; 
			int t = q.front().second; q.pop();
			if (t < n-1){
				int curTrain = route[t];
				if (curTrain == a){
					int nextTrain = route[t+1];
					if (!visited[nextTrain]){
						visited[nextTrain] = 1;
						q.push({nextTrain, t+1});
						dist[nextTrain] = t + 1;
					}
				}
			}
			for (int b : adj[a]){
				if (!visited[b]){
					visited[b] = 1;
					q.push({b,t+1});
					dist[b] = t + 1;
				}	
			}
			if (t < n-1){
				q.push({a, t+1});
			}
		}
		cout << dist[n] << "\n";
	}
	
}