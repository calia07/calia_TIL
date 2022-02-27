/*
최소 신장 트리에 대해 공부하면서 풀게 된 문제입니다. 

이 문제는 최소 신장 트리의 기본 구현에 중점을 둔 문제였습니다.

구현 코드는 [이것이 취업을 위한 코딩테스트다(한빛미디어) - 나동빈 저]를 참고하였습니다.


우선 신장 트리란 하나의 그래프에서 모든 노드를 포함하면서 사이클을 발생시키지 않는 그래프입니다.


최소 비용 신장 트리를 구하는 알고리즘에는 크루스칼 알고리즘이 있습니다.

그 과정을 살펴보면


1. 간선의 데이터를 오름차순으로 정렬

2. 간선을 차례대로 하나씩 확인하며 간선이 사이클을 발생시키는지 확인합니다.

    - 만약 사이클이 발생하면 그래프에 포함시키지 않습니다.

    - 만약 사이클이 발생하지 않으면 그래프에 포함시킵니다.

3. 모든 간선에 대해서 2번의 과정을 반복합니다.


이 때 사이클이 발생하는지 알아보기 위해서는 과정을 거쳐야 하는데 그 과정은 다음과 같습니다.


1. 각 간선을 확인하면서 두 노드의 루트 노드를 확인합니다.

    - 만약 루트노드가 서로 같다면 사이클이 발생했다는 것을 알 수 있습니다.

    - 만약 루트노드가 서로 다르다면 사이클이 발생하지 않았다는 것을 알 수 있습니다.

2. 모든 간선에 대해 1번을 반복합니다.


다음은 코드입니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
int parent[100001]; 
vector<pair<int, pair<int, int> > > edges;
int result = 0;

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
    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back({ cost, {a, b} });
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
        }
    }

    cout << result;
}
