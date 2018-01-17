# ISBSRN - *I* *S*hould *B*e *S*tudying *R*ight *N*ow

But I needed to write something to parse a file of brackets for syntax highlighting.

There are probably millions of implementations of this, millions of which are better than mine. So be it, because C++ can be fun to write in.

`open_node` indicates an opening bracket. It adds a child to the current bracket and recursively starts again.
`closed_node` indicates a closing bracket. It marks the current node as closed, and returns to the parent.

Both return a pointer to a `parse_node` which indicates the current state of the parsing tree.
