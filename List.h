#include <deque>
#include <utility>
#include "Cell.h"
#include "Value.h"

class List : public Object {
 private:
  std::deque<Cell*> cells_;
 public:
  // constructor
  List(const std::string& name, ConnectionWithAggregator* connection) : Object(name, connection) {};

  std::string GetInfo() override;

  // get cell by index
  Cell &GetCell(int index);

  // get Value by index
  Value GetValue(int index);

  // get size
  int GetSize() const;

  // add cell
  void AddCell(Cell *cell);

  // remove cell
  void RemoveCell(int index);

  // insert cell
  void InsertCell(int index, Cell *cell);

  // clear
  void Clear();
};


