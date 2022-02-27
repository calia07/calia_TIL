//위상정렬에 대한 문제를 풀어보았습니다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int node[1001];
int indegree[1001];
vector <int> v[1001];

void topologySort() {
	vector <int> result(1001);
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		result[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int i = 0; i < v[now].size(); i++) {
			if (result[v[now][i]] < result[now] + node[v[now][i]]) {
				result[v[now][i]] = result[now] + node[v[now][i]];
			}

			indegree[v[now][i]] -= 1;
	
			if (indegree[v[now][i]] == 0) {
				q.push(v[now][i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	
		cin >> n >> m;
		for (int i = 0; i < n + 1; i++) {
			node[i] = 1;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			indegree[b] += 1;
		}


		

		topologySort();
	
}
