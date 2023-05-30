#pragma once
#include <vector>
#include <functional>
#include <queue>

double f1 (double x);
double f2 (double x);
double f3 (double x);
double f4 (double x);

class GTree {
    public:
        GTree();
        GTree(const std::function<double (double)>&);
        GTree* get_child(int) const;
        void set_value(const std::function<double (double)>&);
        void insert_child(const std::function<double (double)>&);
        double get_result(double) const;
        void traverse (double);
        double bfs_recursive(std::queue<GTree*>&, double);
    private:
        std::function<double (double)> value;
        std::vector<GTree*> children;
};