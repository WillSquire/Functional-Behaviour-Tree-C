//
//  main.c
//  Functional Behaviour Tree
//
//  Created by Will Squire on 27/06/2015.
//  Copyright (c) 2015 www.william-squire.com. All rights reserved.
//

#include <stdio.h>

// Bool
typedef enum { false, true } bool;

typedef struct {
    //noeds
} Blackboard;

typedef bool (*Node)(Blackboard blackboard);

void selector_add(Blackboard blackboard, Node node) {
    //blackboard -> nodes.add();
}

bool selector(Node nodes[], Blackboard blackboard) {
    
    bool result = false;
    int length = sizeof(nodes);///sizeof(nodes[0]);
    
    printf("Array length: %lu", (sizeof(nodes)/sizeof(nodes[0])));
    
    
    //char buf[256];
    //sprintf(buf, "%d", length);
    //printf("%d", nodes[0](blackboard));
    /*
    for (int i = 0; i < length; i++) {
        if (nodes[i](blackboard))
        result = true;
    }
     */
    
    return result;
}

bool sequence(Node nodes[]) {
    return true;
}

bool basicNode(Blackboard blackboard) {
    return true;
}


int main(int argc, const char * argv[]) {
    Node nodes[512]; 
    Blackboard blackboard;
    nodes[0] = basicNode;
    nodes[1] = basicNode;
    selector(nodes, blackboard);
    
    return 0;
}
