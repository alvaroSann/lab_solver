#include "Quantity.h"


Quantity::Quantity(const Quantity &another) {
    for (int i = 0; i < kCountOfBasicQuantities_; ++i) {
        basic_quantities_power_[i] = another.basic_quantities_power_[i];
    }
}

Quantity &Quantity::SetPower(int index, int power) {
    CheckIndexException(index);
    basic_quantities_power_[index] = power;
    return *this;
}

Quantity Quantity::operator*=(const Quantity &another) {
    for (int i = 0; i < kCountOfBasicQuantities_; ++i) {
        basic_quantities_power_[i] += another.basic_quantities_power_[i];
    }
    return *this;
}

Quantity Quantity::operator*(const Quantity &another) const {
    Quantity answer = *this;
    answer *= another;
    return answer;
}

Quantity Quantity::operator/=(const Quantity &another) {
    for (int i = 0; i < kCountOfBasicQuantities_; ++i) {
        basic_quantities_power_[i] -= another.basic_quantities_power_[i];
    }
    return *this;
}

Quantity Quantity::operator/(const Quantity &another) const {
    Quantity answer = *this;
    answer /= another;
    return answer;
}

Quantity &Quantity::operator^=(int power) {
    for (int &i: basic_quantities_power_) {
        i *= power;
    }
    return *this;
}

Quantity Quantity::operator^(int power) const {
    Quantity answer = *this;
    answer ^= power;
    return answer;
}

Quantity &Quantity::operator=(const Quantity &another) {
    for (int i = 0; i < kCountOfBasicQuantities_; ++i) {
        basic_quantities_power_[i] = another.basic_quantities_power_[i];
    }
    return *this;
}

bool Quantity::operator==(const Quantity &another) const {
    for (int i = 0; i < kCountOfBasicQuantities_; ++i) {
        if (basic_quantities_power_[i] != another.basic_quantities_power_[i])
            return false;
    }
    return true;
}

bool Quantity::operator!=(const Quantity &another) const {
    return !(*this == another);
}

/**
 * Get the power of a quantity at the specified index.
 *
 * @param index the index of the quantity
 *
 * @return the power of the quantity at the specified index
 *
 * @throws CheckIndexException if the index is out of bounds
 */
int Quantity::GetPower(int index) {
    CheckIndexException(index);
    return basic_quantities_power_[index];
}

/**
 * @brief Check if the index is within the valid range.
 *
 * @param index - The index to be checked.
 * @throw std::range_error if the index is out of range.
 */
void Quantity::CheckIndexException(int index) {
    if (index < 0 || index >= kCountOfBasicQuantities_) {
        throw std::range_error("Index must be between 0 and " + std::to_string(kCountOfBasicQuantities_ - 1));
    }
}
std::string Quantity::ToString() const {
  std::string positive_answer;
  std::string negative_answer;
  for (int i = 0; i < kCountOfBasicQuantities_; ++i) {
    if (basic_quantities_power_[i] > 0) {
      if (!positive_answer.empty()) {
        positive_answer += " * ";
      }
      positive_answer += GetBasicQuantityFullName(i) + "^" + std::to_string(basic_quantities_power_[i]);
    }
    if (basic_quantities_power_[i] < 0) {
      if (!negative_answer.empty()) {
        negative_answer += " * ";
      }
      negative_answer += GetBasicQuantityFullName(i) + "^" + std::to_string(basic_quantities_power_[i]);
    }
  }
  if (positive_answer.empty() && negative_answer.empty()) {
    return "units";
  }
  if (positive_answer.empty()) {
    positive_answer = "1";
  }
  if (negative_answer.empty()) {
    return positive_answer;
  }
  return positive_answer + " / (" + negative_answer + ")";
}

std::string Quantity::GetBasicQuantityFullName(int index) const {
  switch (index) {
    case 0: return "kilogram";
    case 1: return "meter";
    case 2: return "second";
    case 3: return "ampere";
    case 4: return "kelvin";
    case 5: return "mole";
    case 6: return "candela";
    default: return "Error in GetBasicQuantityFullName(): index is out of range.";
  }
}
std::string Quantity::GetBasicQuantityShortName(int index) const {
  switch (index) {
    case 0: return "kg";
    case 1: return "m";
    case 2: return "s";
    case 3: return "A";
    case 4: return "K";
    case 5: return "mol";
    case 6: return "cd";
    default: return "Error in GetBasicQuantityShortName(): index is out of range.";
  }
}
