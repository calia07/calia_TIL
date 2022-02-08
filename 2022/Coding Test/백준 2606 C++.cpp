/*
dfs 문제입니다. 

이 문제에서 신경써야했던 부분은 바로 양방향이라는 점입니다. 
양방향이기 때문에 입력받은 값을 두 각 노드에 두번 연결 시켜주는 과정을 거치니 문제가 해결되었습니다.

그래프 문제에서는 양방향인지 단방향인지 주의해서 구현을 해야겠다는 것을 느낄 수 있는 문제였습니다.

*/


#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[101];
vector<int> computer[101];
int number = -1;

void dfs(int x) {
	visited[x] = true;
	number++;
	for (int i = 0; i < computer[x].size(); i++) {
		int y = computer[x][i];
		if (!visited[y])
			dfs(y);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int A, B;
		cin >> A >> B;
		computer[A].push_back(B);
		computer[B].push_back(A);
	}
	dfs(1);
	cout << number;
}
