#include "Cell.h"


Value Cell::GetValue() { return value_; }

void Cell::SetFormula(std::string new_formula) { formula_ = std::move(new_formula); }

std::string Cell::GetFormula() { return formula_; }

void Cell::UpdateValue() {
  throw std::runtime_error("Cell::UpdateValue is not implemented");
    //value_ = connection_->GetObject(formula_);
}
