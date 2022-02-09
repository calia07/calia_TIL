#include <iostream>
#include <string>

using namespace std;

int main() {
	int n; cin >> n;
	int num = n; // 출력할 그룹 단어의 수
	while (n--) {
		string s;
		cin >> s;//문자열 입력
		bool alphabet[26]={false};// 알파벳 bool 배열 선언 및 초기화
		for (int i = 0; i < s.size(); i++) {//문자열 길이만큼 반복
			if (alphabet[s[i]-'a'] == false) {//알파벳의 순서에 해당하는 배열의 인덱스의 값이 fasle이면
				if (s[i] == s[i + 1]) {//지금 문자와 다음 문자가 같으면
					continue;//계속 진행
				}
				else {//다르면
					alphabet[s[i] - 'a'] = true;//배열의 인덱스 값을 이용해 true로 바꿈
				}
			}
			else {//알파벳의 순서에 해당하는 배열의 인덱스의 값이 true이면
				num--;//num에서 1뺴기
				break;//반복문에서 나오기
			}
		}
	}
	cout << num;//그룹 단어의 수 출력

}
