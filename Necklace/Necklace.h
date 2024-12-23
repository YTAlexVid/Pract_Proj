//
// Created by YTAlexVid on 22.12.2024.
//

#ifndef NECKLACE_H
#define NECKLACE_H

#include "../Headers.h"

class Necklace {
public:
    double getCost() const;
    double getWeight() const;
    void createByWeight(double, JewelryShop&);
    void createByCost(double, JewelryShop&);
    void sortByPrice();
    Necklace findByMinClarity(double);
    Necklace findByMaxClarity(double);
    friend std::ostream& operator<<(std::ostream&, const Necklace&);

private:
    double cost_;
    double weight_;
    std::vector<std::shared_ptr<Jewel>> necklace_;
};


#endif //NECKLACE_H
