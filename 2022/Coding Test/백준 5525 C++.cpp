/*입력받은 n으로 해당하는 문자열이 몇개 있는지 알아내는 문제였습니다.

저는 bool연산으로 IO가 번갈아가면서 이어져 있는지 확인했고 이에 해당하면 number++를 해주었습니다.

그러다가 연결된 것이 끊기면 이것을 vector에 추가해주고 number를 0으로 다시 초기화해주었습니다.

이런 과정을 반복하면 마지막으로 vector에 추가된 숫자에 n을 빼고 1을 더해서 그 값을 마지막으로 출력할

answer에 더해주면 끝입니다!
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	int length; cin >> length;
	string s; cin >> s;
	bool ii = false;//I가 나왔는지 판별
	bool oo = false;//O가 나왔는지 판별
	int number = 0;
	vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'O') {
			if (ii == true && oo==false && s[i+1]=='I') {
				number++;
			}
			else {
				v.push_back(number);
				number = 0;
			}
			ii = false;
			oo = true;
		}
		else {
			if (oo == false && ii == true) {
				v.push_back(number);
				number = 0;
			}
			oo= false;
			ii = true;
		}
	}
	
	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= n) {
			answer += v[i] - n + 1;
		}
	}

	cout << answer;
	
}
