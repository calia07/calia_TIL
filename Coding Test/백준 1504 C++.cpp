/*
오늘도 다익스트라 알고리즘과 플로이드-워셜 알고리즘에 대해 공부하면서 관련된 문제를 풀어봤습니다!


다익스트라 알고리즘 구현에 대한 공부와 코드에 대한 참고는 

[이것이 취업을 위한 코딩테스트다 with python(나동빈 저)]로 했어요.


먼저 이 문제는 특정한 2개의 노드를 거쳐서 가야하는 문제입니다. 

각 간선들은 양방향이라는 것에 유의해야합니다. 

그리고 주어진 2개의 노드를 꼭 순서대로 가야할 필요가 없다는 걸 한 번 틀리고 난 다음에 깨달았어요....


저는 다익스트라 알고리즘을 쓴 다음에 2개의 경로에 대해 고려를 해줬어요.


1) 1 -> v1 -> v2 -> N

2) 1 -> v2 -> v1 -> N


먼저 다익스트라 알고리즘을 쓴 다음에

1 -> v1의 최단 경로와 1->v2의 최단 경로를 a1, a2 변수에 담고

다시 다익스트라 알고리즘을 쓴 다음에

v1->v2의 최단 경로와 v1->N의 최단 경로를 b1, c2 변수에 담고

다시 다익스트라 알고리즘을 쓴 다음에

v2->N의 최단 경로와 v2->v1의 최단경로를 c1, b2 변수에 담았어요.


여기서 양방향이기 때문에 v1->v2까지의 최단경로와 v2-> v1까지의 최단경로인 b1과 b2는 같답니다!


2개의 경로를 진행하는 과정에서 둘 다 값이 1e9가 나오는 경우가 있으면 -1을 출력해주고 끝내도록 했고

해당하지 않으면 2개의 경로의 값을 비교해서 더 작은 값을 가진 경로의 최단 경로를 출력해주도록 했습니다.


다음은 코드입니다.
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, E;
vector<pair<int, int>> graph[801];
int d[801];
int v1, v2;

void dijkstra(int start) {
	priority_queue<pair<int, int>>pq;

	pq.push({ 0,start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main() {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	int answer1 = 0;
	int answer2 = 0;
	fill(d, d + 801, 1e9);

	dijkstra(1);
	int a1 = d[v1];
	int a2 = d[v2];

	fill(d, d + 801, 1e9);

	dijkstra(v1);
	int b1 = d[v2];
	int c2 = d[N];
	
	fill(d, d + 801, 1e9);

	dijkstra(v2);
	int c1 = d[N];
	int b2 = d[v1];

	if ((a1 == 1e9 || b1 == 1e9 || c1 == 1e9) && (a2 == 1e9 || b2 == 1e9 || c2 == 1e9)) {
		cout << -1;
		return 0;
	}
	if (a1 + b1 + c1 > a2 + b2 + c2) {
		cout << a2 + b2 + c2;
	}
	else {
		cout << a1 + b1 + c1;
	}
}
