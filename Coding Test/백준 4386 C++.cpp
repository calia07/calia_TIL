/*
오늘은 최소 신장 트리에 관련된 문제를 풀면서 복습을 해봤습니다.


최소 신장트리는 하나의 그래프가 있을 때 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프 

중 최소인 값을 가지는 것입니다.


최소 신장 트리의 구현 공부는  [이것이 취업을 위한 코딩테스트다(with python)-나동빈 저]를 참고하였습니다.


이 문제는 최소 신장 트리를 좌표에서 구하는 것입니다.

그래서 처음에는 난감했어요.. 

하지만 간선의 값을 직접 구해야 한다는 점 말고는 최소 신장트리 구현과 별로 다를게 없더라고요!

직접 구할 때는 cmath를 이용해서 구했습니다.


그리고 주의할 점은 출력할 때 소숫점 2자리까지 출력해줘야 하기 때문에

cout.precision();을 사용해줘야한다는 점입니다!


코드는 다음과 같습니다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int parent[1001];

vector<pair<double, pair<double, double> > > edges;
vector < pair<double, double>> node;
double result = 0;


int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;      
        node.push_back({ a,b });
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({ sqrt(pow(node[i].first-node[j].first,2)+pow(node[i].second-node[j].second,2)),{i,j} });
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++) {
        double cost = edges[i].first;
        double a = edges[i].second.first;
        double b = edges[i].second.second;
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
        }
    }
    cout.precision(3);
    cout << result << '\n';
}
