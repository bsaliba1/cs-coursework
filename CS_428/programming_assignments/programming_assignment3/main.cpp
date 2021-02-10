/*
 * CS 428
 * Baptiste Saliba
 * Programming Assignment 3
 */


#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>


using namespace std;

// Structural Declarations
struct edge;
typedef char NODE; //char represents a NODE
typedef map<NODE, vector<edge> > GRAPH; // NODE maps to list of edges to adjacent nodes


// Function Definitions
void evaluate(GRAPH, NODE);
void djikstra(GRAPH, set<NODE>, NODE);
NODE get_min(map<NODE, int>, set<NODE>);
void print_table_line(int, set<NODE>, map<NODE, int>, map<NODE,NODE>);
void print_header(set<NODE>, NODE);

// Edge Implementation
struct edge{
    NODE dest;
    int length;
};

//Test cases for Part A, B, and C
vector< GRAPH > TESTS{
        //Figure 4.27
        {
                {'u',
                    { edge{'w',5}, edge{'x', 1}, edge{'v', 2} }
                },
                {'v',
                    { edge{'u', 2}, edge{'w',3}, edge{'x', 2} }
                },
                {'w',
                    { edge{'u', 5}, edge{'y', 1}, edge{'v', 3}, edge{'x',3}, edge{'z', 5}}
                },
                {'x',
                    { edge{'u', 2}, edge{'v', 2}, edge{'w', 3}, edge{'y', 1} }
                },
                {'y',
                    { edge{'x', 1}, edge{'w', 1}, edge{'z', 2}}
                },
                {'z',
                    { edge{'y', 2}, edge{'w', 5} }
                }
        },
        // Given Example
        {
                {'t',
                        { edge{'u',2}, edge{'v', 4}, edge{'y', 7} }
                },
                {'u',
                        { edge{'t',2}, edge{'v', 3}, edge{'w', 3} }
                },
                {'v',
                        { edge{'u', 3}, edge{'t',4}, edge{'y', 8}, edge{'x', 3}, edge{'w',4} }
                },
                {'w',
                        { edge{'u', 3}, edge{'v', 4}, edge{'x', 6}}
                },
                {'x',
                        { edge{'w', 6}, edge{'v', 3}, edge{'y', 6}, edge{'z', 8} }
                },
                {'y',
                        { edge{'z', 12}, edge{'x', 6}, edge{'v', 8}, edge{'t', 7} }
                },
                {'z',
                        { edge{'x', 8}, edge{'y', 12} }
                }
        },
        // Example from interactive course website
        {
                {'u',
                        { edge{'w',7}, edge{'x', 5}, edge{'v', 4} }
                },
                {'v',
                        { edge{'u', 4}, edge{'w',3}, edge{'x', 9} }
                },
                {'w',
                        { edge{'u', 7}, edge{'y', 1}, edge{'v', 3}, edge{'x',2}, edge{'z', 1}}
                },
                {'x',
                        { edge{'u', 5}, edge{'v', 9}, edge{'w', 2}, edge{'y', 9} }
                },
                {'y',
                        { edge{'x', 9}, edge{'w', 1}, edge{'z', 3}}
                },
                {'z',
                        { edge{'y', 3}, edge{'w', 1} }
                }
        }
};


void evaluate(GRAPH g, NODE src){
    set<NODE> node_list;

    //Get and store all nodes from graph in list of nodes 'node_list'
    for(auto iter = g.begin(); iter != g.end(); ++iter) {
        NODE node =  iter->first;
        node_list.insert(node);
    }

    djikstra(g, node_list, src);
}

void djikstra(GRAPH g, set<NODE> node_list, NODE src){
    set<NODE> n{src}; // N' : set of visited nodes
    map<NODE,NODE> to_from; // Allows for backtracking
    map<NODE, int> distances; // Keeps track of distances from src to all other nodes
    int step = 0;

    // Initialize all node distances to infinity
    for(auto node : node_list){
        if(node != src) {
            distances[node] = INT_MAX;
        }
    }

    print_header(node_list, src);

    // Djikstra Initialization
    // Update distances for all src's adjacent nodes
    vector<edge> adj_list = g[src];
    for(int i=0; i<g[src].size(); i++){
        edge e = adj_list[i];
        distances[e.dest] =  e.length; // update distance to adjacent node
        to_from[e.dest] = src; // update backtrack node for that adjacent node
    }

    print_table_line(step, n, distances, to_from);
    step++;

    //Add minimum node to the set N' and update all distances until N' it contains all the nodes from the node_list
    while(n.size() != node_list.size()) {
        // Get minimum node and add it to N'
        NODE min_node = get_min(distances, n);
        n.insert(min_node);

        vector<edge> min_edges = g[min_node]; // outward edges from min node

        // Update all distances to adjacent nodes
        for(int i = 0; i < min_edges.size(); i++) {
            NODE adj_node = min_edges[i].dest;
            if(adj_node == src){
                continue;
            }

            // New cost to adj_node is either old cost to adj_node or known least path cost to min_node plus cost from min_node to adj_node
            // 'if' block prevents int overflow error
            if (distances[adj_node] == INT_MAX) {
                distances[adj_node] = distances[min_node] + min_edges[i].length;
                to_from[adj_node] = min_node;
            } else {
                if(distances[min_node] + min_edges[i].length < distances[adj_node]){
                    distances[adj_node] = distances[min_node] + min_edges[i].length;
                    to_from[adj_node] = min_node;
                }
            }
        }
        print_table_line(step, n, distances, to_from);
        step++;
    }
    cout<<endl;
}

NODE get_min(map<NODE, int> distances, set<NODE> n){
    int min = INT_MAX; // Current minimum
    NODE min_node = '?'; // Current minimum node

    // Iterate through distances map
    for(auto iter = distances.begin(); iter != distances.end(); ++iter){
        NODE node = iter->first;
        int length = iter->second;

        // If length to get to node is less than current min and node not in N', then it is the new current minimum
        if(length<=min && n.find(node) == n.end()){
            min = length;
            min_node = node;
        }
    }

    return min_node;
}

// Display each line of the table; a lot of formatting stuff here that you can ignore
void print_table_line(int step, set<NODE> n, map<NODE, int> distances, map<NODE, NODE> to_from){
    cout<<setw(10)<<step;
    string temp = "";
    for(auto c: n){
        temp+=c;
    }
    cout<<setw(10)<<temp;
    for(auto iter = distances.begin(); iter != distances.end(); ++iter){
        if(n.find(iter->first) == n.end()) {
            if (iter->second == INT_MAX) {
                cout << setw(15) << "∞";
            } else {
                cout << setw(11) << iter->second<<","<<to_from[iter->first];
            }
        }else{
            cout<<setw(13)<<"---";
        }
    }
    cout<<endl;
}

// Display header of table
void print_header(set<NODE> node_list, NODE src){
    cout<<setw(10)<<"Step"<<setw(10)<<"N'";
    for(auto c : node_list){
        if(c != src) {
            cout << "    D(" << c << "),p(" << c << ")";
        }
    }
    cout<<endl;
    cout<<"      -------------------------------------------------------------------------------"<<endl;
}

//Driver
int main(int argc, char* argv[]) {

    NODE src = 'u';
    if(argc >= 2){
        src = argv[1][0];
    }

    // For each GRAPH in TESTS run the djikstra on the src node (default 'u')
    cout<<endl;
    for(int i=0; i<TESTS.size(); i++){
        cout<<"TEST "<<i+1<<endl;
        evaluate(TESTS[i], src);
    }
    return 0;
}