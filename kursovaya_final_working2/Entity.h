#pragma once
#include <string>

class Entity {
protected:
    std::string id;
public:
    Entity(const std::string& id);
    virtual std::string getId() const;
    virtual ~Entity() {}
};
