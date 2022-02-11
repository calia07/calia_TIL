/*

bfs/dfs를 구현하는 문제로 각각의 방법으로 구현했을 때 어느 순서로 탐색을 하는지 출력하는 문제입니다.

이 때 두 개의 방법으로 탐색을 해야 하기 때문에 visited 배열을 2개 만들어줬습니다.

dfs로 탐색하는 순서를 먼저 출력해주고 난 뒤에 bfs 함수를 이용하여 탐색하는 순서를 나중에 출력해줍니다.

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, k;
vector <int> graph[1001];
bool visited_dfs[1001];
bool visited_bfs[1001];

void dfs(int k) {
	visited_dfs[k] = true;
	cout << k << " ";
	for (int i = 0; i < graph[k].size(); i++) {
		int x = graph[k][i];
		if (visited_dfs[x] == false) {
			visited_dfs[x] = true;
			dfs(x);
		}
	}
}
void bfs(int k) {
	queue <int> q;
	q.push(k);
	visited_bfs[k] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (visited_bfs[y] == false) {
				q.push(y);
				visited_bfs[y] = true;
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(k);
	cout << endl;
	bfs(k);
}
