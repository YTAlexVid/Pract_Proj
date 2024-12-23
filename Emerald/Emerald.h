//
// Created by YTAlexVid on 17.12.2024.
//

#ifndef EMERALD_H
#define EMERALD_H

#include "../Headers.h"

class Emerald final : public Jewel {
public:
    explicit Emerald(const std::string &, double, double,
                     double, std::string, bool);

    Emerald();

    std::string getType() const override;

    void print(std::ostream&) const override;

    void read(std::istream&) override;

private:
    std::string origin_;
    bool isOiled_;
};


#endif //EMERALD_H
