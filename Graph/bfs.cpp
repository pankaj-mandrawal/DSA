/** 
 *    author:  pankaj_m05
 *    created: 22.09.2020 20:22:55
**/ 
#include<bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& d, int s) {
	vis[s] = 1;
	d[s] = 1;
	queue<int> q;
	q.emplace(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int& u : adj[v]) {
			if (!vis[u]) {
				vis[u] = 1;
				q.emplace(u);
				d[u] = d[v] + 1;
			}
		}
	}
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<bool> vis(n, 0);
  vector<int> d(n, 0);
  for (int i = 0; i < m; ++i) {
  	int u, v;
  	cin >> u >> v;
  	adj[u - 1].emplace_back(v - 1);
  	adj[v - 1].emplace_back(u - 1);
  }
  bfs(adj, vis, d, 0);
  return 0;
}