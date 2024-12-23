//
// Created by YTAlexVid on 17.12.2024.
//

#ifndef PEARL_H
#define PEARL_H

#include "../Headers.h"

class Pearl final : public Jewel {
public:
    explicit Pearl(const std::string &, double, double, double, std::string, std::string);

    Pearl() = default;

    std::string getType() const override;

    void print(std::ostream&) const override;

    void read(std::istream&) override;

private:
    std::string shape_;
    std::string type_;
};


#endif //PEARL_H
