/*
자료구조 중 최대 힙과 최소 힙을 이용한 우선순위 큐를 사용해서 푸는 문제들입니다.

아래의 문제와 세트 같아서 같이 가져왔어요!

우선순위큐는 최대 힙이냐 최소 힙이냐에 따라서 각각 최댓값이나 최솟값이 top에 위치해 있습니다. 따라서 pop하면 최댓값과 최솟값이 나오는 거죠.


먼저 최대 힙을 이용해야 하는 문제의 코드입니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n; cin >> n;
	priority_queue <int> pq;
	while (n--) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.size() == 0) {
				cout << 0 << '\n';
			}
			else
			{
				cout << pq.top()<<'\n';
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
}


/*
다음은 최소 힙을 이용해야 하는 문제의 코드입니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n; cin >> n;
	priority_queue <int, vector<int>, greater<int>> pq;

	while (n--) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.size() == 0) {
				cout << 0 << '\n';
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
}
/*
처음에 풀 떄 시간초과가 떠서 생각해보니까 

1. 출력할 때 줄바꿈을 enl 대신에  '\n'을 사용해야 시간이 단축되는데 endl로 썼고

2. 다음으로 cin.tie(0); 와 cin.sync_with_stdio(0);을 추가를 안해줬더라고요.

혹시 시간초과가 뜨신다면 이 점을 한 번 체크해보시는 것 추천드립니다!
*/
