#include "isbsrn.h"

parse_node::~parse_node () {
    /* Delete all its children */
    for (parse_node *child : children) 
        delete child;
}

bool parse_node::get_closed (void) {
    return closed;
}

std::vector<parse_node *> parse_node::get_children (void) {
    return children;
}

parse_node::parse_node (parse_node *parent) {
    this->parent = parent;
}

parse_node *parse_node::open_node (void) {
    /* Make new node whose parent is the current instance */
    parse_node *new_child = new parse_node (this);
    
    /* Add new child */
    children.push_back(new_child);
    
    /* Enter new child */
    return new_child;
}

parse_node *parse_node::close_node (void) {
    /* Set closed */
    closed = true;
    
    /* Enter parent now */
    return parent;
}
