#include "List.h"

void List::AddCell(Cell *cell) {
  cells_.push_back(cell);
}

void List::RemoveCell(int index) {
  cells_.erase(cells_.begin() + index);
}

void List::InsertCell(int index, Cell *cell) {
  cells_.insert(cells_.begin() + index, cell);
}

void List::Clear() {
  cells_.clear();
}

Cell &List::GetCell(int index) {
  return *cells_[index];
}

int List::GetSize() const {
  return cells_.size();
}

Value List::GetValue(int index) {
  return cells_[index]->GetValue();
}

std::string List::GetInfo() {
  std::string answer = "Objet: List  |  Name: " + GetName() + "\nData:\n";
  for (int i = 0; i < cells_.size(); i++) {
    answer += std::to_string(i) + ":\n" + cells_[i]->GetInfo() + "\n";
  }
  return answer;
}


