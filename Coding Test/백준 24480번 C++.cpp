#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001] = { false };
vector <int> graph[100001];
int dist[100001] = { 0 };
int k = 0;

bool compare(int a, int b) {
	return a > b;
}
void dfs(int x) {
	visited[x] = true;
	k++;
	dist[x] = k;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) dfs(y);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {	
			sort(graph[i].begin(), graph[i].end(),compare);		
	}

	dfs(R);

	for (int i = 1; i <= N; i++) {
		cout << dist[i] << '\n';
	}
		
}

