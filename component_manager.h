#pragma once
#include "definition.h"
#include <map>
#ifndef _COMPONENT_MANAGER_H_
#define _COMPONENT_MANAGER_H_

typedef struct HealthComponent {
	float curr;
	float max;
} HealthComponent;

template <class T>
class Component {

	Component();
	~Component();
};

class Component<HealthComponent>() {

	Component() {

	}

};

/* ================= COMP MANAGER =============================================== */
class ComponentManager {
private:
	
	map<IGboolean, Component*> _components;
	
	Component _availableComponents[10] = {
		HealthComponent();

	};

public:
	ComponentManager();
	~ComponentManager();
	
	void registerEntity(Entity& ent, IGuint compID);
	
	void deregisterEntity(IGuint compID);

	inline Component[10] getAvailableComponents() { return _availableComponents; }

	inline map<IGboolean, Component*> getComponents() { return _components; }
};

#endif

