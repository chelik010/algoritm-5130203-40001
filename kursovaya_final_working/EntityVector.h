#ifndef ENTITYVECTOR_H
#define ENTITYVECTOR_H

#include <vector>

template <typename T>
class EntityVector {
    std::vector<T*> items;
public:
    void add(T* item) { items.push_back(item); }
    std::vector<T*>& getAllEntities() { return items; }
};

#endif
