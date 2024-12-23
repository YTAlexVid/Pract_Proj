//
// Created by YTAlexVid on 22.12.2024.
//

#ifndef JEWELFACTORY_H
#define JEWELFACTORY_H

#include "../headers.h"

class JewelFactory {
public:

    static std::shared_ptr<Jewel> getEmptyJewel(char);
    JewelFactory() = delete;

private:
    enum JewelType{TYPE_EMERALD='e', TYPE_DIAMOND='d', TYPE_PEARL='p'};
};



#endif //JEWELFACTORY_H
