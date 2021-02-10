#include <iostream>
#include <vector>
#include <queue> 
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

/* Represents a node in the state space tree */
struct Node {
    int level;
    vector<int> path;
    int bound; 

    inline bool operator<(const Node &n) const {
        return bound < n.bound;
    }
};

/* Calculates the lower bound of a node in the state space tree
 * @param v = node, graph = 2d matrix representation of graph, V = number of nodes
 * @return lower bound  
 */
int bound(Node v, vector< vector<int> > graph, int V) {

    int lowerBound = 0;

    vector< vector<bool> > check;
    check.resize(V, vector<bool>(V, false));

    for (int i = 0; i < v.path.size() - 1; i++) {
        for (int j = 0; j < V; j++) {
            check[v.path[i] - 1][j] = true;
        }
        check[v.path[i + 1] - 1][v.path[i] - 1] = true;
        for (int j = 0; j < V; j++) {
            check[j][v.path[i + 1] - 1] = true;
        }
        lowerBound += graph[v.path[i] - 1][v.path[i + 1] - 1];
    }

    for (int i = 0; i < V; i++) {
        int rowMin = INT_MAX;
        bool flag = false;

        for (int j = 0; j < V; j++) {
            if (i != j && check[i][j] == false) {
                flag = true;
                rowMin = min(rowMin, graph[i][j]);
            }
        }
        if (!flag) rowMin = 0;
        lowerBound += rowMin;
    }

    return lowerBound;
}

/* Calculates the length of the tour
 * @param u = node
 * @return int length of the tour
 */
int length(Node u, vector< vector<int> > graph)
{
    int length = 0; /*Value to return, start at 0.*/

    /*Loop through the number of nodes in the path*/
    for(int i = 0; i < u.path.size() - 1; i++)
    {
        /*For every node in the path*/ 
        length += graph[u.path[i] - 1][u.path[i+1] - 1];
    }

    return length;
}
 
/* Calculates the minimum cost in the TSP problem using the best-first search algorithm 
 * Time complexity: 
 * @param graph = 2d matrix representation of graph, V = number of nodes
 * @return minimum cost of TSP problem  
 */
int tspBestFirstSearch(vector< vector<int> > graph, int V) 
{

    /*Create the set of all nodes*/
    set<int> aGV; /*All graph vertices*/

    for(int i = 0; i < V; i++)
    {
        aGV.insert(i+1);
    }

    priority_queue<Node> PQ; // initialize priority queue of nodes  
    Node u;
    Node v;

    vector<int> optPath; /*Variable to store the optimal path*/

    // make first vertex
    v.level = 0;  
    v.path.push_back(1);
    v.bound = bound(v, graph, V);

    int minDist = INT_MAX;

    PQ.push(v);

    while (!PQ.empty()) 
    {
        // dequeue node with best bound
        v = PQ.top();
        PQ.pop();

        if (v.bound < minDist) 
        {
            u.level = v.level + 1; // set u to child of v

            for(int i = 2; i <= V; i++)
            {
                /*Create an iterator for a vector that will check if i is in v.path*/
                vector<int>::iterator it = find(v.path.begin(), v.path.end(), i);

                /*Only perform these operations if i is not in v.path so it returns v.path.end()*/
                if(it == v.path.end())
                {
                    u.path = v.path;
                    u.path.push_back(i);

                    if(u.level == V - 2) /*Check if next vertex completes a tour*/
                    {
                        /*Find the only vertex not in u.path, push it to back*/
                        
                        /*First convert u.path into an ordered set*/
                        set<int> pathCopy;

                        for(int i = 0; i < u.path.size(); i++)
                        {
                            pathCopy.insert(u.path[i]);
                        }

                        /*Compare path copy with allGraphVertices to find the one vertice that is missing*/
                        set<int> diff;

                        set_difference(aGV.begin(), aGV.end(), pathCopy.begin(), pathCopy.end(), inserter(diff, diff.end()));

                        u.path.push_back(*diff.begin());

                        /*Push the starting node to the back*/
                        u.path.push_back(1);

                        /*Create a variable to save value of length(u,graph) so we don't need to call it twice.*/
                        int currLength = length(u, graph);

                        if(currLength < minDist)
                        {
                            minDist = currLength;
                            optPath = u.path;
                        }
                    }
                    else
                    {
                        u.bound = bound(u, graph, V);
                        if(u.bound < minDist)
                        {
                            PQ.push(u);
                        }
                    }
                }

            }
        }
    }

    return minDist;
}
