//
// Created by YTAlexVid on 22.12.2024.
//

#ifndef JEWELRYSHOP_H
#define JEWELRYSHOP_H

#include "../Headers.h"

class JewelryShop {
public:
    void readSingleJewel(std::istream&);
    void readMultipleJewels(std::istream&);
    void printShop(std::ostream&) const;
    const std::vector<std::shared_ptr<Jewel>>& getJewelry() const;
    void sortByPrice();
    void sortByWeight();

private:
    std::vector<std::shared_ptr<Jewel>> jewelry_;
};



#endif //JEWELRYSHOP_H
