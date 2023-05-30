#include "gtree.h"
#include <iostream>

int main(){
    GTree g(f1);
    g.insert_child(f2);
    g.insert_child(f3);
    GTree* my_child = g.get_child(2);
    my_child->insert_child(f4);
    //std::cout << g.get_result(5.5) << std::endl;
    //std::cout << my_child->get_result(5.5) << std::endl;
    g.traverse(5);
    return 0;
}