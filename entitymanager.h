#include <vector>
#include "definitions.h"
#pragma once
#ifndef _ENTITY_MANAGER_H_
#define _ENTITY_MANAGER_H_
class Entity;
class EntityManager {
    private:
	std::vector<Entity> _activeEntities;
    
    public:
	~EntityManager();
	
	inline std::vector<Entity> getActiveEntities() { return _activeEntities; }
	
	Entity* createEntity(IGstring name);	
	
	void manageEntities();
    
	Entity& getEntityByID(IGuint id);
};

#endif
