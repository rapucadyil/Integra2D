#include "vector2.h"
#include "definitions.h"
#include "logger.h"
#include "componentmanager.h"
#include "entitymanager.h"
#include "entity.h"
#pragma once
#ifndef _ECS_H_
#define _ECS_H_

constexpr int MAX_ENTITIES =	 10;

typedef struct gameobject {
    
	Entity* m_Ent;
	TransformComponent* m_Transform;
	HealthComponent* m_HP;
    
	gameobject() {
        
	}
    
    
	void modHealth(char opr, float val) {
		switch (opr) {
            case 'C':
			m_HP->increment(val);
            break;
            case 'M':
			m_HP->incrementM(val);
            break;
		}
	}
    
	void move(float x, float y) {
		m_Transform->move(x, y);
	}
    
}INTEGRA_OBJECT;

class ECS {
    
    public:
	ComponentManager cmpMgr;
	EntityManager entMgr;
    
    public:
    
    
	void init( ) {
		cmpMgr = ComponentManager();
		entMgr = EntityManager();
        
	}
    
    void monitorHealthComps() {
        for (int i = 0; i < cmpMgr.getHealthComponents().size(); i++){
            
            if(cmpMgr.getHealthComponents()[i].curr <= 0) {
                //delete cmpMgr.getHealthComponents()[i].parent;
            }
        }
    }
    
};

#endif

