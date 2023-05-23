#include "tasks_rk2.h"
#include <iostream>
#include "queue"
using namespace std;
int Node::countNodes=0;
Node::Node(){
    parent = nullptr;
    name=countNodes;
    ishere=false;
}
Node:: ~Node(){
    parent= nullptr;
    countNodes=0;
    ishere=false;
}
Node::Node(int nameNode){
    ishere=false;
    parent=nullptr;
    name=nameNode+1;
}
Graph::Graph() {
    head=new Node;
    head->parent= nullptr;
}

Graph::~Graph() {
    delete head;
}
Graph::Graph(int countNodes){
    head=new Node(countNodes);
}
int Graph::buildTreeBFS(int countNodes) {
    int rootNodeName = 0;
    Node* rootNode = new Node(rootNodeName);
    std::queue<Node*> q;
    q.push(rootNode);
    int currentNodeCount = countNodes;
    int currentName = 1;
    while (!q.empty()) {
        Node* currentParent = q.front();
        q.pop();

        for (int i = 0; i < currentNodeCount; i++) {
            Node* currentChild = new Node(currentName);
            currentName++;

            currentParent->listChilds.push_back(currentChild);
            currentChild->parent = currentParent;
            q.push(currentChild);
        }

        currentNodeCount--;
        if (currentNodeCount < 1) {
            currentNodeCount = countNodes - 1;
        }
    }
    return Node::countNodes;
}
void Graph::DFS(){

}


