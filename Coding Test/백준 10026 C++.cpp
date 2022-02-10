/*
저는 이 문제를 dfs로 풀었어요! 그런데 R과 G를 구분 하느냐 안하느냐에 따라서 다른 값이 나오기 때문에

dfs 함수도 dfs_d,dfs_s로 두 개를 만들어주었고 map과 visited 배열도 각각 map_s, map_d, visited_s, visited_d 로 두 개씩  만들어줬어요.

dfs_d 함수는 R과 G를 다르게 보는 함수인데 매개변수에 문자를 넣어줘서 이 문자와 같고 방문하지 않았으면 그 위치에 X라는 문자를 넣어줘서 중복을 막는 방법을 사용했습니다.

dfs_s함수는 R과 G를 같게 보는 함수인데 이 경우에도 매개변수에 문자를 넣어준 다음에 

만약 매개변수로 온 문자가 R이나 G이면 그 옆의 칸이 R이나 G이고 방문하지 않았을 때 X라는 문자를 넣어주도록했고 B이면 그 옆의 칸이 B이고 방문하지 않았을 때 X라는 문자를 넣어주는 방법을 사용했습니다.

그리고 입력받을 때 map에 넣을 때의 반복문에서 s.size()가 아니라 n이라고 쓰면 에러가 발생한다는 점을 알게되었습니다!

다음은 코드입니다. 
*/

#include <iostream>
#include <string>

using namespace std;
int n;

char map_d[100][100];
char map_s[100][100];
int visited_d[100][100];
int visited_s[100][100];

bool dfs_d(int x, int y,char c) {
	if (x < 0 || x >= n || y < 0 || y >= n) {
		return false;
	}
	if (!visited_d[x][y] && map_d[x][y]==c) {
		visited_d[x][y] = true;
		map_d[x][y] = 'X';
		dfs_d(x + 1, y,c);
		dfs_d(x - 1, y,c);
		dfs_d(x, y + 1,c);
		dfs_d(x, y - 1,c);
		return true;
	}
	return false;
}

bool dfs_s(int x, int y,char c) {
	if (x < 0 || x >= n || y < 0 || y >= n) {
		return false;
	}
	if (c == 'R' || c == 'G') {
		if (!visited_s[x][y] && (map_s[x][y] == 'R' || map_s[x][y] =='G')) {
			visited_s[x][y] = true;
			map_s[x][y] = 'X';
			dfs_s(x + 1, y, c);
			dfs_s(x - 1, y, c);
			dfs_s(x, y + 1, c);
			dfs_s(x, y - 1, c);
			return true;
		}
	}
	else {
		if (!visited_s[x][y] && map_s[x][y] == 'B') {
			visited_s[x][y] = true;
			map_s[x][y] = 'X';
			dfs_s(x + 1, y, c);
			dfs_s(x - 1, y, c);
			dfs_s(x, y + 1, c);
			dfs_s(x, y - 1, c);
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n;
	string s="";
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		for (int j = 0; j < s.size(); j++) {
			map_s[i][j] = s[j];
			map_d[i][j] = s[j];
		}
	}
	int num_d = 0;
	int num_s = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs_d(i, j,map_d[i][j])) {
				num_d++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs_s(i, j,map_s[i][j])) {
				num_s++;
			}
		}
	}
	cout << num_d << " " << num_s;
}
​
