#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
PROBLEM STATEMENT - You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

NOTE : Choose the next flower to plant from available flower types in ascending order, means if 1 and 4 both can be used then we will use 1 instead of 4.
*/

void planting_With_No_Adjacent(int gardens, vector<vector<int>> &vec)
{
    /* We need to convert the adjacency list into the corresponding adjacency matrix because we need to traverse the neighbours of a node in an ascending order in the for loop named 'YEH VAALA FOR LOOP'. The reason is that we have to plant the lowest available flower. Thus, we must traverse the neighbours in an ascending order. In the adjacency list the neighbours are not sorted because their order depends on the order of input. In an adjacency matrix we can traverse in the ascending order.
    For example - Consider this test case:
    4
    6
    1 2 2 3 3 4 4 1 1 3 2 4
    Here the output we will get if we directly use the adjacency list to form the answer vector is {1, 2, 4, 3}. However, the expected answer here is {1, 2, 3, 4}. Thus, if we would have considered garden 3 before garden 4 we would have got the expected answer. However, by using the adjacency list we reach garden 4 before garden 3. Thus, flower 3 is assigned to garden 4 and not garden 3. Thus, by using the adjacenecy matrix, we consider garden 3 before garden 4.
    */
    vector<vector<int>> adj = vector<vector<int>>(gardens);
    for (int i = 0; i < gardens; i++)
    {
        for (int j = 0; j < gardens; j++)
        {
            if (vec[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> colours(gardens);
    for (int i = 0; i < gardens; i++)
    {
        if (colours[i] == 0)
        {
            colours[i] = 1;
            queue<int> q;
            q.push(i);
            while (!(q.empty()))
            {
                int current = q.front();
                q.pop();
                // YEH VAALA FOR LOOP -
                for (auto j : adj[current])
                {
                    if (colours[j] == 0 || colours[j] == colours[current])
                    {
                        // If we enter this if consdition it means we have to change the value of colours[j].
                        if (colours[j] == 0)
                        {
                            /* If we enter this if condition, it means that j has not yet been visited even once. Thus, we assign flower 1 to it. We are supposed to assign the lowest available flower to a garden. Thus, even though other flower types may be available, we begin by assigning flower 1 to the garden.
                             */
                            colours[j] = 1;
                        }
                        if (colours[j] == colours[current])
                        {
                            /* If we enter this if condition, it means that the neighbour j and the current garden have the same flowers planted in them. Thus, we assign flower type one more than that planted in the current garden to the neighbour j garden. This if condition must be after the (colours[j] == 0) if condition because we have j garden only after assigning flower 1 to the neighbour j.
                             */
                            colours[j] = colours[current] + 1;
                        }
                        q.push(j);
                    }
                    if (colours[j] > 4)
                    {
                        /* If we assign a flower type more than 4 to a garden then we must loop it back to the {1, 2, 3, 4} sequence. Thus, we must assign the flower type equal to (colours[j] % 4).
                         */
                        colours[j] %= 4;
                    }
                }
            }
        }
    }
    for (auto i : colours)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int gardens, garden_Pairs;
    cin >> gardens >> garden_Pairs;
    // adj = vector<vector<int>> (gardens);
    vector<vector<int>> adj = vector<vector<int>>(gardens, vector<int>(gardens));
    int a, b;
    for (int i = 0; i < garden_Pairs; i++)
    {
        cin >> a >> b;
        adj[a - 1][b - 1] = 1;
        adj[b - 1][a - 1] = 1;
    }
    planting_With_No_Adjacent(gardens, adj);
    return 0;
}