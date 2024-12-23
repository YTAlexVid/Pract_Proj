//
// Created by YTAlexVid on 22.12.2024.
//

#include "Diamond.h"

Diamond::Diamond(const std::string &name, const double price, const double weight,
                 const double clarity, std::string certificationType, const bool isLabGrown)
    : Jewel(name, price, weight, clarity),
      isLabGrown_(isLabGrown), certificationType_(std::move(certificationType)) {
    if (certificationType_.empty()) {
        throw std::invalid_argument("Certification type can't be empty");
    }
}

Diamond::Diamond(): isLabGrown_(false) {}


std::string Diamond::getType() const {
    return "Diamond";
}

void Diamond::print(std::ostream& out) const {
    this->Jewel::print(out);
    out<<" | Lab Grown: "<<std::boolalpha<<isLabGrown_<<" | Certification Type: "<<certificationType_;
}

void Diamond::read(std::istream& in) {
    this->Jewel::read(in);
    in>>isLabGrown_>>certificationType_;
    if (certificationType_.empty()) {
        throw std::invalid_argument("Certification type can't be empty");
    }
}

