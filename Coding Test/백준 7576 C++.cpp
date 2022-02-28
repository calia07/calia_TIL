/*
오랜만에 dfs/bfs를 복습하기 위해 푼 문제입니다.


토마토가 근처에 익은 토마토가 있어야만 익기때문에 값을 입력받으면서 값이 1이면 큐에 넣었고 모두 입력받은 뒤

bfs 함수를 이용해 각 좌표의 토마토가 익는데 걸리는 시간으로 값을 바꾸도록했습니다.


이렇게 0인 부분을 채워나가고 bfs가 끝난 다음에 탐색을 해서 0인 값이 남아있으면 토마토가 모두 익지 못하는 

상태이기 때문에 -1을 출력하고 종료하게 해주었습니다.


만약 0인 부분이 없다면 표의 값들 중 가장 큰 값을 출력할 수 있도록 값을 비교해서 max에 넣었습니다.

max에서 1을 뺸 이유는 1부터 시작을 했기 때문입니다.


다음은 코드입니다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int ground[1001][1001];
queue<pair<int, int>> q;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs() {
	while (!q.empty()) {
		pair<int, int> s = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newx = s.first + dx[i];
			int newy = s.second + dy[i];

			if (newx >= 0 && newx < m && newy >= 0 && newy<n && ground[newx][newy]==0) {
				ground[newx][newy] = ground[s.first][s.second] + 1;
				q.push({ newx,newy });
			}
			
			
		}
		
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ground[i][j];
			if(ground[i][j]==1)
				q.push({ i,j });
		}
	}
	bfs();
	int max = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (ground[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (max < ground[i][j]) {
				max = ground[i][j];
			}
		}
	}
	cout << max-1;

}
