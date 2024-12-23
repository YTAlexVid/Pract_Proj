//
// Created by YTAlexVid on 22.12.2024.
//

#include "Emerald.h"

Emerald::Emerald(const std::string &name, const double price, const double weight,
                 const double clarity, std::string origin, const bool isOiled)
    : Jewel(name, price, weight, clarity),
      origin_(std::move(origin)), isOiled_(isOiled) {
    if(origin_.empty()) {
        throw std::invalid_argument("Origin can't be empty");
    }
}

Emerald::Emerald() : isOiled_(false) {}


std::string Emerald::getType() const {
    return "Emerald";
}

void Emerald::print(std::ostream& out) const {
    this->Jewel::print(out);
    out<<" | Origin: "<<this->origin_<<" | Oiled: "<<std::boolalpha<<this->isOiled_;
}

void Emerald::read(std::istream& in) {
    this->Jewel::read(in);
    in>>this->origin_>>isOiled_;
    if(origin_.empty()) {
        throw std::invalid_argument("Origin can't be empty");
    }
}


