#include "entity.h"
#include <math.h>
#include <string>
#include <functional>
#include <stdlib.h>
#include <time.h>

Entity::Entity(IGstring name) {
	_active = true;
	_entName = name;
	std::hash<IGstring> name_hash;
	std::size_t temp_id = name_hash(_entName) % 100;
	_entID = temp_id;
}
