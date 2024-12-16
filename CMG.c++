// كود لخوارزمية
// Cheriayan Mehlhorn Gabow:

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>

using namespace std;

const int INF = numeric_limits<int>::max();

class MaxFlow {
public:
    MaxFlow(int n) : n(n), adj(n), capacity(n, vector<int>(n, 0)) {}

    void addEdge(int u, int v, int cap) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += cap; // Allow parallel edges
    }

    int fordFulkerson(int source, int sink) {
        int maxFlow = 0;
        while (true) {
            vector<int> parent(n, -1);
            queue<int> q;
            q.push(source);
            parent[source] = source;

            while (!q.empty() && parent[sink] == -1) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (parent[v] == -1 && capacity[u][v] > 0) 

// في حال لم تتمّ زيارة العقد و هناك حجم إضافيّ:

                  {     parent[v] = u;
                        q.push(v);
                        if (v == sink) break;
                    }
                }
            }

            if (parent[sink] == -1) break; 

//لا مزيد من المسّارات المُعزّزة:

// إيجاد الحدّ الأقصى للتّدفق عبر المسّار الموجود.
            int flow = INF;
            for (int v = sink; v != source; v = parent[v])
 {
                int u = parent[v];
                flow = min(flow, capacity[u][v]);
            }

//قم بتحديث قدرات الحواف و الحواف العكسيّة على طول المسار:

            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                capacity[u][v] -= flow;
                capacity[v][u] += flow;
            }

            maxFlow += flow;
        }
        return maxFlow;
    }

//عددّ القُمم:
private:
    int n;
    vector<vector<int>> adj; 

// Adjacency list:

    vector<vector<int>> capacity; // Capacity matrix
};

int main() {
    int n = 6; 
//عددّ القُمم:
    MaxFlow mf(n);

    mf.addEdge(0, 1, 16);
    mf.addEdge(0, 2, 13);
    mf.addEdge(1, 2, 10);
    mf.addEdge(1, 3, 12);
    mf.addEdge(2, 1, 4);
    mf.addEdge(2, 4, 14);
    mf.addEdge(3, 2, 9);
    mf.addEdge(3, 5, 20);
    mf.addEdge(4, 3, 7);
    mf.addEdge(4, 5, 4);

    cout << "The maximum possible flow is " << mf.fordFulkerson(0, 5) << endl;

    return;

//زمن تنفيذ هذه الخرارزميّة:
// أ_إذا كانت list أو array :
O([E]+[v])
//    ب_لو كانت matrix :
O([v*2])

//القسم الثّاني: زهراء سعد الدّين، نور الهدى حسن، هلا فندو، فاطمة أحمد، فرح ابراهيم، نور السّيد