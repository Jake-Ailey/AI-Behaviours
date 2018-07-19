#pragma once
#include "GameObject.h"
#include <vector>

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

	void update(float , Grid* pGrid, bool leftClick);
	void draw(aie::Renderer2D* pRenderer, Grid* pGrid, aie::Font* pFont);

	void resetCell();		//Randomises every cell on the screen, randomly turning them "on" or "off"	
	void countNeighbours(aie::Renderer2D* pRenderer, Grid* pGrid, aie::Font* pFont);  //Runs a for loop through the grid, making a count of how many active neighbours a cell has

	bool activeCell[GRID_WIDTH][GRID_HEIGHT]; //Bool to store whether a cell should be active or not

	bool pathingCell[GRID_WIDTH][GRID_HEIGHT];	//Bool that will make a node seek to another node
	bool counted = false;	//A bool that stores whether or not the neighbours have already been counted
	bool gridSwitch = true;	//A bool to toggle the grid on and off	

	class Node
	{
		//Classes are private by default, so even if the Grid class is set to public, we still need to set Node to public to access it
	public:
		Node();
		~Node
		(
		);

		int m_directNeighbours = 0;		//The amount a neighbours to the left, right, up, and down, max of 4
		int m_diagonalNeighbours = 0;	//The amount of neighbours surrounding the cell diagonally, max of 4
		int m_totalNeighbours = 0;		//The sum of both direct and diaganol neighbours, used when printing neighbours on top of cells
		int m_gScore = 0;					//The cost to traverse a node is equal to m_totalNeighbours / 2, rounded down (hopefully)

		bool m_pathingNode = false;	//Starting and Ending nodes will be what we use for pathfinding
		int pathingNodeCount = 0;

		Node* parentNode;				//The current Node's previous node in it's list of traversed nodes
		Node* currentNode;
		Node* targetNode;				//The next node we aim to process

		Node* pathingNodeStart;			//A way to store which nodes are the starting and ending nodes
		Node* pathingNodeEnd;

		std::vector<Node*> openList;		
		std::vector<Node*> closedList;

		bool mouseCheck(Grid* pGrid, int x, int y);			//Checks which node the mouse is hovering over when a mouse button is clicked
		void mouseClickLeft(Grid* pGrid, int x, int y);		//Turns a node on or off
		void mouseClickRight(Grid* pGrid, int x, int y);	//Turns a node into a pathing node

		void dijkstraSearch(Grid* pGrid, Node* startingNode, Node* endingNode);

		Vector2 m_nodePosition;
	};
	
	Node* m_cellNode[GRID_WIDTH][GRID_HEIGHT];
};

