#ifndef VALUE_H
#define VALUE_H

#include "Quantity.h"

#include <iostream>
#include <cmath>
#include <stdexcept>

class Value {
public:
    // Constructors and destructor
    Value();

    Value(double data, const Quantity& quantity);

    Value(const Value& another) = default;

    ~Value() = default;

    // Operators
    Value operator+(const Value& another) const;

    Value operator+=(const Value& another);

    Value operator*(const Value& another) const;

    Value operator*=(const Value& another);

    Value operator/(const Value& another) const;

    Value operator/=(const Value& another);

    Value operator^=(int power);

    Value operator^(int power) const;

    Value& operator=(const Value& another);

    bool operator==(const Value& another) const;

    bool operator!=(const Value& another) const;

    // Methods
    void SetValue(double value, const Quantity& quantity);

    double GetValue() const;

    Quantity GetQuantity() const;

    void RoundingValue(const Value& inaccuracy);

    std::string ToString() const;

private:
    double data_;
    Quantity quantity_;
};

#endif
