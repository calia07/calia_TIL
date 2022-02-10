/*
dfs문제를 찾다가 발견한 문제입니다.

보통 상하좌우로 움직이는 것과는 다르게 대각선으로도 움직일 수 있다는 것이 이 문제의 특이한 점입니다.

저는 문제를 풀 때 높이와 너비 각각 행과 열 중에 무엇인지에 대해 헷갈려서 결과가 다르게 나오는 일이 있었어요!

그래서 문제를 정말 잘 읽고 이해해야겠다는 생각이 들었습니다.


dfs코드로 상하좌우 대각선을 탐색하여 모두 방문한 곳으로 만들어주고 다음 노드에서 함수를 호출해주면 이미 방문한 곳이면 count가 되지 않기 때문에 dfs함수가 반환하는 true값으로 몇 개의 섬이 있는지 알 수 있습니다.


코드입니다.
*/

#include <iostream>

using namespace std;

int w,h;
int map[51][51];


bool dfs(int x, int y) {
	if (x < 0 || y >= w || y < 0 || x >= h) {
		return false;
	}
	if (map[x][y] == 1) {
		map[x][y] = 0;
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		dfs(x - 1, y - 1);
		dfs(x + 1, y + 1);
		dfs(x - 1, y + 1);
		dfs(x + 1, y - 1);
		return true;
		
	}
	return false;

}

int main() {
	while (true) {
		int answer = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (dfs(i, j) == true) {
					answer++;
				}
			}
		}
		cout <<answer<<'\n';
	}
}
