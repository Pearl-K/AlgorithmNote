//백준 2533 사회망 서비스 : https://www.acmicpc.net/problem/2533

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
vector<vector<int>> edge;
int visited[1000001];

pii dfs(int node){
    visited[node] = true;
    pii ret = {1, 0};
    for (auto &next: edge[node]){
        if(!visited[next]){
            pii child = dfs(next);
            ret.first += min(child.first, child.second);
            ret.second += child.first;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, u, v;
    cin >> N;

    edge.resize(N+1);
    pii ret;

    for(int i=0; i < N-1; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    ret = dfs(1);
    cout << min(ret.first, ret.second);

    return 0;
}
