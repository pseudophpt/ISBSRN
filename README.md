# ISBSRN - *I* *S*hould *B*e *S*tudying *R*ight *N*ow

But I needed to write something to parse a file of brackets for syntax highlighting.

There are probably millions of implementations of this, millions of which are better than mine. So be it, because C++ can be fun to write in.

#### Usage

`open_node` indicates an opening bracket. It adds a child to the current bracket and recursively starts again.

`closed_node` indicates a closing bracket. It marks the current node as closed, and returns to the parent.

Both return a pointer to a `parse_node` which indicates the current state of the parsing tree.


Code to parse a list of booleans giving open or close

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

#### Speed

This algorithm is `O(n)`. 

Bracket count | Speed (μs)
--- | ---
4  | 4.98 
8 | 7.866
16 | 12.527
32 | 20.047
64 | 32.193
128 | 50.675
256 | 76.345
512 | 112.582
1024 | 207.7
2048 | 421.905
4096 | 850.918
8192 | 1685.11
16384 | 3424.79
32768 | 6792.68

1000 μs = 1 ms, 1000000 μs = 1s

Speed may differ on your computer, run `make test` (if you want to compile yourself, optional) and `./isbsrn` to find how it runs on yours.

#### Example

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


