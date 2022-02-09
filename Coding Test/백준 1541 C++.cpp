/* 오늘은 탐욕법에 대해 공부하면서 관련된 잃어버린 괄호라는 문제를 풀었어요! 

이 문제는 -뒤에 나오는 +들을 모두 -로 바꿔주도록 괄호를 치면 최솟값이 나오는 문제입니다!

bool 변수 minus를 이용해서 -가 나왔는지 안나왔는지 판별하고

만약 minus가 나왔으면 true로 뒤의 모든 숫자들을 뺴주고 안나왔으면 false로 +뒤의 숫자를 더해주도록 했어요!

그리고 입력받을 때 문자열로 입력을 받았기 때문에 stoi()함수를 이용해서 int 자료형으로 바꿔주도록 했습니다.

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	string num = "";
	bool minus=false;
	int result = 0;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] >= '0'&& str[i] <= '9') {
			num += str[i];
		}
		else {
			if (minus) {
				result -= stoi(num);
				num.clear();
			}
			else {
				result += stoi(num);
				num.clear();
			}
		}
		if (str[i] == '-') {
			minus = true;
		}
	}
	cout << result;
}
