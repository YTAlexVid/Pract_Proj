//
// Created by YTAlexVid on 22.12.2024.
//

#include "Necklace.h"

double Necklace::getWeight() const {
    return this->weight_;
}
double Necklace::getCost() const {
    return this->cost_;
}
void Necklace::createByWeight(double maxWeight, JewelryShop& jewelryShop){
    if(maxWeight < 0){
        throw std::invalid_argument("Max weight can't be negative");
    }
    bool flag = true;
    this->necklace_.clear();
    this->weight_ = 0;
    this->cost_ = 0;
    while(flag && maxWeight > 0){
        std::for_each(jewelryShop.getJewelry().begin(), jewelryShop.getJewelry().end(),
                      [&flag, &maxWeight, this, &jewelryShop](const std::shared_ptr<Jewel>& ptr){
            if(ptr->getWeight() <= maxWeight){
                this->necklace_.push_back(ptr);
                this->weight_+=ptr->getWeight();
                this->cost_+=ptr->getPrice();
                maxWeight-=ptr->getWeight();
            }
            else if (maxWeight < jewelryShop.getJewelry().front()->getWeight()){
                flag = false;
            }
        });
    }
}
void Necklace::createByCost(double maxCost, JewelryShop& jewelryShop) {
    if(maxCost<0){
        throw std::invalid_argument("Max cost can't be negative");
    }
    bool flag = true;
    this->necklace_.clear();
    this->weight_ = 0;
    this->cost_ = 0;
    while(flag && maxCost>0){
        std::for_each(jewelryShop.getJewelry().begin(), jewelryShop.getJewelry().end(),
                      [&flag, &maxCost, this, &jewelryShop](const std::shared_ptr<Jewel>& ptr){
                          if(ptr->getPrice()<=maxCost){
                              this->necklace_.push_back(ptr);
                              this->weight_+=ptr->getWeight();
                              this->cost_+=ptr->getPrice();
                              maxCost-=ptr->getPrice();
                          }
                          else if (maxCost<jewelryShop.getJewelry().front()->getPrice()){
                              flag = false;
                          }
                      });
    }
}
void Necklace::sortByPrice() {
    std::sort(this->necklace_.begin(), this->necklace_.end(),
              [](const std::shared_ptr<Jewel>& a, const std::shared_ptr<Jewel>& b){
        return a->getPrice()<b->getPrice();
    });
}

Necklace Necklace::findByMinClarity(double clarity){
    Necklace ret;
    std::for_each(this->necklace_.begin(), this->necklace_.end(),
                  [clarity, &ret](std::shared_ptr<Jewel> ptr){
        if(ptr->getClarity()>=clarity){
            ret.necklace_.push_back(ptr);
            ret.cost_+=ptr->getPrice();
            ret.weight_+=ptr->getWeight();
        }
    });
    return ret;
}

Necklace Necklace::findByMaxClarity(double clarity){
    Necklace ret;
    std::for_each(this->necklace_.begin(), this->necklace_.end(),
                  [clarity, &ret](std::shared_ptr<Jewel> ptr){
                      if(ptr->getClarity()<=clarity){
                          ret.necklace_.push_back(ptr);
                          ret.cost_+=ptr->getPrice();
                          ret.weight_+=ptr->getWeight();
                      }
                  });
    return ret;
}

std::ostream& operator<<(std::ostream& out, const Necklace& necklace){
    std::copy(necklace.necklace_.begin(), necklace.necklace_.end(),
              std::ostream_iterator<std::shared_ptr<Jewel>>(out, "\n"));
}