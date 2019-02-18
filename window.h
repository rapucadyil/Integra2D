#include <vector>
#include "definitions.h"
#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_
class Scene;
struct SDL_Window;
struct SDL_Renderer;
struct InputHandler;
class Entity;

class Window {
private:
	SDL_Window* _window;
	InputHandler* _windowInput;
	SDL_Renderer* _renderer;
	std::vector<Scene*> _scenes;
public:
	Scene* _currentScene; 
	static bool _closed;

public:
	Window(IGstring title, int x, int y, int w, int h);
	~Window();
	void update(IGfloat dt);
	bool shouldClose();
	void addScene(Scene* scene);
	inline SDL_Window& getWindow() { return *_window; }
	inline SDL_Renderer& getRenderer() { return *_renderer; }
	inline std::vector<Scene*>& getScenes() { return _scenes; }
	inline Scene& getCurrentScene() { return *_currentScene; }

private:
	bool init(IGstring title, int x, int y, int w, int h);
	void sceneStateMachine(IGfloat dt);
};

#endif


