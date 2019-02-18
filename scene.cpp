#include "scene.h"
#include "inputhandler.h"
#include <SDL.h>
/* ====================== Static Declarations ================================================ */
/* ====================== END DECLARATIONS =================================================== */

Scene::Scene(IGstring name, IGuint id) {
	_sceneBuildID = id;
	_sceneName = name;
	_active = true;
}


Scene::~Scene() {
	delete _sys;
	SDL_DestroyRenderer(_renderer);
}

void Scene::setRenderer(SDL_Renderer* renderer) {
	_renderer = renderer;
}

void Scene::tick(IGfloat dt, InputHandler& input) {
}

void Scene::render() {

}



