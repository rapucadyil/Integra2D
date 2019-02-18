#include "entitymanager.h"
#include <string>
#include "entity.h"


EntityManager::~EntityManager() {
    
}


Entity* EntityManager::createEntity(IGstring name) {
	Entity* newEnt = new Entity(name);
	_activeEntities.push_back(*newEnt);
	return newEnt;	
    
}

void EntityManager::manageEntities() {
	for (int i = 0; i < _activeEntities.size(); i++) {
        
		if (!_activeEntities[i].getActive()) {
			_activeEntities.erase(_activeEntities.begin() + i);
		}
	}
    
}

Entity& EntityManager::getEntityByID(IGuint _id) {
	for (int id = 0; id < _activeEntities.size(); id++) {
        
		if (_activeEntities[id].getEntityID() == _id) {
			return _activeEntities[id];
		}
	}
    
}

