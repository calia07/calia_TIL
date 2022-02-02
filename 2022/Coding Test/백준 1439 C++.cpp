/*오늘은 뒤집기라는 문제를 풀었어요!
  
0의 뭉치와 1의 뭉치 중 더 적은 것을 출력해주면 되는 문제였습니다.

다음은 코드입니다.*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	int one = 0;
	int zero = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[i + 1]) {
			if (s[i] == '0')
				zero++;
			else if(s[i]=='1')
				one++;
		}
	}

	cout << min(one, zero);
	
}
