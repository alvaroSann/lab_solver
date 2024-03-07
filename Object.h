#ifndef PRIMITIVE_OBJECT
#define PRIMITIVE_OBJECT

#include "Value.h"
#include <functional>
#include <utility>

class Object;

struct ConnectionWithAggregator {
 public:
  ConnectionWithAggregator(std::function<Object*(const std::string&)> GetterObject) : GetterObject_(std::move(GetterObject)) {}

  Object* GetObject(const std::string& name) {
    return GetterObject_(name);
  }
 private:
  std::function<Object*(const std::string&)> GetterObject_;
};

class Object {
 public:
  explicit Object(ConnectionWithAggregator* connection) : connection_(connection) {}
  Object(const std::string& name, ConnectionWithAggregator* connection) : connection_(connection), name_(name) {}

  virtual std::string GetInfo() = 0;

  virtual Object* GetInsideObject(const std::string &name) {
    if (name.empty()) return this;
    return nullptr;
  }

  std::string GetName() { return name_; }

  void SetName(std::string name) { name_ = std::move(name); }

  bool IsNamed() {
    return !name_.empty();
  }

 protected:
  Object* GetParentObject(const std::string& formula) {
    return connection_->GetObject(formula);
  }

 private:
  ConnectionWithAggregator* connection_;

  std::string name_;
};



#endif
