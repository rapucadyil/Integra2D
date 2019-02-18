#pragma once
#include "definitions.h"
#include "logger.h"
#include "vector2.h"
#include <vector>
#include <map>
#include <typeinfo>
#ifndef _COMPONENT_MANAGER_H_
#define _COMPONENT_MANAGER_H_

class Entity;

/* ======= HEALTH TYPEDEF ===== */
typedef struct HealthComponent {
	Entity* parent;
    
	float curr;
	float max;
	
	HealthComponent(float c, float m){
		curr = c;
		max = m;
	}
    
	void increment(float val) {
		curr += val;
	}
    
	void decrement(float val) {
		curr -= val;
	}
    
	void incrementM(float val) {
		max += val;
	}
    
	void decrementM(float val) {
		max -= val;
	}
} HealthComponent;

/* ======== TRNSF TYPEDEF ======= */
typedef struct TransformComponent {
	
	Entity* parent;
    
	Vector2 position;
	
	TransformComponent& operator=(const TransformComponent tc) {
		return *this;
	}
    
	TransformComponent() {
		position = *Vector2::Zero();
	}
    
	TransformComponent(float x, float y) {
        
		position.X = x;
		position.Y = y;
	}
    
	void move(float xspeed, float yspeed) {
		position.X += xspeed;
		position.Y += yspeed;
		
	}
    
} TransformComponent;


#endif
class ComponentManager {
    
#define TRANSFORMC_ID	0
#define HEALTHC_ID		1
    
    private:
	std::vector<HealthComponent> hpComps;
	std::vector<TransformComponent> tcComps;
    
    public:
	ComponentManager() {
		hpComps = std::vector<HealthComponent>();
		tcComps = std::vector<TransformComponent>();
	}
    
	inline std::vector<HealthComponent> getHealthComponents() { return hpComps; }
	inline std::vector<TransformComponent> getTransformComponents() { return tcComps; }
    
    
	TransformComponent* getTransformCompByParent(Entity* _parent) {
		for (int i = 0; i < tcComps.size(); i++) {
			if (tcComps[i].parent == _parent) {
				return &tcComps[i];
			}
		}
        
	}
    
	HealthComponent* getHealthCompByParent(Entity* _parent) {
		for (int i = 0; i < hpComps.size(); i++) {
			if (hpComps[i].parent == _parent) {
				return &hpComps[i];
			}
		}
	}
    
	void assignComponentToEntity(Entity& ent, IGuint compID) {
		switch(compID) {
            case TRANSFORMC_ID:
            {
                TransformComponent transform = TransformComponent();
                transform.parent = &ent;
                tcComps.push_back(transform);
                Logger::log("Transform comp assigned", LT::INFO);
            }break;
            case HEALTHC_ID: 
            {
                HealthComponent hp = HealthComponent(100,100);
                hp.parent = &ent;
                hpComps.push_back(hp);
                Logger::log("Health comp assigned", LT::INFO);
            }break;
            
		}
        
	}
    
	
};

