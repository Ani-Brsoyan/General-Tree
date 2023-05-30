#include "gtree.h"
#include <iostream>

double f1 (double x) { return x * x; }
double f2 (double x) { return x / 10; }
double f3 (double x) { return 1 - x;}
double f4 (double x) { return x; }

GTree::GTree() : value(f4) {}

GTree::GTree(const std::function<double (double)>& val) : value(val) {}

GTree* GTree::get_child(int i) const {
   if(i > 0 && i <= children.size()){
        return children[i - 1];
   }
   std::cout << "Invalid index\n" << "nullptr returned\n";
   return nullptr;
}

void GTree::set_value(const std::function<double (double)>& val) {
    value = val;
}

 void GTree::insert_child(const std::function<double (double)>& val) {
    this->children.push_back(new GTree(val));
 }

 double GTree::get_result(double x) const {
    return value(x);
 }

 void GTree::traverse (double arg) {
    //at least one element exists in gtree by default
    std::queue<GTree*> my_queue;
    my_queue.push(this);
    double res = bfs_recursive(my_queue, arg);
    std::cout << res << std::endl;
 }

 double GTree::bfs_recursive(std::queue<GTree*>& my_queue, double arg) {
    if(my_queue.empty()){
        return arg; 
    }
    GTree* current = my_queue.front();
    my_queue.pop();
    double res = current->get_result(arg);
    for(GTree* child : current->children) {
        my_queue.push(child);
    }
    return bfs_recursive(my_queue, res);
 }
