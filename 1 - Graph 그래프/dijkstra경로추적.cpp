#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
const int INF = 1e9 + 7;
using ll = long long;
using namespace std;

// 다익스트라는 모든 간선이 양수일 때 사용할 수 있다는 한계를 기억
int N, M, A, B;
ll dist[MAX];
int path_back[MAX] = {0, };
vector<pair<int, int>> graph[MAX];


//우선순위 큐를 이용한 다익스트라 구성
void dijkstra(int start){
    dist[start]= 0;
    path_back[start] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> PQ;
    PQ.push({0, start});

    while(!PQ.empty()){

        int cost = PQ.top().first;
        int node = PQ.top().second;
        PQ.pop();

        if (dist[node] < cost) continue;

        for(int i=0; i < graph[node].size(); i++){
            int n_cost = graph[node][i].first;
            int next = graph[node][i].second;

            if (dist[next] > cost + n_cost){
                dist[next] = cost + n_cost;
                path_back[next] = node;
                PQ.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill_n(dist, MAX, INF);

    cin >> N;
    cin >> M;

    for(int i=0; i < M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
    }

    cin >> A >> B;
    dijkstra(A);

    cout << dist[B] << "\n";

    vector<int> ret;
    ret.push_back(B);

    int path = path_back[B];
    while(path){
        ret.push_back(path);
        path = path_back[path];
    }

    cout << ret.size() << "\n";
    for(int i= ret.size()-1; i >= 0; i--){
        cout << ret[i] << " ";
    }

    return 0;
}
