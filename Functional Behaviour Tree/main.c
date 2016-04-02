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
typedef struct {
    bool logged_in;
} Blackboard;
typedef bool (*Node)(Blackboard* blackboard);

//------------------------------------------------------
// Functions
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

//------------------------------------------------------
// Unit Testing
//------------------------------------------------------

//------------------------------------------------------
// Actions
//------------------------------------------------------

bool action_logged_in_header(Blackboard* blackboard) {
    printf("<header>Welcome logged-in user</header\n");
    return true;
}

bool action_logged_out_header(Blackboard* blackboard) {
    printf("<header>Sign in?</header\n");
    return true;
}

//------------------------------------------------------
// Conditions
//------------------------------------------------------

bool is_logged_in(Blackboard* blackboard) {
    return blackboard->logged_in;
}

//------------------------------------------------------
// Sequences
//------------------------------------------------------

bool logged_in_header(Blackboard* blackboard) {
    return sequence((Node[]){
        is_logged_in,
        action_logged_in_header,
        NULL
    }, blackboard);
}

//------------------------------------------------------
// Selectors
//------------------------------------------------------

bool header(Blackboard* blackboard) {
    return selector((Node[]){
        logged_in_header,
        action_logged_out_header,
        NULL
    }, blackboard);
}

int main(int argc, const char * argv[]) {
    
    Blackboard blackboard;
    blackboard.logged_in = false;
    
    header(&blackboard);
    
//    blackboard.x = 11;
    
//    Node nodes[] = {
//        is_under_10,
//        node_test_false,
//        node_test_false,
//        NULL
//    };
    
//    printf("%d \n", sequence(nodes, &blackboard));
    
    return 0;
}
