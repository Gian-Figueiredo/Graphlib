#include <graphlib/digraph/DigraphMatrix.hpp>
#include <test_utils.hpp>
#include <iostream>

int main() {
    graphlib::DigraphMatrix d(5);
    d.addArc(1, 2);
    d.addArc(2, 3);
    graphlib::test::run_digraph_contract_test(d, 5, 2);
    d.clearArcs();
    d.addArc(1, 2);
    d.addArc(1, 3);
    d.addArc(2, 3);
    d.addArc(3, 4);
    d.addArc(4, 2);
    d.addArc(4, 4);
    std::cout << d.toString() << std::endl;
}