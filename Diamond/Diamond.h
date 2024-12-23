//
// Created by YTAlexVid on 17.12.2024.
//

#ifndef DIAMOND_H
#define DIAMOND_H

#include "../Headers.h"
class Diamond final : public Jewel {
public:
    explicit Diamond(const std::string &, double, double, double, std::string, bool);

    Diamond();

    std::string getType() const override;

    void print(std::ostream&) const override;

    void read(std::istream&) override;

private:
    bool isLabGrown_;
    std::string certificationType_;
};

#endif //DIAMOND_H
