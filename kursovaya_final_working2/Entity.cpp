#include "Entity.h"

Entity::Entity(const std::string& id) : id(id) {}
std::string Entity::getId() const { return id; }
