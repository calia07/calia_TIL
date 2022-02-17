/*
이 문제는 문자열 카테고리에 있는 문제로 map을 사용해서 풀었습니다.

map은 key와 value로 이루어져 있고 사용하려면 상단에 map 헤더를 사용해야 합니다.

먼저 이 문제에서 입력받는 것은 개수가 정해 있지 않아서 getline(cin,str)을 while문의 안에 넣어줘서 끝까지 

입력되도록 했어요!


그리고 마지막에 출력할 때 각 value를 백분율로 변환시켜야 하는데 나눠서 (double)자료형으로 출력해야 

된다는 점 꼭 주의하시기 바랍니다. 저는 double형변환을 안해서 계속 정수로 출력이 되는 실수를 했어요....


다음은 코드입니다.

*/

#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cout << fixed;
	cout.precision(4);
    map<string, int> species;
	int number = 0;
	string str;
	while (getline(cin, str)) {
		species[str]++;
		number++;
	}
	
	map<string, int> :: iterator iter;
	for (iter = species.begin(); iter != species.end();iter++) {
		cout << iter->first << " " << iter->second * 100 / (double)number << '\n';
	}
}
