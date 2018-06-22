#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "WanderBehaviour.h"
#include "Grid.h"


class Duck;
class Grid;
class Node;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;

	Grid* m_grid;
	Grid::Node* m_node;
	Duck* m_player;
	SeekBehaviour* m_seekBehaviour;
	FleeBehaviour* m_fleeBehaviour;
	WanderBehaviour* m_wanderBehaviour;
};