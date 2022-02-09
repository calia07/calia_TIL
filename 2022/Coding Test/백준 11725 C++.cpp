/*
오늘도 dfs/bfs 에 관한 문제를 풀었습니다.

find 함수를 이용하여 parent 배열에 각각의 부모 노드의 번호를 넣어 주었습니다.

find 함수는 dfs를 이용하여 재귀적으로 구성했습니다.

그리고 마지막으로 2부터 n까지 parent 배열의 각 인덱스에 들어있는 값을 출력해주면 끝입니다.


처음에는 문제에 이진트리라는 말이 없는데 이진트리로 단정짓고 pair를 이용해서 풀었는데요.

이렇게하면 주어진 테스트케이스는 통과할 수 있지만 자식 노드가 세 개인 트리에서는 통과할 수 없습니다.


문제를 잘 읽고 풀어야겠다는 생각이 든것 같아요!
*/

#include <iostream>
#include <vector>

using namespace std;
bool visited[100001];
vector <int> graph[100001];
int parent[100001];
int n;

void find(int root) {
	visited[root] = true;
	for (int i = 0; i < graph[root].size(); i++) {
		int y = graph[root][i];	
		if (!visited[y]) {
			parent[y] = root;
			find(y);
			
		}
		
	}
	
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int A,B; cin >> A>>B;
		graph[A].push_back(B);
		graph[B].push_back(A);	
	}
	find(1);
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

}
