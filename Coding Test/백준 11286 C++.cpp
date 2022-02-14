/*
이 문제도 최소 힙을 사용하는 문제긴 한데 기준이 절댓값 기준이라서 특별한 정렬 기준을 만들어줘야해요.

compare를 사용해서 절댓값을 기준으로 정렬할 수 있도록 만들어주었고 만약 절댓값이 같으면 값이 작은 걸 반환해야하는 것까지 구현해줬습니다!

그 외의 것은 최대 힙/최소 힙 문제와 거의 동일합니다.

다음은 코드입니다.
*/

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b))
			return true;
		else if (abs(a) < abs(b))
			return false;
		else {
			return a > b;
		}
	}
};
		
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	priority_queue <int, vector<int>, compare> pq;
	int n; cin >> n;
	while (n--) {
		int num; cin >> num;
		if (num == 0) {
			if (pq.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top()<<'\n';
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}

}
