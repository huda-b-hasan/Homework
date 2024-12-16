// كود لإثّبات إذا كان بيان مُوجّه مُتّصل بقوّة:
#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V; 
// عددّ الرؤوس
    vector<vector<int>> adj; 
// قائمة الجّوار

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
 // إضافة حافّة من u إلى v
    }

    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;
 // علامة على أنّ الرأس تم زيارته
        for (int u : adj[v]) { 
// استكشاف جميع الجيران
            if (!visited[u]) {
 // إذا لم يتمّ زيارة الجار بعد
                dfs(u, visited); 
// استدعاء DFS لهذا الجار
            }
        }
    }

    bool isStronglyConnected() {
        vector<bool> visited(V, false);

// قم بإجراء DFS من الرّأس الأوّل
        dfs(0, visited);

 // تحققّ ممّا إذا كانت جميع الرؤوس قد تمّت زيارتها
        for (bool v : visited) {
            if (!v) return false; 
// إذا كان هُناك رأس لم يتمّ زيارته، الرّسم البياني ليس مُتصلًا بقوة
        }

        // إنشاء الرسم البياني المعكوس
        vector<vector<int>> transposed(V);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                transposed[v].push_back(u); 
// عكس الاتّجاه
            }
        }

 // إعادة تعيين الزّيارة:
        fill(visited.begin(), visited.end(), false);

 // قم بإجراء DFS على الرّسم البياني المعكوس:
        dfs(0, visited);

 // تحققّ ممّا إذا كانت جميع الرّؤوس قد تمّت زيارتها في الرّسم البياني المعكوس
        for (bool v : visited) {
            if (!v) return false; 
// إذا كان هناك رأس لم يتمّ زيارته، الرّسم البياني ليس مُتصلًا بقوّة
        }

        return true; 
// إذا تمّت زيارة جميع الرّؤوس في كِلتا العمليتين، الرّسم البياني مُتصل بقوّة
    }
};

int main() {
    Graph g(5); 
// إنشاء رسم بياني بـ 5 رؤوس
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    if (g.isStronglyConnected()) {
        cout << "الرسم البياني مُتصل بقوة." << endl;
    } else {
        cout << "الرسم البياني ليس مُتصلًا بقوة." << endl;
    }

    return 0;
}
//  المجموعة الأولى الخطوة الأولى من الوظيفة تم حلّها من قِبَل :
// هبه حسينو، روان أبو سيف، غزل أحمد، ماريا إدّريس، رهام الدّرويش، ميسم عمر .