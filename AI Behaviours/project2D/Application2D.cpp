#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Agent.h"
#include "Duck.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 20);

	m_seekBehaviour = new SeekBehaviour();
	m_fleeBehaviour = new FleeBehaviour();
	m_wanderBehaviour = new WanderBehaviour();

	m_grid = new Grid();
	
	m_player = new Duck(m_shipTexture, Vector2(400, 400), 1.6f);
	
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	delete m_seekBehaviour;
	delete m_fleeBehaviour;
	delete m_wanderBehaviour;
	
	delete m_grid;

	delete m_player;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	//Button to reset the grid. Will redraw the grid and randomise everything on screen. 100% random, so will not 
	// create efficient or optimal paths on it's own
	if (input->wasKeyPressed(aie::INPUT_KEY_R))
	{
		m_grid->resetCell();
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		//Simple toggle switch for the grid

		if (m_grid->gridSwitch == false)
			m_grid->gridSwitch = true;
		else if (m_grid->gridSwitch == true)
			m_grid->gridSwitch = false;
	}

	//------------------------------------------|
	// Camera Controls, for testing
	//------------------------------------------|
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		m_cameraX -= 200.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_cameraX += 200.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_cameraY -= 200.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_cameraY += 200.0f * deltaTime;
	}
	//__________________________________________|

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	if(input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
	m_grid->update(deltaTime, m_grid);

	m_player->update(deltaTime);
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//Player sprite
	m_player->draw(m_2dRenderer);

	//Drawing a grid
	if(m_grid->gridSwitch == true)
	m_grid->draw(m_2dRenderer, m_grid, m_font);

	// done drawing sprites
	m_2dRenderer->end();
}