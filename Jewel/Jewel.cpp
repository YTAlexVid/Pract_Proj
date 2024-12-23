//
// Created by YTAlexVid on 22.12.2024.
//

#include "Jewel.h"

Jewel::Jewel(std::string name, const double price, const double weight, const double clarity)
    : name_(std::move(name)), weight_(weight), clarity_(clarity), price_(price) {
    if(price<0) {
        throw std::invalid_argument("Price must be greater or equal than zero");
    }
}

Jewel::Jewel() : weight_(0), clarity_(0), price_(0) {}

std::string Jewel::getName() const { return this->name_; }

double Jewel::getPrice() const { return this->price_; }

double Jewel::getWeight() const { return this->weight_; }

double Jewel::getClarity() const { return this->clarity_; }

void Jewel::setName(const std::string &name) { this->name_ = name; }

void Jewel::setPrice(const double price) {
    if(price<0) {
        throw std::invalid_argument("Price must be greater or equal than zero");
    }
    this->price_ = price;
}

void Jewel::setWeight(const double weight) { this->weight_ = weight; }

void Jewel::setClarity(const double clarity) { this->clarity_ = clarity; }

void Jewel::print(std::ostream &out) const {
    out << this->name_ << " (" << this->getType() << ") - Weight: " << this->weight_ << " | Clarity: " <<
            this->clarity_ << " | Price: " << this->price_;
}

void Jewel::read(std::istream &in) {
    in>>this->name_>>this->weight_>>this->clarity_>>this->price_;
    if(this->price_<0) {
        throw std::invalid_argument("Price must be greater or equal than zero");
    }
}

std::ostream& operator<<(std::ostream& out, const Jewel& jewel) {
    jewel.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, Jewel& jewel) {
    jewel.read(in);
    return in;
}
std::ostream& operator<<(std::ostream& out, const std::shared_ptr<Jewel>& ptr) {
    ptr->print(out);
    return out;
}

std::istream& operator>>(std::istream& in, const std::shared_ptr<Jewel>& ptr) {
    ptr->read(in);
    return in;
}