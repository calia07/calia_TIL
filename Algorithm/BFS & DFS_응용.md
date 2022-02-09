## 실전 1) 음료수 얼려 먹기
#### 처음 시도한 코드에서는 map을 배열이 아닌 vector로 입력 받아서 더 복잡했고 변수들을 main 함수 안에 선언을 해놔서 dfs함수를 호출 시 매개변수가 많아 복잡했다.
#### dfs를 이용하여 방문한 곳은 1로 변환시켜주고 dfs가 true인 값이 몇 개인지 세어주는 방식으로 문제를 풀었다.

- 실패 코드 
    ```cpp
    #include <iostream>
    #include <vector>
    #include <string>
    
    using namespace std;
    
    bool dfs(int x,int y, int n, int m,vector<vector<int>>& s) {
    	if (x < 0 || x >= n || y < 0 || y >= m) {
    		return false;
    	}
    	if (s[x][y] == 0) {
    		s[x][y] = 1;
    		dfs(x - 1, y, n, m, s);
    		dfs(x + 1, y, n, m, s);
    		dfs(x, y + 1, n, m, s);
    		dfs(x, y - 1, n, m, s);
    		return true;
    	}
    	return false;
    }
    
    int main() {
    	int n, m;
    	cin >> n >> m;
    	vector<vector<int>> map;
    	string str;
    	vector <int> r;
    	getline(cin, str);
    	for (int i = 0; i < n; i++) {
    		getline(cin, str);
    		for (int j = 0; j < m; j++) {
    			r.push_back(str[i]-'0');
    		}
    		map.push_back(r);
    		r.clear();
    	}
    	int result = 0;
    	for (int i = 0; i < n+1; i++) {
    		for (int j = 0; j < m; j++) {
    			if (dfs(i, j, n, m, map) == true)
    			{
    				result++;
    			}
    		}
    	}
    	
    	
    	cout << result;
    }
    ```
    
- 강의 참고 후 수정 코드<br>

    map을 배열로 수정하였고 변수들을 main함수의 밖에 선언해주어 dfs 호출시에 매개변수가 간단해졌다.
    
    ```cpp
    #include <iostream>
    #include <string>
    
    using namespace std;
    
    int n, m;
    int map[1000][1000];
    
    bool dfs(int x, int y) {
    	if (x < 0 || x >= n || y < 0 || y >= m) {
    		return false;
    	}
    	if (map[x][y] == 0) {
    		map[x][y] = 1;
    		dfs(x - 1, y);
    		dfs(x + 1, y);
    		dfs(x, y + 1);
    		dfs(x, y - 1);
    		return true;
    	}
    	return false;
    }
    
    int main() {
    	cin >> n >> m;
    	string s;
    	getline(cin, s);
    	for (int i = 0; i < n; i++) {
    		getline(cin, s);
    		for (int j = 0; j < m; j++) {
    			map[i][j] = s[j] - '0';
    		}
    	}
    	int answer = 0;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			if (dfs(i, j)) {
    				answer++;
    			}
    		}
    	}
    	cout << answer;
    }
    ```
    
## 실전 2) 미로 탈출
#### 좌표를 사용하기 위해 pair를 사용했고 각 칸을 지나갈 때마다 1씩 증가시킨 값을 넣어준다. 마지막으로 오른쪽 아래에 있는 칸의 값을 출력시켜준다.

- 강의 참고 후 문제 푼 코드
    
    ```cpp
    #include <iostream>
    #include <string>
    #include <queue>
    #include <utility>
    #include <vector>
    
    using namespace std;
    
    int n, m;
    
    int map[201][201];
    
    int dx[] = { -1,1,0,0 };
    int dy[] = { 0,0,-1,1 };
    
    int bfs(int x, int y) {
    	queue<pair<int,int>> q;
    	q.push(pair<int, int>(x, y));
    	
    	while (!q.empty()) {
    		pair<int, int> s = q.front();
    		q.pop();
    		for (int i = 0; i < 4; i++) {
    			int newx = s.first + dx[i];
    			int newy = s.second + dy[i];
    
    			if (newx < 0 || newx >= n || newy < 0 || newy >= m)
    				continue;
    			if (map[newx][newy] == 0)
    				continue;
    			if (map[newx][newy] == 1) {
    				map[newx][newy] = map[s.first][s.second] + 1;
    				q.push(pair<int, int>(newx, newy));
    			}
    		}
    	}
    	return map[n - 1][m - 1];
    
    }
    
    int main() {
    	cin >> n >> m;
    	
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			scanf_s("%1d", &map[i][j]);
    		}
    	}
    	
    	cout << bfs(0, 0);
    }
    ```
    

## 응용 1) 특정 거리의 도시 찾기
#### bfs 함수 이용해서 해결했으며 bfs 내부에서 number++를 어디서 해야 할지에 관해서 고민했었다.
#### bfs 함수를 이용해서 최단 거리를 answer 배열의 각 노드의 인덱스에 해당하게 넣어주었고 이 값이 주어진 K와 같으면 출력하도록했다. 이 때 오름차순으로 출력하도록하였다.
    
    ```cpp
    #include <iostream>
    #include <queue>
    
    using namespace std;
    int N, M, K, X;
    vector <int> graph[300001];
    int visited[300001];
    int answer[300001];
    
    int bfs( ) {
    	queue<int> q;
    	int number = 1;
    	visited[X] = true;
    	q.push(X);
    	while (!q.empty()) {
    		int s = q.size();
    		while (s-- > 0) {
    			int x = q.front();
    			q.pop();
    			for (int i = 0; i < graph[x].size(); i++) {
    				int y = graph[x][i];
    				if (!visited[y]) {
    					q.push(y);
    					answer[y] = number;
    					visited[y] = true;
    				}
    			}
    		}
    		number++;
    	}
    	return 0;
    }
    
    int main() {
    	cin >> N >> M >> K >> X;
    	for (int i = 0; i < M; i++) {
    		int num, dep;
    		cin >> num >> dep;
    		graph[num].push_back(dep);
    	}
    	bfs();
    	bool empty = true;
    	for (int i = 0; i <= N; i++) {
    		if (answer[i] == K) {
    			cout << i << endl;
    			empty = false;
    		}
    	}
    	if (empty)
    		cout << -1;
    }
    ```

## 응용 2) 연구소
#### 벽을 세 개 세울 수 있는 경우의 수를 모두 탐색하는 방법으로 세 개를 세우고 안전 영역 크기를 측정한 다음 계속 비교해서 이 크기의 최댓값을 구하는 방법

```cpp
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int map[8][8];
int temp[8][8] = {0};

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int result = 0;

void virus(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (temp[nx][ny] == 0) {
				temp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

int score() {
	int score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				score++;
			}
		}
	}
	return score;
}


void dfs(int count) {
	if (count == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2) {
					virus(i, j);
				}
			}
		}
		result = max(result, score());
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					count += 1;
					dfs(count);
					map[i][j] = 0;
					count -= 1;
				}
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0);
	cout <<result;

}
```
