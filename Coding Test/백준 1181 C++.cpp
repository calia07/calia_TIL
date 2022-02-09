/*오늘은 단어 정렬이라는 문제를 풀었어요!

이 문제는 입력받은 단어들을 단어의 길이에 따라 오름차순으로 출력하고 

만약 단어의 길이가 같으면 사전식 순서로 출력을 하도록하는 문제였습니다.


저는 pair를 요소로하는 벡터를 사용해서 pair에 단어의 길이와 단어를 넣어주도록 했어요.

그리고 algorithm STL을 사용해서 sort하는데 그 기준을 compare 함수를 이용해서 지정해주고

마지막으로 출력할 때는 불 변수를 이용해서 반복되는 단어들은 출력을 하지 않도록 했어요!

다음은 코드입니다.*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else
		return a.first < b.first;
}

int main()
{
	bool overlap = false;
	vector<pair<int, string> > v;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		v.push_back(pair<int, string>(s.size(), s));
	}
	

	sort(v.begin(), v.end(),compare);
	cout << v[0].second << '\n';

	for (int i = 1; i < v.size(); i++) {
		if (v[i].second == v[i -1].second) {
			overlap = true;
		}
		else
			overlap = false;
		if (!overlap)
			cout << v[i].second << '\n';
	}

	return 0;
}
