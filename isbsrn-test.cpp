#include <iostream>
#include <ctime>
#include <cstdlib>
#include "isbsrn.h"

int main () {
    parse_node *current = new parse_node((parse_node *)0);
    
    srand(time(0));
    
    
    int size = 0;
    int times = 0;
    
    std::cout << "Max size of brackets (2^(n + 1)): ";
    std::cin >> size;

    std::cout << "Sample size: ";
    std::cin >> times;

    std::vector<float> speed_amounts (size, 0);
    
    /* For each sample */
    for (int j = 0; j < times; j ++) {
        /* Initial */
        std::vector<bool> bracks = {1, 0};
        for (int i = 0; i < size; i ++ ) {
            /* Place to insert */
            int insert = rand() % bracks.size();
            std::vector <bool> bracks_copy = bracks;
            /* Actually insert */
            bracks.insert(bracks.begin() + insert, bracks_copy.begin(), bracks_copy.end());
            
            auto start = clock();
            
            parse_node *current = new parse_node((parse_node *)0);
            for (bool b : bracks) {
                if (b) current = current->open_node();
                else current = current->close_node();
            }
            
            auto end = clock();
            
            speed_amounts[i] += (float)(end - start);
        }
    }   
    for (int sample = 0; sample < size; sample ++) {
        std::cout << "n: " << (2 << sample) << " t: " << speed_amounts[sample] / times << std::endl;
    }
}
