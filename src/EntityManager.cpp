#include "EntityManager.hpp"
#include <algorithm>

void EntityManager::removeDeadEntities(EntityVec& vec) {
    auto end = std::remove_if(vec.begin(), vec.end(), [](const std::shared_ptr<Entity>& e) {
        return !e->isActive();
    });
    vec.erase(end, vec.end());
}

void EntityManager::update() {
     for (const auto& entity : m_entitiesToAdd) {
        m_entities.push_back(entity);
        m_entityMap[entity->tag()].push_back(entity);

        for (auto& [tag, entityVec] : m_entityMap) {
            if (tag == entity->tag()) {
                entityVec.push_back(entity);
            }
        }
    }
    m_entitiesToAdd.clear();

    removeDeadEntities(m_entities);

    for (auto& [tag, entityVec] : m_entityMap) {
        removeDeadEntities(entityVec);
    }
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag) {
    auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
    m_entitiesToAdd.push_back(entity);
    return entity;
}

const EntityVec& EntityManager::getEntities() {
    return m_entities;
}

const EntityVec& EntityManager::getEntities(const std::string& tag) {
    return m_entityMap[tag];
}
