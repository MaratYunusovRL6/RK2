//
// Created by Admin on 22.05.2023.
//

#ifndef RK2_TASKS_RK2_H
#define RK2_TASKS_RK2_H
#include "queue"
#include "list"
struct Node{
    Node();
    Node(int nameNode);
    Node* parent;
    std::list<Node*> listChilds;
    bool ishere;
    int name;
    static int countNodes;
    ~Node();
};
class Graph{
private:
    Node*head;
public:
    void DFS();
    void BFS();
    int buildTreeDFS(int countNodes);
    int buildTreeBFS(int countNodes);
    Graph(int number);
    Graph();
    ~Graph();

    std::pair<bool, std::list<int>> search_DFS(int nameNode);

    std::pair<bool, std::list<int>> search_BFS(int nameNode);
};

#endif //RK2_TASKS_RK2_H
