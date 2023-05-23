#include "tasks_rk2.h"
#include <iostream>
#include "queue"
#include "lsfilofifo.h"
using namespace std;
int Node::countNodes=0;
static int count = 0;
Node::Node(){
    parent = nullptr;
    name=countNodes;
    ishere=false;
}
Node:: ~Node(){
    std::destroy(listChilds.begin(),listChilds.end());
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
int Graph::buildTreeDFS(int countNodes){
    if(countNodes < 0)
        return -1;
    head = new Node;
    count = 0;
    head->name = count++;
    buildTreeDFS(head, countNodes);
    return 0;
}
void Graph::buildTreeDFS(Node* parent, int countNodes){
    if(countNodes > 0)
        for(int i = 0; i < countNodes; i++){
            Node* f = new Node;
            f->name = count++;
            parent->listChilds.push_back(f);
            buildTreeDFS(f, countNodes - 1);
        }
}
void Graph::DFS(){
    FILE* f = fopen("dfs.txt", "w");
    DFS(head, f);
    fclose(f);
}
void Graph::DFS(Node* parent, FILE* f) {
    fprintf(f, "%d", parent->name);
    if(parent->listChilds.size()){
        fprintf(f, "%c", '{');
    }
    for (std::list<Node *>::iterator it = parent->listChilds.begin(); it != parent->listChilds.end(); it++) {
        DFS(*it, f);
        if (!(std::next(it) == parent->listChilds.end()))
            fprintf(f, "%c", ',');
    }
    if(parent->listChilds.size())
        fprintf(f, "%c", '}');

}

