//
//  functional_behaviour_tree.h
//  Functional Behaviour Tree
//
//  Created by Will Squire on 08/04/2016.
//  Copyright © 2016 Will Squire. All rights reserved.
//

#ifndef functional_behaviour_tree_h
#define functional_behaviour_tree_h

#include <stdio.h>

//------------------------------------------------------
// Typedefs
//------------------------------------------------------

typedef enum {false, true} bool;
typedef struct {
    bool logged_in;
    //    char* response;
} Blackboard;
typedef bool (*Node)(Blackboard* blackboard);

//------------------------------------------------------
// Functions (Interface)
//------------------------------------------------------

bool selector(Node nodes[], Blackboard* blackboard);
bool sequence(Node nodes[], Blackboard* blackboard);

#endif /* functional_behaviour_tree_h */
