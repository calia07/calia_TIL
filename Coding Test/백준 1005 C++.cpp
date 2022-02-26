/*
그래프 이론에서 위상 정렬 개념과 구현을 공부하면서 이 문제를 풀게 되었습니다. 

위상 정렬 구현에 대한 틀은 이것이 취업을 위한 코딩테스트다(나동빈 저) 책의 위상 정렬 코드를 참고하였습니다.


 위상 정렬은 방향 그래프의 모든 노드를 방향성을 거스르지 않고 나열하는 것입니다.

만약 1번이 2번 보다 앞에 있어야 하고 2번이 3번보다 앞에 있어야 하면 순서가 1,2,3 이 되는 것처럼

보통 예시를 보면 선수과목 예제가 많이 나옵니다.

 그 예를 들면 C++ 프로그래밍을 들어야 자료구조를 들을 수 있고

또 자료구조를 들어야 컴퓨터 알고리즘을 들을 수 있다는 것들이 있습니다.


노드로 들어오는 간선의 개수를 진입차수라고 하는데 이 진입차수가 0인 노드를 큐에 넣고

큐에서 원소를 꺼내 간선을 그래프에서 제거하고 새롭게 진입차수가 0이 된 노드를 큐에 넣는 방식으로

풀었습니다.


이 문제를 풀 때 조심해야 할 점은 테스트 케이스가 여러 개이기 때문에 다음 테스트 케이스를 실행 할 때 

전의 테스트 케이스의 데이터가 남아 있으면 안 된다는 점입니다. 이 부분 때문에 틀렸었어요!
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int T;
int n,m,k;
int node[1001];
int indegree[1001];
vector <int> v[1001];

void topologySort() {
	vector <long long> result(1001);
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		result[i] = node[i];
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
			if (result[v[now][i]] <= result[now] + node[v[now][i]]) {
				result[v[now][i]] = result[now] + node[v[now][i]];
			}

			indegree[v[now][i]] -= 1;
	
			if (indegree[v[now][i]] == 0) {
				q.push(v[now][i]);
			}
		}
	}
	cout << result[k] << '\n';
}

int main() {
	cin >> T;
	while (T--) {
		
		cin >> n >> m;
		fill(indegree, indegree + 1001, 0);

		for (int i = 0; i < 1001; i++) {
			v[i].clear();
		}

		for (int i = 1; i <= n; i++) {
			cin >> node[i];
		}

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			indegree[b] += 1;
		}
		cin >> k;
		topologySort();
	}
}
