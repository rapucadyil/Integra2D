#include <vector>
#include "logger.h"
#include "definitions.h"
#pragma once
struct SDL_Window;
struct SDL_Renderer;
class EntitySystem;
class InputHandler;
class TransformComponent;
#ifndef _SCENE_H_
#define _SCENE_H_

class Scene {
private:
	EntitySystem* _sys;
	IGstring _sceneName;
	IGuint _sceneBuildID;
	SDL_Renderer* _renderer;
	IGboolean _active;

public:
	static TransformComponent _playerTransform;
	static std::vector<TransformComponent> _entityTransformComps;
public:
	Scene(IGstring name, IGuint id);
	~Scene();	

	void tick(IGfloat dt, InputHandler& input);

	void render();

	inline void setEntitySystem(EntitySystem* sys) { _sys = sys; }

	void setRenderer(SDL_Renderer* renderer);

	inline IGboolean getActive() { return _active; }
	inline SDL_Renderer& getRenderer() { return *_renderer; }
	inline EntitySystem& getEntitySystem() { return *_sys; }
	inline IGstring getSceneName() { return _sceneName; }
	inline IGuint getBuildID() { return _sceneBuildID; }

};

#endif
