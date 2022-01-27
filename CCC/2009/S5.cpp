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
		
    int r, c, co;
    cin >> r >> c;
    int city[r][c];
    int d[r][c+1];
    memset(city, 0, sizeof(city));
    memset(d, 0, sizeof(d));
    cin >> co;
    int x, y, rd, b, dis;
    while(co--){
		cin >> x >> y >> rd >> b;
		y = r - y + 1;
		for (int i = max(0, y-1-rd); i < min(r, y+rd); i++){
			//cout << pow(rd,2) << " " << pow(i-(y-1),2) << " " << pow(rd,2) - pow(i-(y-1),2) << "\n";
			dis = (int)sqrt(pow(rd,2)-pow(i-(y-1),2));
			//cout << dis << "\n";
			d[i][max(0,x-1-dis)] += b;
			d[i][min(c,x+dis)] -= b;
			} 
		/*for (int i = max(0, y-1-rd); i < min(r,y+rd); i++){
			for (int j=max(0,x-1-rd); j < min(c,x+rd); j++){
				//cout << sqrt(pow(y-i-1,2)+pow(x-j-1,2)) << " ";
				if (sqrt(pow(y-i-1,2)+pow(x-j-1,2)) <= rd) city[i][j] += b;
				}
				//cout << "\n";
			}*/	
		}
		
	for (int i = 0; i < r; i++){
		city[i][0] = d[i][0];
		for (int j = 1; j < c; j++){
			city[i][j] = city[i][j-1] + d[i][j];
			}
		}
	int ans = 0, f = 0;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (city[i][j] > ans) ans = city[i][j];
				}
			}
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (city[i][j] == ans) f++;
				}
			}
		/*for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				cout << city[i][j] << " ";
				}
			cout << "\n";	
			}*/	
	cout << ans << "\n" << f;
	}