#include <iostream>
#include <algorithm>
#include <list>
#include <climits>
using namespace std;

typedef struct node {
    int dest;
} node;

class Graph {
    int n;
    list<node> *route;
public:
    Graph(int n) {
        this->n = n;
        route = new list<node> [2005];
    }
    void Add(int v, int u, int w);
    friend void Shortest (Graph graph, unsigned long *len, int start, int finish);
};

unsigned long ans = ULLONG_MAX;
int weight[2005][2005];

void Graph::Add(int v, int u, int w) {
    node temp;
    temp.dest = u;
    route[v].push_back(temp);
    temp.dest = v;
    route[u].push_back(temp);
}

int min_path(unsigned long len[], bool been[], int n) {
    unsigned long min;
    int min_idx;
    min = ULLONG_MAX;
    for(int i = 0; i <= n; i++)
        if(!been[i] && len[i] <= min)
            min = len[i], min_idx = i;
    return min_idx;
}

void Shortest (Graph graph, unsigned long *len, int start, int finish) {
    int n = graph.n;
    bool been[n];
    for(int i = 0; i <= n; i++) {
        len[i] = ULLONG_MAX;
        been[i] = false;
    }
    len[start] = 0;
    for(int i = 0; i < n-1; i++) {
        int u = min_path(len, been, n);
        been[u] = true;
        list<node> :: iterator it;
        for(it = graph.route[u].begin(); it != graph.route[u].end(); it++) {
            if(!been[it->dest] && weight[u][it->dest] > 0 && len[u] + weight[u][it->dest] < len[it->dest]) {
                len[it->dest] = len[u] + weight[u][it->dest];
            }
        }
    }
    if(ans > len[finish]) ans = len[finish];
    return;
}

int main() {
    int n, s, e, t, b;
    int u, v, w;
    cin >> n >> s >> e;
    cin >> t;
    Graph graph(n);
    unsigned long len_start[2005], len_finish[2005];
    while(t--) {
         cin >> v >> u >> w;
         if(weight[v][u] == 0 || weight[v][u] > w) {
            if(weight[v][u] == 0) graph.Add(v, u, w);
            weight[v][u] = w;
            weight[u][v] = w;
         }
    }
    Shortest(graph, len_start, s, e);
    Shortest(graph, len_finish, e, s);
    cin >> b;
    while(b--) {
        cin >> v >> u >> w;
        if((len_start[v] + len_finish[u] + w < ans) && len_start[v] != ULLONG_MAX && len_finish[u] != ULLONG_MAX) ans = len_start[v] + len_finish[u] + w;
        if((len_start[u] + len_finish[v] + w < ans) && len_start[u] != ULLONG_MAX && len_finish[v] != ULLONG_MAX) ans = len_start[u] + len_finish[v] + w;
    }
    if(ans == ULLONG_MAX || ans <= 0) cout << "0\n";
    else cout << ans << endl;
}
