/*
Dijkstra's Shortest Path Algorithm
Problem_link: https://codeforces.com/contest/450/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, m, k;
vector<pair<int, int>> adj[N];
ll dis[N];
int vis[N];
int ans = 0;

struct Node
{
	int x;
	ll w;
	bool f;
	Node(int X, ll W, bool F) :x(X), w(W), f(F) {}

	bool operator<(const Node& a)const {
		if (w == a.w)return f > a.f;
		return w > a.w;
	}
};

priority_queue<Node> q;
void Dijkstra() {
	q.push(Node(1, 0, 0));
	dis[1] = 0;
	while (q.size()) {
		Node u = q.top();
		q.pop();
		if (vis[u.x]) {
			ans += u.f;
			continue;
		}
		vis[u.x] = 1;
		for (auto it : adj[u.x]) {
			int v = it.second;
			int w = it.first;
			if (dis[v] > u.w + w) {
				dis[v] = u.w + w;
				q.push(Node(v, dis[v], 0));
			}
		}
	}

}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d %d", &n, &m, &k);
	while (m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
	while (k--) {
		int city, d;
		scanf("%d %d", &city, &d);
		q.push(Node(city, d, 1));
	}
	for (int i = 0; i <= n; i++)dis[i] = 1e16;
	Dijkstra();
	cout << ans << '\n';
	return 0;
}