/*
dfs 문제를 풀어보았는데요! 이 문제는 1이 집이 있는 곳이고 0이 집이 없는 곳이었습니다.

map이 25*25로 주어졌기  때문에 시간초과가 안되면서 모든 노드에서 dfs 탐색을 시켜줄 수 있었어요.

그래서 각 노드마다 dfs 탐색을 하면서 들린 곳은 단지 번호를 매겨주는 과정을 반복하고  몇 개의 단지가 

있는지에 관한 것은 number 변수를  dfs함수가 true가 나올때마다 1씩 증가시켜주는 방식으로 해결했어요


단지 번호를 매길 때 1부터 하면 집이 있는 탐색 안한 곳과 혼동이 되기 때문에 2부터 매겨주고 마지막에 

출력할 때 2를 빼준 값을 출력해줬습니다.


그리고 저는 입력받을 때 0과 1값들이 붙어있어서 string으로 입력받고 이것을 하나하나 '0'을 빼주는 과정을 통해숫자로 변환시켜서 넣어주었는데 scanf를 사용하는 것이 더 편할 것 같다는 생각이 들었어요!

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[25][25];
int number = 2;
int house = 0;
vector <int> h;

bool dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) {
		return false;
	}
	if (map[x][y] == 1) {
		house++;
		map[x][y] = number;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
		
		return true;
	}
	return false;
}


int main() {
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dfs(i, j)) {
				h.push_back(house);
				number++;
				
			}
			house = 0;
		}
	}
	sort(h.begin(), h.end());
	cout << number-2 << '\n';
	for (int i = 0; i < h.size(); i++) {
		cout << h[i] << endl;
	}
}
