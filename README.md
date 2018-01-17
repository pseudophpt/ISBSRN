# ISBSRN - I Should Be Studying Right Now

But I needed to write something to parse a file of brackets for syntax highlighting.

There are probably millions of implementations of this, millions of which are better than mine. So be it, because C++ can be fun to write in.

## Usage

`open_node` indicates an opening bracket. It adds a child to the current bracket and recursively starts again.

`closed_node` indicates a closing bracket. It marks the current node as closed, and returns to the parent.

Both return a pointer to a `parse_node` which indicates the current state of the parsing tree.

Code to parse a list of booleans giving open or close:

```cpp
int main () {
    parse_node *current = new parse_node((parse_node *)0);
    
    std::vector<bool> bracks = {1, 0, 1, 0};
    
    for (bool b : bracks) {
        if (b) current = current->open_node();
        else current = current->close_node();
    }
}
```

## Speed

This algorithm is `O(n)` for both parsing and deletion. 

Bracket count | Parse speed (μs) | Delete speed (μs)
--- | --- | ---
4 | 1.609 | 0.699
8 | 1.999 | 0.843
16 | 3.473 | 1.265
32 | 6.085 | 1.99
64 | 11.734 | 3.469
128 | 22.007 | 6.35
256 | 42.594 | 12.221
512 | 86.098 | 24.334
1024 | 167.722 | 48.455
2048 | 336.097 | 100.87
4096 | 670.882 | 199.087
8192 | 1342.11 | 389.083
16384 | 2774.77 | 755.241
32768 | 5545.65 | 1531.56


10<sup>3</sup>μs = 1ms, 10<sup>6</sup>μs = 1s


![plot image](https://github.com/pseudophpt/ISBSRN/raw/master/plot.png)
## Example

Parsing `((())()(()`

![tree image](https://github.com/pseudophpt/ISBSRN/raw/master/tree.png)

By hand, we can also get the answer of 

```
(
    (
        (
        )
    )
    (
    )
    (
    	(
        )


