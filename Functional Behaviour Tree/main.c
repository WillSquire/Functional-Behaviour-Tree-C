//
//  main.c
//  Functional Behaviour Tree
//
//  Created by Will Squire on 27/06/2015.
//  Copyright (c) 2015 www.william-squire.com. All rights reserved.
//

#include <stdio.h>

//------------------------------------------------------
// Typedefs
//------------------------------------------------------

typedef enum {false, true} bool;
typedef struct {} Blackboard;
typedef bool (*Node)(Blackboard blackboard);

//------------------------------------------------------
// Functions
//------------------------------------------------------

bool selector(Node nodes[], Blackboard blackboard) {
    int i=0;
    while (NULL!=nodes[i]) {
        if (nodes[i](blackboard))
            return true;
        ++i;
    }
    return false;
}

bool sequence(Node nodes[], Blackboard blackboard) {
    int i=0;
    while (NULL!=nodes[i]) {
        if (!nodes[i](blackboard))
            return false;
        ++i;
    }
    return true;
}

//------------------------------------------------------
// Unit Testing
//------------------------------------------------------

bool node_test_true(Blackboard blackboard) { return true; }
bool node_test_false(Blackboard blackboard) { return false; }

int main(int argc, const char * argv[]) {
    Node nodes[512];
    Blackboard blackboard;
    nodes[0] = node_test_true;
    nodes[1] = node_test_true;
    nodes[2] = node_test_false;
    nodes[3] = NULL;
    printf("%d \n", sequence(nodes, blackboard));
    
    return 0;
}
