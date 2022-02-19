/*
다이나믹 프로그래밍에 대해 공부하면서 푼 문제입니다!

1,2,3 더하기 라는 문제도 있는데 이 문제는 그 문제의 응용 편입니다.


일단 제 코드는 효율적이지는 않은 코드같아서 그냥 이렇게 풀었다는 것만 참고하시면 좋을 것 같습니다.


일단 저는 dp를 사용해서 최대한 중복되는 계산을 하지 않도록 했어요.


dp[i-1] => i-1에 1을 더하면 dp[i-1]의 개수와 같음

dp[i-2] => i-2에 2를 더하면 dp[i-2]의 개수와 같음

dp[i-3] => i-3에 3을 더하면 dp[i-3]의 개수와 같음


세 수에 1,2,3을 더한 값이 i이기 떄문에 배열의 전 인덱스 3개를 합하면 dp[i]의 값을 구할 수 있어요!


주의할 점은 숫자가 크게 나오기 때문에 int를 사용하면 감당할 수 없다는 점입니다.

따라서 long long을 써야해요!


그리고 연산을 최대한으로 줄이기 위해서 입력받은 수 중에서 최댓값을 구해서 그 수까지만 연산을 해놓고 

dp의 배열에서 해당 인덱스의 값을 출력하도록 했습니다.


다음은 코드입니다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long dp[1000001];

int main() {
	int n; cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	
	
	vector <int> v;
	int maximum = 0;
	while (n--) {
		int number; cin >> number;
		maximum = max(maximum, number);
		v.push_back(number);
	}

	
	for (int i = 4; i <= maximum; i++) {
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1])%1000000009;
	}

	for (int i = 0; i < v.size(); i++) {
		cout << dp[v[i]] << '\n';
	}
}
