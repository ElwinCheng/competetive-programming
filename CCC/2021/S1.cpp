#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	double ans = 0;
	int arr[n+1];
	int h[n];
	for (int i = 0; i <= n; i++){
		cin >> arr[i];
	}	
	for (int i = 0; i < n; i++){
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++){
		ans += (arr[i-1]+arr[i])*h[i-1];
	}
	ans = ans/2.0;
	printf("%f", ans);
}