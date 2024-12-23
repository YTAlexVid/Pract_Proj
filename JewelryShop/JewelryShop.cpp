//
// Created by YTAlexVid on 22.12.2024.
//

#include "JewelryShop.h"




void JewelryShop::readSingleJewel(std::istream& in) {
    char type;
    in>>type;
    jewelry_.push_back(JewelFactory::getEmptyJewel(type));
    in >> *jewelry_.back();
}
void JewelryShop::readMultipleJewels(std::istream& in) {
    while(!in.eof()) {
        readSingleJewel(in);
    }
}
void JewelryShop::printShop(std::ostream& out) const {
    std::copy(jewelry_.begin(), jewelry_.end(),
        std::ostream_iterator<std::shared_ptr<Jewel>>(out, "\n"));
}

const std::vector<std::shared_ptr<Jewel>> &JewelryShop::getJewelry() const {
    return this->jewelry_;
}

void JewelryShop::sortByPrice() {
    std::sort(this->jewelry_.begin(), this->jewelry_.end(),
              [](const std::shared_ptr<Jewel>& a, const std::shared_ptr<Jewel>& b){
        return a->getPrice() < b->getPrice();
    });
}
void JewelryShop::sortByWeight() {
    std::sort(this->jewelry_.begin(), this->jewelry_.end(),
              [](const std::shared_ptr<Jewel>& a, const std::shared_ptr<Jewel>& b){
                  return a->getWeight() < b->getWeight();
              });
}
