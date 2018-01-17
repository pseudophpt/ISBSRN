#ifndef ISBSRN_H
#define ISBSRN_H

#include <vector>

class parse_node {
    private:
        parse_node *parent;
        std::vector<parse_node *> children;
        bool closed;
    public:
        parse_node (parse_node *parent);
        parse_node *open_node (void);
        parse_node *close_node (void);
        bool get_closed(void);
        std::vector<parse_node *> get_children (void);
};

#endif
