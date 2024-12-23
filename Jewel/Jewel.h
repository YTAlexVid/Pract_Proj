//
// Created by YTAlexVid on 10.12.2024.
//

#ifndef JEWEL_H
#define JEWEL_H

#include<string>
#include<memory>
#include<iostream>

class Jewel {
public:
    virtual ~Jewel() = default;

    virtual std::string getType() const = 0;
    std::string getName() const;
    double getPrice() const;
    double getWeight() const;
    double getClarity() const;

    void setName(const std::string &);
    void setPrice(double);
    void setWeight(double);
    void setClarity(double);

    virtual void print(std::ostream&) const;
    virtual void read(std::istream&);

    friend std::ostream& operator<<(std::ostream&, const Jewel&);
    friend std::ostream& operator<<(std::ostream&, const std::shared_ptr<Jewel>&);
    friend std::istream& operator>>(std::istream&, Jewel&);
    friend std::istream& operator>>(std::istream&, const std::shared_ptr<Jewel>&);

protected:
    explicit Jewel(std::string, double, double, double);
    Jewel();

    std::string name_;
    double weight_;
    double clarity_;
    double price_;
};

#endif //JEWEL_H
