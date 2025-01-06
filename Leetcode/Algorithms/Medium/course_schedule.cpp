
/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/course-schedule/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool kahnAlgorithm(const vector<vector<int>>& adjList){

        // First pass to set the degrees of each node
        vector<int> degree(adjList.size());
        for (int i = 0; i < adjList.size(); i++) {
            for (int j = 0; j < adjList[i].size(); j++) {
                degree[adjList[i][j]]++;
            }
        }

        queue<int> q;
        // We intially store all nodes with 0 degrees
        for(int i = 0; i < degree.size(); i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }

        // Nodes that have been processed (have had at some)
        // point 0 degree.
        int nodesProcessed{0};

        // When the queue is empty either the graph is done
        // or a cycle is reached.
        while(!q.empty()){
            // Pop a node, place it in the topological order,
            // and then decrement the neighbors.
            int node = q.front();
            nodesProcessed++;
            for(int i = 0; i < adjList[node].size(); i++){
                int index = adjList[node][i];
                degree[index]--;
                if(degree[index] == 0){
                    q.push(index);
                }
            }
            q.pop();
        }

        return nodesProcessed == adjList.size();
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Basically, we have m courses, and these courses can have
        // prerequisites. To be able to take all m courses, we need to
        // not have any loops in the prerequisites. We can construct
        // a directed graph where an edge connects two nodes if one is
        // a prerequisite. We then use Kahn's algorithm, which can find
        // the topoligical ordering of a directed graph only if it has
        // no cycles. It returns false if there are cycles, making it
        // perfect for our use.
        
        // We can modify the algorithm so that it doesn't try to find
        // the order at all.

        // First we build an adjacency list (could also be a matrix,
        // but the list is better for sparser graphs).
        vector<vector<int>> adjList(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        return kahnAlgorithm(adjList);
    }
};