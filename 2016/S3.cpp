#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

int ans = 0, numLeft = 0;
int nodeAns;
bool visited[100000];
vector<int> graph[100000];

void dfs(int node, int dep){
	if (dep > ans){ 
		ans = dep;
		nodeAns = node;
	}
	numLeft++;
	for(int u: graph[node]){
		if (visited[u]) continue;
		visited[u] = 1;
		dfs(u,dep+1);
		}
	}

int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, y, a;
    cin >> n >> m;
    bool arePho[n];
    int degree[n];
    memset(arePho, 0, sizeof(arePho));
    memset(degree, 0, sizeof(degree));
    while(m--){
		cin >> x;
		arePho[x] = 1;
		}
	for (int i=0;i<n-1;i++){
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
		degree[x]++;
		degree[y]++;
		}
	for (int i=0;i<n;i++){
		if (degree[i]==1 && !arePho[i]){
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				a = q.front();
				q.pop();
				auto it = graph[a].begin();
				while (it != graph[a].end()){
					int b = *it;
					if(degree[b] <= 2 && !arePho[b]){
						q.push(b);
						}
					graph[b].erase(find(graph[b].begin(),graph[b].end(),a));
					graph[a].erase(it);
					degree[b]--;
					degree[a]--;
					}
				}
			}
		}
	for(int i=0;i<n;i++){
		if(arePho[i]){
			memset(visited, 0, sizeof(visited));
			visited[i] = 1;
			dfs(i,0);
			memset(visited,0,sizeof(visited));
			visited[nodeAns] = 1;
			dfs(nodeAns,0);
			break;
			}
		}
	/*for (int i = 0; i < n;i++){
		
			cout << i << ": ";
			for(int u : graph[i]) cout << u << " ";
			
		cout << "\n";
		}
	cout << numLeft << " " << ans << "\n";*/
	cout << ((numLeft/2)-1)*2 - ans;
	}