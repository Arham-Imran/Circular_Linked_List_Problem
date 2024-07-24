#include <iostream>
#include "Linked_List.hpp" 

int main()
{
    ll::Linked_List<int> problem_list;
    for(int i=1; i<10; i++)
        problem_list.insert_at_end(i);
    problem_list.add_circularity(4);
    int pos;
    bool circularity;
    std::tie(pos, circularity) = problem_list.check_circularity_vector();
    std::cout << "Is Linked list circular? " << circularity << std::endl;
    if(circularity)
        std::cout << "Position of circularity: " << pos << std::endl;
}
