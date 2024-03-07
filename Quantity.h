#include <iostream>

class Quantity {
public:
    Quantity() = default;

    Quantity(const Quantity &another);

    //set powers of basic quantities: 0-kilogram, 1-meter, 2-second, 3-ampere, 4-kelvin, 5-mole, 6-candela
    Quantity &SetPower(int index, int power);

    //get powers of basic quantities: 0-kilogram, 1-meter, 2-second, 3-ampere, 4-kelvin, 5-mole, 6-candela
    int GetPower(int index);

    std::string ToString() const;

    Quantity operator*=(const Quantity &another);

    Quantity operator*(const Quantity &another) const;

    Quantity operator/=(const Quantity &another);

    Quantity operator/(const Quantity &another) const;

    Quantity &operator^=(int power);

    Quantity operator^(int power) const;

    Quantity &operator=(const Quantity &another);

    bool operator==(const Quantity &another) const;

    bool operator!=(const Quantity &another) const;

    ~Quantity() = default;

private:
    static void CheckIndexException(int index);

    static constexpr int kCountOfBasicQuantities_ = 7;

    //powers of basic quantities: 0-kilogram, 1-meter, 2-second, 3-ampere, 4-kelvin, 5-mole, 6-candela
    int basic_quantities_power_[kCountOfBasicQuantities_]{0, 0, 0, 0, 0, 0, 0};

    std::string GetBasicQuantityShortName(int index) const;

    std::string GetBasicQuantityFullName(int index) const;
};