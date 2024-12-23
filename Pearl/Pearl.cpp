//
// Created by YTAlexVid on 22.12.2024.
//

#include "Pearl.h"

Pearl::Pearl(const std::string &name, const double price, const double weight,
             const double clarity, std::string shape, std::string type): Jewel(name, price, weight, clarity),
                                                                         shape_(std::move(shape)),
                                                                         type_(std::move(type)) {
}

std::string Pearl::getType() const {
    return "Pearl";
}

void Pearl::print(std::ostream& out) const {
    this->Jewel::print(out);
    out<<" | Shape: "<<this->shape_<<" | Type: "<<this->type_;
}

void Pearl::read(std::istream& in) {
    this->Jewel::read(in);
    in>>shape_>>type_;
}