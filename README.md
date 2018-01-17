# ISBSRN - *I* *S*hould *B*e *S*tudying *R*ight *N*ow

But I needed to write something to parse a file of brackets for syntax highlighting.

There are probably millions of implementations of this, millions of which are better than mine. So be it, because C++ can be fun to write in.

## Usage

`open_node` indicates an opening bracket. It adds a child to the current bracket and recursively starts again.

`closed_node` indicates a closing bracket. It marks the current node as closed, and returns to the parent.

Both return a pointer to a `parse_node` which indicates the current state of the parsing tree.

Code to parse a list of booleans giving open or close (uncomment the lines to see how the algorithm performs on your computer)

```cpp
int main () {
    parse_node *current = new parse_node((parse_node *)0);
    
    std::vector<bool> bracks = {1, 0, 1, 0};
    
    //auto start = clock();
    for (bool b : bracks) {
        if (b) current = current->open_node();
        else current = current->close_node();
    }
    
    //auto end = clock();
    
    //std::cout << (end - start) << " microseconds";
}
```

## Speed

This algorithm is `O(n)`. 

Bracket count | Speed (μs) 
--- | ---
2 | 1.514
4 | 2.17
8 | 3.611
16 | 6.45
32 | 12.295
64 | 24.396
128 | 48.1715
256 | 94.8365
512 | 188.266
1024 | 375.211
2048 | 749.769
4096 | 1497.3
8192 | 2992.72
16384 | 5970.11

10<sup>3</sup>μs = 1ms, 10<sup>6</sup>μs = 1s

## Example

Parsing `((())()(()`
![tree image](tree.png)

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


