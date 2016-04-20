//
//  functional_behaviour_tree.c
//  Functional Behaviour Tree
//
//  Created by Will Squire on 08/04/2016.
//  Copyright © 2016 Will Squire. All rights reserved.
//

#include "../include/functionalbehaviourtree.h"

//------------------------------------------------------
// Functions (Implementation)
//------------------------------------------------------

bool selector(Node nodes[], Blackboard* blackboard) {
    int i=0;
    while (NULL!=nodes[i]) {
        if (nodes[i](blackboard))
            return true;
        ++i;
    }
    return false;
}

bool sequence(Node nodes[], Blackboard* blackboard) {
    int i=0;
    while (NULL!=nodes[i]) {
        if (!nodes[i](blackboard))
            return false;
        ++i;
    }
    return true;
}