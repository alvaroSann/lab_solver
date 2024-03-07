#include <Cell.h>
#include <List.h>
#include <functional>
#include <map>

class ObjectsAggregator {
public:
  Object* GetObject(const std::string& name);

  void AddObject(Object* object);

  void AddCell(const std::string& name) {
    AddObject(new Cell(name, connection_));
  }

  std::string GetInfo(const std::string& name);

 private:
  std::map<std::string, Object*> objects_;

  std::function<Object*(const std::string&)> getterObject_ = [this](const std::string& name) {
    return GetObject(name);
  };

  ConnectionWithAggregator* connection_ = new ConnectionWithAggregator(getterObject_);

  std::function<Value(std::string)> getterValue_ = [this](const std::string& formula) {
    if (formula.empty()) {
      return Value();
    }
    int answer = 0;
    for (char i : formula) {
      answer = answer * 10 + i - '0';
    }
    return Value(answer, Quantity());
  };
};
