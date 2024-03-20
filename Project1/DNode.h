#ifndef PROJECT1_DNODE_H
#define PROJECT1_DNODE_H

class DNode {
public:
    int number;
    DNode* prev; 
    DNode* next; 

    DNode(int number) : number(number), prev(nullptr), next(nullptr) {} 
};

#endif //PROJECT1_DNODE_H