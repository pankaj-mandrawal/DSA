/** 
 *    author:  pankaj_m05
 *    created: 22.09.2020 20:21:27
**/
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& d, int s, int p, int dis) {
	d[s] = dis;
	for (auto& v : adj[s]) {
		if (v != p) {
			dfs(adj, d, v, s, dis + 1); 
		}
	}
	return;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> d(n, 0);   
  for (int i = 1; i < n; ++i) {
  	int u, v;
  	cin >> u >> v;
  	adj[u - 1].emplace_back(v - 1);
  	adj[v - 1].emplace_back(u - 1);
  }
  dfs(adj, d, 0, -1, 0);
  for (int i = 0; i < n; ++i) {
  	cout << d[i] << ' ';
  }
  cout << '\n';
  return 0;
}