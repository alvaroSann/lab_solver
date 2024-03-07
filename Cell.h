#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H

#include <utility>
#include "Object.h"

//Class Cell, which contains one value. This value is set by the formula.
class Cell : virtual public Object {
public:
    explicit Cell(ConnectionWithAggregator* connection) : Object(connection) {}

    Cell(const std::string& name, ConnectionWithAggregator* connection) : Object(name, connection) {}

    // returns last calculated value
    Value GetValue();

    // sets new formula
    void SetFormula(std::string new_formula);

    std::string GetFormula();
    
    void UpdateValue();

    std::string GetInfo() override {
      return (IsNamed() ? ("Name: " + GetName() + ",\n") : "") +
             "Formula: " + formula_ + ",\n" +
             "Value:   " + value_.ToString();
    }

private:
    Value value_;
    std::string formula_;
};


#endif
