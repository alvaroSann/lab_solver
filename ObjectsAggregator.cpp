//
// Created by rasskazkin on 3/6/24.
//

#include "ObjectsAggregator.h"

void ObjectsAggregator::AddObject(Object *object) {
  if (GetObject(object->GetName()) != nullptr) {
    throw std::runtime_error("Object with name " + object->GetName() + " already exists!\nName should be unique.");
  }
    objects_[object->GetName()] = object;
}

Object *ObjectsAggregator::GetObject(const std::string &name) {
  auto it = objects_.find(name);
  if (it == objects_.end()) {
    return nullptr;
  }
  return it->second;
}
std::string ObjectsAggregator::GetInfo(const std::string &name) {
  auto it = objects_.find(name);
  if (it == objects_.end()) {
    throw std::runtime_error("Object with name " + name + " does not exist!");
  }
  return it->second->GetInfo();
}
