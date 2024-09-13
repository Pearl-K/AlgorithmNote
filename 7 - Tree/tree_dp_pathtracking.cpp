#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int W[100001];
bool vst[10001]= {false, };
int dp[100001][2] = {-1, };
vector<int> tree[10001];
vector<int> path;

void dfs(int node){
    dp[node][0] = 0;
    dp[node][1] = W[node];
    vst[node]= true;

    for(int i=0; i < tree[node].size(); i++){
        int next = tree[node][i];
        if(!vst[next]){
            dfs(next);
            dp[node][0] += max(dp[next][0], dp[next][1]); //자기 포함 X, 다음 포함 O
            dp[node][1] += dp[next][0]; //자기 포함 O, 다음 포함 여부 탐색
        }
    }
}

void path_tracking(int prev, int node){
    if(!vst[prev] && dp[node][1] > dp[node][0]){
        path.push_back(node);
        vst[node] = true;
    }

    for(int i =0; i < tree[node].size(); i++){
        int next = tree[node][i];
        if (prev != next) path_tracking(node, next);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i=1; i <= N; i++) cin >> W[i];

    for (int i=0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    //tree dp로 내 가중치를 포함하고 다음을 건너뛰거나,
    // 날 선택하지 않고 다음을 택하거나 determine?
    // 단순히 dp 테이블만 채워서 구하는게 아니라 역추적도 해야함

    dfs(1);
    memset(vst, 0, sizeof(vst));
    path_tracking(0, 1);
    sort(path.begin(), path.end());

    int ret = max(dp[1][0], dp[1][1]);
    cout << ret << '\n';
    for(int i=0; i < path.size(); i++) cout << path[i] << " ";
    return 0;
}
