#include "Headers.h"

int main() {
    JewelryShop js;
    std::ifstream fin("input.txt");
    js.readMultipleJewels(fin);
    js.sortByPrice();
    js.printShop(std::cout);
    return 0;
}
