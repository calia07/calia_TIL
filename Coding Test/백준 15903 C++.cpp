/*
이 문제는 우선순위 큐를 이용하면 정말 간단하게 풀 수 있는 문제였어요.

최소힙을 사용하여 가장 작은 값 두 개를 pop해서 더한 다음에 그 값을 다시 2번 push하는 과정을 m번 반복한 뒤

남아있는 요소들을 모두 더해주는 방법으로 풀었습니다.


다만 주의할 점이 있다면 바로 자료형입니다!

문제에 제시된 조건을 보면 자료형을 int가 아닌 long long 을 써야 통과됩니다.


다음은 코드입니다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	priority_queue <long long, vector<long long>, greater<long long>> pq;//최소 힙
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long num; cin >> num;
		pq.push(num);
	}
	while (m--) {
		long long one = pq.top();
		pq.pop();
		long long two = pq.top();
		pq.pop();
		pq.push(one + two);
		pq.push(one + two);
	}
	long long answer = 0;

	while (pq.size() != 0) {
		answer += pq.top();
		pq.pop();
	}
	cout << answer;
}
