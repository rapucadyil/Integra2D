#include "definitions.h"
#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity {
private:
	IGuint _entID;
	IGstring _entName;
	IGboolean _active;
public:
	Entity(IGstring name);

	void setEntityName(char* val) {
		_entName = val;
	}

	inline IGuint getEntityID() { return _entID; }
	inline IGstring getName() { return _entName; }
	inline IGboolean getActive() { return _active; }

	inline bool operator==(const Entity& other) {
		return (this->_entID == other._entID) && (this->_entName == other._entName);
	}

};

#endif
