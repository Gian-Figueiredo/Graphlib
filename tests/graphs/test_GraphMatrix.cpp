#include <graphlib/GraphMatrix.hpp>
#include <test_utils.hpp>

int main() {
    graphlib::GraphMatrix g(5);
    graphlib::test::run_contract_tests(g);
}