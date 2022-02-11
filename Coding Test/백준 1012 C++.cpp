/*
dfs를 이용하여 유기농 배추를 기르기 위한 지렁이가 몇 마리 필요한지에 대해 알아보는 문제였습니다.

dfs를 사용하여 들린 곳은 표시를 해주고 모든 노드에 대해 dfs를 호출해주면 몇 개의 덩어리로 이루어져 있는지 알 수 있습니다.

다음은 코드입니다.
*/


#include <iostream>

using namespace std;
int m, n, k;
int map[50][50];
int visited[50][50];

bool dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n) {
		return false;
	}
	if (map[x][y]==1) {
		map[x][y] = 0;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
		return true;
	}
	return false;

}

int main() {
	int num; cin >> num;
	while (num--) {
		int number = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y; cin >> x >> y;
			map[x][y] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (dfs(i, j)) {
					number++;
				}
			}
		}
		cout << number << endl;
	}
	return 0;
}
