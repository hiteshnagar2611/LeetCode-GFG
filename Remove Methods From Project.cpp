#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Function to find all suspicious methods using BFS
    void findSuspiciousMethods(int k, const vector<vector<int>>& graph, vector<bool>& suspicious) {
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int method = q.front();
            q.pop();

            for (int next : graph[method]) {
                if (!suspicious[next]) {
                    suspicious[next] = true;
                    q.push(next);
                }
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Build the graph
        vector<vector<int>> graph(n);      // Forward graph
        vector<vector<int>> reverseGraph(n); // Reverse graph to track who calls whom

        for (auto& invocation : invocations) {
            int a = invocation[0]; // a calls b
            int b = invocation[1];
            graph[a].push_back(b);
            reverseGraph[b].push_back(a);
        }

        // Step 1: Identify suspicious methods (reachable from k)
        vector<bool> suspicious(n, false);
        findSuspiciousMethods(k, graph, suspicious);

        // Step 2: Check if any method outside the suspicious set calls a suspicious method
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {  // Method i is not suspicious
                for (int next : graph[i]) {
                    if (suspicious[next]) {
                        // Method i calls a suspicious method, so we cannot remove any methods
                        vector<int> allMethods(n);
                        for (int j = 0; j < n; ++j) {
                            allMethods[j] = j;
                        }
                        return allMethods; // Return all methods [0, 1, ..., n-1]
                    }
                }
            }
        }

        // Step 3: Collect all methods that are not suspicious
        vector<int> remainingMethods;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                remainingMethods.push_back(i);
            }
        }

        return remainingMethods;
    }
};
