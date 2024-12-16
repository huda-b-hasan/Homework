#include <iostream>
#include <vector>
#include <algorithm> // لاستخدام std::find

using namespace std;

void depthFirstSearch(const vector<vector<int>>& graph, int start, vector<int>& visited) {
    // إضافة العنصر الحالي إلى القائمة المُزارة
    visited.push_back(start);

    // استكشاف الجوار
    for (int neighbor : graph[start]) {
        if (find(visited.begin(), visited.end(), neighbor) == visited.end()) {
            depthFirstSearch(graph, neighbor, visited);
        }
    }
}

int main() {
    // تمثيل الرسم البياني كمصفوفة متجاورة (قائمة من القوائم)
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1, 5},
        {1, 2, 5},
        {3, 4}
    };

    vector<int> visited;
    depthFirstSearch(graph, 0, visited);

    // طباعة العناصر المُزارة
    for (int node : visited) {
        cout << node << " ";
    }

    return 0;
}
