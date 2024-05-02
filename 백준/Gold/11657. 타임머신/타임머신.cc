#include <vector>
#include <iostream>
#include <algorithm>
 
#define MAX 9'999'999
 
using namespace std;
 
struct Edge
{
	int from = 0;
	int to = 0;
	int cost = MAX;
};
 
int main()
{
	int start = 1;
	int node, edge;
	cin >> node >> edge;
 
	vector<Edge> edges(edge);
	vector<long long> costs(node + 1, MAX);
 
	// 자기 자신으로 가는 비용은 0
	costs[start] = 0;
 
	// 간선 입력
	for (int i = 0; i < edge; ++i)
	{
		int a, b, v;
 
		cin >> a >> b >> v;
 
		edges[i].from = a;
		edges[i].to = b;
		edges[i].cost = v;
	}
 
	// 벨만포드
	// 1. n-1번 간선마다 최소 비용을 구한다
	for (int n = 1; n < node; ++n)
	{
		for (int e = 0; e < edge; ++e)
		{
			// 간선의 시작 지점이 start 노드와 연결되어 있지 않다면 continue;
			if (costs[edges[e].from] == MAX)
				continue;
 
			// 현재 간선을 거쳐 가는 것이 더 빠르다면 갱신
			costs[edges[e].to] = min(costs[edges[e].to], costs[edges[e].from] + edges[e].cost);
		}
	}
 
	// 2. 한번 더 갱신을 시도. 만약 갱신 된다면 음수 간선 순환이 발생한 것이므로 -1을 출력
	for (int e = 0; e < edge; ++e)
	{
		// 간선의 시작 지점이 start 노드와 연결되어 있지 않다면 continue;
		if (costs[edges[e].from] == MAX)
			continue;
 
		// 현재 간선을 거쳐 가는 것이 더 빠르다면 갱신
		if (costs[edges[e].to] > costs[edges[e].from] + edges[e].cost)
		{
			cout << -1 << endl;
			return 0;
		}
	}
 
	// 결과 출력
	for (int n = 2; n <= node; ++n)
	{
		if (costs[n] == MAX) cout << -1 << endl;
		else cout << costs[n] << endl;
	}
	return 0;
}