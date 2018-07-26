#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include <vector>

#define CELL_SIZE 15
#define BORDER_SIZE 20
#define GRID_HEIGHT 35
#define GRID_WIDTH 63\

//So we just need a decision making tree no. We can implement this with our flying plane, and have it change behaviours based on whatever the mouse is doing. 
//However, we can't just make a simple bool of if statement to change it's behaviour, we need to have a proper state tree for a proper decision making implementation

//So to implement decision making, we can simply have the plane changing what behaviours it's doing, like Wander or Avoid, based on how close it is to the mouse
//IMPLEMENT FINITE STATE MACHINE!
//Done with an switch statement/ Enum

class Input;

class Grid
{
public:
	//-------------------------------------------------------------------------------------------------------|
	// NODE CLASS
	// When nesting a class like this, you need to put the nested class on the top of the "public" keyword
	// in the main class, because it is read top-down, and won't know what's being referenced if it's
	// the other way around
	//-------------------------------------------------------------------------------------------------------|
	class Node
	{
		//Classes are private by default, so even if the Grid class is set to public, we still need to set Node to public to access it
	public:
		Node();
		~Node();

		int m_directNeighbours = 0;		//The amount a neighbours to the left, right, up, and down, max of 4
		int m_diagonalNeighbours = 0;	//The amount of neighbours surrounding the cell diagonally, max of 4
		int m_totalNeighbours = 0;		//The sum of both direct and diaganol neighbours, used when printing neighbours on top of cells
		int m_gScore = 0;				//The cost to traverse a node
		int m_hScore = 0;				//Heuristic Cost A*
		int m_fScore = 0;				//Total of hScore and gScore

		bool m_pathingNode = false;		//Starting and Ending nodes will be what we use for pathfinding
		bool m_traversed = false;		//Keeping track of whether or not a node has already been processed

		Node* parentNode;				//The current Node's previous node in it's list of traversed nodes
										
		//Pointers to all 8 neighbour nodes. Because we have 2205 cells, there will be a possible maximum of 17640 pointers (70560 bytes). Good lord
		// BUT THIS IS WHAT WE'RE GOING WITH UNTIL WE CAN FIND SOMETHING BETTER, which we can't. We tried. For hours. This is rubbish.
		Node* neighbourNode[8]; //Note: Node[0] is the top node, and works clockwise around	eg. topNeighbour -> topRightNeighbour -> rightNeighbour
		int edgeCost[8];

		bool mouseCheck(Grid* pGrid, int x, int y);			//Checks which node the mouse is hovering over when a mouse button is clicked
		void mouseClickLeft(Grid* pGrid, int x, int y);		//Turns a node on or off
		void mouseClickRight(Grid* pGrid, int x, int y);	//Turns a node into a pathing node

		Vector2 m_nodePosition;								//Stores the x and y position of a node
	};

public:
	Grid();
	~Grid();

	void update(float , Grid* pGrid, bool leftClick);
	void draw(aie::Renderer2D* pRenderer, Grid* pGrid, aie::Font* pFont);

	void countNeighbours(aie::Renderer2D* pRenderer, Grid* pGrid, aie::Font* pFont);  //Runs a for loop through the grid, making a count of how many active neighbours a cell has

	bool activeCell[GRID_WIDTH][GRID_HEIGHT]; //Bool to store whether a cell should be active or not

	void resetCell();				//Randomises every cell on the screen, randomly turning them "on" or "off"	

	bool counted = false;			//A bool that stores whether or not the neighbours have already been counted
	bool gridSwitch = true;			//A bool to toggle the grid on and off	
	void pathOnly(Grid* pGrid);				//A function that will only draw the yellow path if true.
	int pathingNodeCount = 0;		//Keeps track of how many pathing nodes we have, shouldn't ever exceed 3

	Node* pathingNodeStart;			//A way to store which nodes are the starting and ending nodes
	Node* pathingNodeEnd;

	std::vector<Node*> openList;
	std::vector<Node*> closedList;
	std::vector<Vector2> path;

	//Dijkstra's Shortest Path Algorithm. Finds the shortest path to our 'endingNode'. Previously we had this function inside the Nodes class, 
	// so it was making a dijkstraSearch() function for all active nodes (over 2000)
	std::vector<Vector2> dijkstraSearch(Node* startingNode, Node* endingNode);
	
	Node* m_cellNode[GRID_WIDTH][GRID_HEIGHT];		//A 2D array the same size as the grid, to store each of the nodes
};

