#include <iostream>
#include <vector>
#include <queue> 
#include <climits>
#include <algorithm>

using namespace std;

/* Calculates the cost of one possible permutation of nodes
 * @param graph = 2d matrix representation of graph, nodes = permutation order of nodes, V = number of nodes
 * @return distance 
 */
int calcDistance(vector<vector<int> > graph, vector<int> nodes, int V) {

    int dist = 0;

    // calculate cost by summing up distances between nodes in specified permutation order
    for (int  i = 0; i < V - 1; i++) {
        dist += graph[nodes[i]][nodes[i + 1]];
    }
    dist += graph[nodes[V - 1]][nodes[0]]; // complete cycle
    return dist;
}

/* Calculates the minimum cost in the TSP problem using brute force (calculates the cost of every possible permutation of nodes to find the minimum) 
 * Time complexity: O(n!)
 * @param graph = 2d matrix representation of graph, V = number of nodes
 * @return minimum cost of TSP problem  
 */
int tspBruteForce(vector<vector<int> > graph, int V) {

    // array of nodes used to store permutations
    vector<int> nodes; 
    for (int i = 0; i < V; i++) {
        nodes.push_back(i); 
    }

    int minDist = INT_MAX;

    do {
        int dist = calcDistance(graph, nodes, V); // calculate cost of permutation 
        minDist = min(minDist, dist); // save minimum cost found 
    } while (next_permutation(nodes.begin(), nodes.end())); // STL function that finds all permutations of a set 

    // return minimum cost found
    return minDist;
}
