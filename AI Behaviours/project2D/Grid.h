#pragma once
#include "GameObject.h"

#define CELL_SIZE 15
#define BORDER_SIZE 20
#define GRID_HEIGHT 35
#define GRID_WIDTH 63

class Input;

class Grid
{
public:
	Grid();
	~Grid();

	void update(float deltaTime);
	void draw(aie::Renderer2D* pRenderer, Grid* pGrid, aie::Font* pFont);

	void mouseClick();	
	void resetCell();		//Randomises every cell on the screen, randomly turning them "on" or "off"	
	void countNeighbours(aie::Renderer2D* pRenderer, Grid* pGrid, aie::Font* pFont);  //Runs a for loop through the grid, making a count of how many active neighbours a cell has

	bool activeCell[GRID_WIDTH][GRID_HEIGHT]; //Bool to store whether a cell should be active or not
	bool counted = false;	//A bool that stores whether or not the neighbours have already been counted
	bool gridSwitch = true;	//A bool to toggle the grid on and off

	class Node
	{
		//Classes are private by default, so even if the Grid class is set to public, we still need to set Node to public to access it
	public:
		Node();
		~Node();


		int m_directNeighbours = 0;		//The amount a neighbours to the left, right, up, and down, max of 4
		int m_diagonalNeighbours = 0;	//The amount of neighbours surrounding the cell diagonally, max of 4
		int m_totalNeighbours = 0;		//The sum of both direct and diaganol neighbours, used when printing neighbours on top of cells
		int m_cost = 0;					//The "cost" that each cell will have to be traversed through, needed for Dijkstra's Shortest Path Algorithm

		Vector2 m_nodePosition;
	};


	Node* m_cellNode[GRID_WIDTH][GRID_HEIGHT];
};

