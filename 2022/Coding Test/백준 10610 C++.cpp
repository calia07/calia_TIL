/*

주어진 숫자의 배열을 바꿔서 가장 큰 30의 배수를 만드는 문제였습니다!
우선 10의 배수가 되려면 숫자 중에 0이 들어가야되기때문에 bool 변수를 사용해서 zero가 있는지 탐지를 해주고
3의 배수가 되려면 각 자리 숫자의 합이 3의 배수가 되어야 되기 때문에 각 자리의 수를 합한 값을 이용해서
만약 이 수가 3으로 나뉘고 zero가 있으면 vector를 sort해서 뒤에서부터 출력해주도록 했어요!
만약 두 조건 중 하나라도 만족하지 못하면 -1을 출력하도록 해서 풀었습니다!

다음은 코드입니다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector <int> v;
	string s; cin >> s;
	int number = 0;
	bool zero = false;
	for (int i = 0; i < s.size(); i++) {
		number += s[i] - '0';
		v.push_back(s[i] - '0');
		if (s[i]-'0'== 0) {
			zero = true;
		}
	}

	sort(v.begin(), v.end());

	if (number % 3 == 0 && zero == true) {
		for (int i = v.size() - 1; i >= 0; i--)
		{
			cout << v[i];
		}
	}
	else {
		cout << -1;
	}
}
