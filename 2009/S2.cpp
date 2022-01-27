#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
	
int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool visited[257] = {0};
    int r, c, ans =0;
    cin >> r >> c;
    bool g[r][c];
    bool cpy[r][c];
    for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> g[i][j];
			}
		}
	for (int i = r; i > 0; i--){
		memcpy(cpy, g, sizeof(g));
		for (int j = i; j < r; j++){
			for (int z = 0; z < c; z++){
				if (cpy[j][z] ^ cpy[j-1][z]) cpy[j][z] = 1;
				else cpy[j][z] = 0;
				}
			}
		/*for (int u = 0; u < r; u++){
			for (int v = 0; v < c; v++){
				cout << cpy[u][v] << " ";
				}
			cout << "\n";
			}*/
		//cout << "\n";
		int count = 0;
		for (int k = 0; k < c; k++){
			if (cpy[r-1][k]){
				count += pow(2,k);
				}
			}
		visited[count] = 1;
		}
	for (auto i : visited){
		//cout << i << " ";
		if (i) ans++;
		}
	cout << ans;
	}