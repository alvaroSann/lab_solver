#include "Value.h"

Value::Value() : data_(), quantity_() {}

Value::Value(double data, const Quantity& quantity) : data_(data), quantity_(quantity) {}

Value Value::operator+(const Value& another) const {
    Value answer = *this;
    answer += another;
    return answer;
}

Value Value::operator+=(const Value& another) {
    if (quantity_ != another.quantity_) {
        throw std::invalid_argument("Cannot add values with different dimensions");
    }
    data_ += another.data_;
    return *this;
}

Value Value::operator*(const Value& another) const {
    Value answer = *this;
    answer *= another;
    return answer;
}

Value Value::operator*=(const Value& another) {
    data_ *= another.data_;
    quantity_ *= another.quantity_;
    return *this;
}

Value Value::operator/(const Value& another) const {
    Value answer = *this;
    answer /= another;
    return answer;
}

Value Value::operator/=(const Value& another) {
    data_ /= another.data_;
    quantity_ /= another.quantity_;
    return *this;
}

Value Value::operator^=(int power) {
    data_ = pow(data_, power);
    quantity_ ^= power;
    return *this;
}

Value Value::operator^(int power) const {
    Value answer = *this;
    answer ^= power;
    return answer;
}

Value& Value::operator=(const Value& another) {
    data_ = another.data_;
    quantity_ = another.quantity_;
    return *this;
}

bool Value::operator==(const Value& another) const {
    return data_ == another.data_ && quantity_ == another.quantity_;
}

bool Value::operator!=(const Value& another) const {
    return !(*this == another);
}

void Value::SetValue(double value, const Quantity& quantity) {
    data_ = value;
    quantity_ = quantity;
}

double Value::GetValue() const {
    return data_;
}

Quantity Value::GetQuantity() const {
    return quantity_;
}

void Value::RoundingValue(const Value& inaccuracy) {
    double inaccuracy_value = inaccuracy.GetValue();
    if (inaccuracy_value < 0.0) {
        throw std::invalid_argument("Inaccurate value cannot be negative");
    }
    int precision = (inaccuracy_value != 0.0) ? static_cast<int>(-log10(inaccuracy_value)) : 3;
    data_ = round(data_ * pow(10, precision)) / pow(10, precision);
}
std::string Value::ToString() const {
  return std::to_string(data_) + " " + quantity_.ToString();
}
