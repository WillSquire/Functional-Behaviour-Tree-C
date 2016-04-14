//
//  libfunctionalbehaviourtree.h
//  functionalbehaviourtree
//
//  Created by Will Squire on 14/04/2016.
//  Copyright © 2016 Will Squire. All rights reserved.
//

#ifndef libfunctionalbehaviourtree_h
#define libfunctionalbehaviourtree_h

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

#endif /* libfunctionalbehaviourtree_h */
