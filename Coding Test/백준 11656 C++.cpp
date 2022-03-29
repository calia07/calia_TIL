/*
오늘도 정렬에 관한 문제를 풀어봤습니다.

비교적 간단한 문자열 정렬 문제였습니다. 접미사를 잘라내기 위해 substr를 사용했고 이것을

문자열 vector v에 넣어준 뒤에 정렬을 시키고 출력을 해주면 되는 문제였습니다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <string> v;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		string str = s.substr(i, s.size() - i);
		v.push_back(str);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

}
