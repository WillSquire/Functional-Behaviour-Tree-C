//
//  functional_behaviour_tree.h
//  Functional Behaviour Tree
//
//  Created by Will Squire on 08/04/2016.
//  Copyright © 2016 Will Squire. All rights reserved.
//

#ifndef LIBFUNCTIONALBEHAVIOURTREE_FUNCTIONAL_BEHAVIOUR_TREE_H
#define LIBFUNCTIONALBEHAVIOURTREE_FUNCTIONAL_BEHAVIOUR_TREE_H

#include <stdio.h>

//------------------------------------------------------
// Typedefs
//------------------------------------------------------

typedef enum {false, true} bool;
typedef struct Blackboard Blackboard;
typedef bool (*Node)(Blackboard* blackboard);

//------------------------------------------------------
// Functions (Interface)
//------------------------------------------------------

bool selector(Node nodes[], Blackboard* blackboard);
bool sequence(Node nodes[], Blackboard* blackboard);

#endif //LIBFUNCTIONALBEHAVIOURTREE_FUNCTIONAL_BEHAVIOUR_TREE_H
