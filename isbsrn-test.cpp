#include <iostream>
#include <ctime>
#include <cstdlib>
#include "isbsrn.h"

int main () {
    parse_node *current = new parse_node((parse_node *)0);
    
    srand(time(0));
    
    std::vector<bool> bracks = {1, 0};
    
    int size = 0;
    int times = 0;
    
    std::cout << "Max size of brackets (2^(n + 1)): ";
    std::cin >> size;

    std::cout << "Sample size: ";
    std::cin >> times;
    
    for (int i = 0; i < size; i ++ ) {
        int insert = rand() % bracks.size();
        std::vector <bool> bracks_copy = bracks;
        bracks.insert(bracks.begin() + insert, bracks_copy.begin(), bracks_copy.end());
        
        float total_time = 0;
        
        for (int j = 0; j < times; j ++) {
            auto start = clock();
            parse_node *current = new parse_node((parse_node *)0);
            for (bool b : bracks) {
                if (b) current = current->open_node();
                else current = current->close_node();
            }
            auto end = clock();
            
            total_time += (float)(end - start);
        }
        
        std::cout << (total_time / times) << " for " << bracks.size() << " bracks" << std::endl;
    }
    
        
}
