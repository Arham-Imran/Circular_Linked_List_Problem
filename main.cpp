#include <iostream>
#include "Linked_List.hpp"
#include "timing.hpp"

int main()
{
    Timer timer;
    ll::Linked_List<int> problem_list;
    for(int i=1; i<10; i++)
        problem_list.insert_at_end(i);
    problem_list.add_circularity(6);
    int pos;
    bool circularity;
    timer.start();
    std::tie(pos, circularity) = problem_list.check_circularity_vector();
    timer.end();
    std::cout << "Time for Vector Implementation: " << timer.get_time() << "ns" << std::endl;
    std::cout << "Is Linked list circular? (using vector method): " << circularity << std::endl;
    if(circularity)
        std::cout << "Position of circularity: " << pos << std::endl;
    
    timer.start();
    std::tie(pos, circularity) = problem_list.check_circularity_cycle();
    timer.end();
    std::cout << "Time for Floyd Implementation: " << timer.get_time() << "ns" << std::endl;
    std::cout << "Is Linked list circular? (using floyd cycle detection): " << circularity << std::endl;
    if(circularity)
        std::cout << "Position of circularity: " << pos << std::endl;
}
