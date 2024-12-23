//
// Created by YTAlexVid on 22.12.2024.
//

#include "JewelFactory.h"

std::shared_ptr<Jewel> JewelFactory::getEmptyJewel(const char type) {
    switch(type) {
        case TYPE_DIAMOND:
            return std::make_shared<Diamond>();
        case TYPE_EMERALD:
            return std::make_shared<Emerald>();
        case TYPE_PEARL:
            return std::make_shared<Pearl>();
        default:
            throw std::invalid_argument("No jewel exists with type specified");
    }
}