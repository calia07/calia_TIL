/*탐욕법에 관한 문제를 풀었어요!

먼저 거리와 비용에 관한 입력을 vector와 배열에 받아주고 최소 비용을 구하기 위해

비용과 거리를 구할 때 비용은 여태까지 나온 값 중에서 가장 작은 값을 곱해주도록 했어요!


주의할 점이 있는데 점수가 나뉘는 문제인데 만약 제약 조건이 없다고 하면 숫자가 엄청 커지기 때문에

자료형을 long long을 사용해줘야 100점이 나오더라고요.


앞으로 자료형도 주의해서 문제를 풀어야할 것 같아요!

*/

다음은 코드입니다.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	vector <int> cost;
	int arr[100000];
	long long money = 0;
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int num; cin >> num;
		cost.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long min = arr[0];
	for (int i = 0; i < n - 1; i++) {
		if (min > arr[i])
			min = arr[i];
		money += min * cost[i];
		
	}
	cout << money;
}
