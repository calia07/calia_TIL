/*오늘은 bfs/dfs를 공부하면서 관련된 문제를 풀었어요. 이 문제는 최단 거리에 관련된 문제여서 

bfs로 풀었습니다.

bfs함수를 따로 만들어주었고 이것을 호출해서 answer배열에 각각의 최단거리를 인덱스에 맞게 넣어주도록 

했어요. 

그리고 마지막에 입력받은 최단 거리 값과 같은 값을 가지면 그 인덱스를 출력하도록했습니다.


아래는 주석을 넣은 코드입니다!*/

#include <iostream>
#include <queue>

using namespace std;
int N, M, K, X;
vector <int> graph[300001];//그래프
int visited[300001];//방문한 곳인지
int answer[300001];//최단거리

int bfs( ) {
	queue<int> q;//bfs->queue선언
	int number = 1;//거리 계산할 변수
	visited[X] = true;//방문한 곳으로 표시
	q.push(X);//큐에 삽입
	while (!q.empty()) {//큐가 공백상태가 아니면
		int s = q.size();
		while (s-- > 0) {//거리 계산을 위한 while문
			int x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++) {
				int y = graph[x][i];//연결된 노드 탐색
				if (!visited[y]) {//방문한 곳이 아니면
					q.push(y);//y를 큐에 넣기
					answer[y] = number;//y노드 까지의 거리를 answer에 넣기
					visited[y] = true;//방문한 곳으로 표시
				}
			}
		}
		number++;//조건을 충족시키지 않을 때 number++
	}
	return 0;
}

int main() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int num, dep;
		cin >> num >> dep;
		graph[num].push_back(dep);
	}//그래프에 간선으로 노드 연결
	bfs();//bfs 함수 호출
	bool empty = true; //출력 판별을 위한 변수
	for (int i = 0; i <= N; i++) {//answer 배열에서
		if (answer[i] == K) {//값이 K와 같으면
			cout << i << endl;//인덱스의 값을 출력
			empty = false;//-1 출력 안함
		}
	}
	if (empty)
		cout << -1;//만약 K와 같은 값이 없으면 -1 출력
}
