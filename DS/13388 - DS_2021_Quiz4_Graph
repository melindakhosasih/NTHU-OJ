#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;
int max_prob(double **prob, bool been[], int source, int n) {
    double max = -1;
    int max_idx;
    for(int i = 0; i < n; i++)
        if(!been[i] && prob[source][i] > max)
            max = prob[source][i], max_idx = i;
    return max_idx;
}

int main() {
    int n, m, r;
    double **graph, **prob;
    graph = new double*[505];
    prob = new double*[505];
    for(int i = 0; i < 505; i++) {
        graph[i] = new double[505];
        prob[i] = new double[505];
    }
    for(int i = 0; i < 505; i++) {
        for(int j = 0; j < 505; j++) {
            graph[i][j] = -1;
            prob[i][j] = -1;
        }
    }
    cin >> n >> m >> r;
    while(m--) {
        int a, b;
        double p;
        cin >> a >> b >> p;
        if(graph[a][b] < p) {
            graph[a][b] = p;
            graph[b][a] = p;
        }
    }
    while(r--) {
        int s, e;
        cin >> s >> e;
        if(s == e && s < n && e < n) {
            cout << fixed << setprecision(5) << 1.00000 << endl;
            continue;
        } else if(s >= n || e >= n) {
            cout << fixed << setprecision(5) << 0.00000 <<endl;
            continue;
        }
        bool been[505];
        for(int i = 0; i < 505; i++) been[i] = false;
        if(prob[s][s] == -1) {
            prob[s][s] = 1;
            for(int i = 0; i < n; i++) {
                int u = max_prob(prob, been, s, n);
                been[u] = true;
                for(int j = 0; j < n; j++) {
                    if(!been[j] && graph[u][j] != -1 && prob[s][u] != -1 && prob[s][u] * graph[u][j] > prob[s][j])
                        prob[s][j] = prob[s][u] * graph[u][j];
                }
            }
        }
        if(prob[s][e] != -1) cout << fixed << setprecision(5) << prob[s][e] <<endl;
        else cout << fixed << setprecision(5) << 0.00000 <<endl;
    }
}
