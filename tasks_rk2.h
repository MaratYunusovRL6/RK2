//
// Created by Admin on 22.05.2023.
//
#ifndef RK2_TASKS_RK2_H
#define RK2_TASKS_RK2_H
#include "list"
#include "iostream"
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
    void buildTreeDFS(Node* parent, int countNodes);
    void DFS(Node* parent, FILE* f);
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
