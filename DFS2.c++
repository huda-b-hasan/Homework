#include <iostream>
#include <vector>
#include <set>

using namespace std;

void depthFirstSearch(const vector<vector<int>>& graph, int s, set<int>& visited) {
    // اضافة العنصر الحالي إلى المجموهة المزارة
    visited.insert(s);
    cout << s << " "; 

    // اكتشاف العقد المجاوره
    for (int x : graph[s]) {
        if (visited.find(x) == visited.end()) {
            depthFirstSearch(graph, x, visited);
        }
    }
}

int main() {  
    // تمثيل البيان ك مصفوفه جوار
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1, 5},
        {1, 2, 5},
        {3, 4}
    };

    set <int> visited;
    depthFirstSearch(graph, 0, visited);

    return 0;
}
// coding by huda hasan (هدى حسن)
