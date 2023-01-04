#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Topological Sorting

        map<int, vector<int>> graph;
        map<int, int> inDegree;
        vector<int> nodeOrder;

        for (auto x : prerequisites)
        {
            // Storing courses that can be done after particular x[1]
            graph[x[1]].push_back(x[0]);

            // Storing the number of Course must do before x[0]
            inDegree[x[0]]++;
        }

        // Finding Node that has zero incoming Course to be done
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                nodeOrder.push_back(i);
            }
        }

        // Starting from first element in the nodeOrder
        //   |-> Eliminate the nodes having zero incoming Course to be done

        for (int i = 0; i < nodeOrder.size(); i++)
        {
            for (auto j : graph[nodeOrder[i]])
            {

                // Reducing the degree as the node is getting eliminated
                inDegree[j]--;

                // Adding the node in nodeOrder if the incoming Courses become zero
                if (inDegree[j] == 0)
                    nodeOrder.push_back(j);
            }
        }

        return nodeOrder.size() == numCourses;
    }
};