/*
오늘은 다익스트라 알고리즘에 관해 공부하면서 관련 문제를 풀어봤습니다.


다익스트라 알고리즘은 여러 개의 노드가 있는 그래프에서 출발 노드에서 다른 노드까지의 최단 경로를 구해주는 

알고리즘입니다.


구현은 우선순위큐를 이용했습니다.

dijkstra 함수를 이용해서 갈 때의 거리와 올 때의 거리를 구해주고 비교해서 이 둘을 더한 값이 가장 큰 노드를 골라 

왕복하는데 걸리는 시간을 출력하도록 했습니다.


다음은 코드입니다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, X;
vector < pair <int, int>> v[1001];

int d[1001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(pair<int, int>(0, start));
	d[start] = 0;
	while (!pq.empty()) {
		int dis = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dis) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int cost = dis + v[now][i].second;
			if (cost < d[v[now][i].first]) {
				d[v[now][i].first] = cost;
				pq.push(pair<int, int>(-cost, v[now][i].first));
			}
		}
	}

}
int main() {
	cin >> N>>M>>X;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(pair<int, int>(b, c));
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		fill(d, d + 1001, 1e9);
		dijkstra(i);
		int temp = d[X];

		fill(d, d + 1001, 1e9);
		dijkstra(X);
		int temp2 = d[i];
		if (temp+temp2 > max) {
			max = temp + temp2;
		}
	}
	
	cout << max;

}
