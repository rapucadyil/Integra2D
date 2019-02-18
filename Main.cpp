#include <SDL.h>
#include <SDL_image.h>
#include <glew.h>
#include <iostream>
#include "definitions.h"
#include "inputhandler.h"
#include "Sprite.h"
#include "componentmanager.h"
#include "entitymanager.h"
#include "entity.h"
#include "scene.h"
#include "ecs.h"
#include "window.h"

#define INTEGRA_CREATE_WINDOW(N, X, Y, W, H) Window(N, X, Y, W, H)

#if 0
int main(int argc, char* argv[]) {
    
	Window win = INTEGRA_CREATE_WINDOW("Integra Editor", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	win.addScene(win._currentScene = new Scene("Main", 0));
	win._currentScene->setRenderer(&win.getRenderer());
    
    
    
	while (!win.shouldClose()) {
		win.update(0);
	}
    
    
	/* Clean up */
    
	return 0;
}
#endif

int main(int argc, char**) {
    SDL_Window* win = SDL_CreateWindow("Integra Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    Sprite spr = Sprite("test_image.png", ren);
    
    // spr.flip = SDL_FLIP_HORIZONTAL;
    
    
    while(1) {
        
        SDL_SetRenderDrawColor(ren, 255,255,255,255);
        spr.draw(ren, 100, 100, 128, 128);
    }
    
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    
    SDL_Quit();
}




#if 0
int main(int argc, char* argv[]) {
    
	ECS ecs;
	ecs.init();
    
	INTEGRA_OBJECT player;
	
	player.m_Ent = ecs.entMgr.createEntity("Player");
	ecs.cmpMgr.assignComponentToEntity(*player.m_Ent, 0);
	ecs.cmpMgr.assignComponentToEntity(*player.m_Ent, 1);
	player.m_Transform = ecs.cmpMgr.getTransformCompByParent(player.m_Ent);
	player.m_HP = ecs.cmpMgr.getHealthCompByParent(player.m_Ent);
	
    while(player.m_Ent != nullptr) {
        ecs.monitorHealthComps();
        player.m_HP->decrement(100);
        system("PAUSE");
    }
    
    
    
#define OPENGL_TEST 0
#if OPENGL_TEST
	
	SDL_Window* win = SDL_CreateWindow("OpenGL-test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    
	SDL_GL_CreateContext(win);
    
    
    glewInit();
    
	float vertexData[12] = {
		0.0f, 0.0f,
		0.5f, 0.0f,
		0.5f, 0.5f,
        0.0f, 0.0f,
        0.0f, 0.5f,
        0.5f, 0.5f
	};
    
    
    
    
	GLuint vbo = 0;
	if (vbo == 0)
		glGenBuffers(1, &vbo);
    
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
    
	while (1) {
        
		glClearDepth(1.0);
        
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
        
		glEnableVertexAttribArray(0);
        
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
        
		glDrawArrays(GL_TRIANGLES, 0, 6);
        
		glDisableVertexAttribArray(0);
        
		glBindBuffer(GL_ARRAY_BUFFER, 0);
        
		SDL_GL_SwapWindow(win);
	}
#endif
	return 0;
    
}
#endif
