#include <iostream>
#include<iomanip>
using namespace std;

int max_prob(double prob[105][105], bool been[], int source, int n);

int main() {
    int n, m, r;
    double graph[105][105], prob[105][105];
    for(int i = 0; i < 105; i++) {
        for(int j = 0; j < 105; j++) {
            graph[i][j] = -1;
            prob[i][j] = -1;
        }
    }
    cin >> n >> m >> r;
    while(m--) {
        int a, b;
        double p;
        cin >> a >> b >> p;
        graph[a][b] = p;
        graph[b][a] = p;
    }

    while(r--) {
        int a, b;
        bool been[105];
        for(int i = 0; i < 105; i++) been[i] = false;
        cin >> a >> b;
        if(prob[a][a] == -1) {
            prob[a][a] = 1;
            for(int i = 0; i < n; i++) {
                int u = max_prob(prob, been, a, n);
                been[u] = true;
                for(int j = 0; j < n; j++) {
                    if(!been[j] && graph[u][j] != -1 && prob[a][u] != -1 && prob[a][u] * graph[u][j] > prob[a][j])
                        prob[a][j] = prob[a][u] * graph[u][j];
                }
            }
        }
        if(prob[a][b] != -1 && a != b) cout << fixed << setprecision(5) << prob[a][b] <<endl;
        else cout << fixed << setprecision(5) << 0.00000 <<endl;
    }
}

int max_prob(double prob[105][105], bool been[], int source, int n) {
    double max = -1;
    int max_idx;
    for(int i = 0; i < n; i++)
        if(!been[i] && prob[source][i] > max)
            max = prob[source][i], max_idx = i;
    return max_idx;
}
