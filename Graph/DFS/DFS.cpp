/**
  *    author: pankaj_m05
**/
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int s) {
	vis[s] = 1;
	for (auto& v : adj[s]) {
		if (!vis[v]) {
			dfs(adj, vis, v);
		}
	}
	return;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<bool> vis(n, 0);
  while (m--) {
  	int u, v;
  	cin >> u >> v;
  	adj[u - 1].emplace_back(v - 1);
  	adj[v - 1].emplace_back(u - 1);
  }
  dfs(adj, vis, 0);  
  return 0;
}
