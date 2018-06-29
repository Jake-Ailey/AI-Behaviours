#include "Grid.h"
#include "Font.h"
#include "Input.h"

//TO-DO:
//Decision Making Techniques
//Pathfinding  -Dijkstra's Path

Grid::Grid()
{
	//When the program starts, it will run through a loop turning cells on and off at random
	// Closing and re-running the program will not result in a different set of cells each time, as it isn't recompiling the code, and not
	// randomising them each time, simply re-using the old preset. This is why we have the "resetCell()" function.
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			int active = rand() % 2;

			if (active == 0)
				activeCell[i][j] = false;
			else
				activeCell[i][j] = true;

			m_cellNode[i][j] = new Node;
		}
	}
}

Grid::~Grid()
{
	
}

void Grid::update(float deltaTime, Grid* pGrid)
{
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			if (m_cellNode[i][j]->mouseCheck(pGrid, i, j) == true)
			{
				m_cellNode[i][j]->mouseClick(pGrid, i, j);
			}			
		}
	}
}

//The for loop starts at one so that it is away from the edge of the screen, and gives a nice "border" around the grid
//Takes in the grid with the randomised active cells, and draws the active ones on their corrosponding positions, also takes in a font
// to write in the neighbour count over the top of every cells
void Grid::draw(aie::Renderer2D* pRenderer, Grid* pGrid, aie::Font* pFont)
{
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			//Resets render colour every frame, so that the cells are all the same colour
			pRenderer->setRenderColour(0xFFFFFFFF);

			//Checks to see if a cell is active, and if so, draws it. The (i + 1) and (j + 1) are there to alter the x and y pos of the cells, 
			// so that it fits nicely into the screen, and away from the edge of the screen. Gives it an artificial "border" 
			if(activeCell[i][j])
			pRenderer->drawBox((i + 1) * BORDER_SIZE, (j + 1) * BORDER_SIZE, CELL_SIZE, CELL_SIZE, 0, 5.0f);

			m_cellNode[i][j]->m_nodePosition.x = (i + 1) * BORDER_SIZE;
			m_cellNode[i][j]->m_nodePosition.y = (j + 1) * BORDER_SIZE;

			pRenderer->setRenderColour(0x000000FF); //Setting the text colour to red 0xd80f0fFF

			//Checking to see whether or not a cell is active, and if true, draws the number of neighbours it has over the top
			if (activeCell[i][j] == true)
			{
				//sprintf converts our int into a number in text, and then pushes that new text into our char array
				char text[4];
				sprintf(text, "%i", pGrid->m_cellNode[i][j]->m_totalNeighbours);

				pRenderer->drawText(pFont, text, i * BORDER_SIZE + 14, j * BORDER_SIZE + 13, 2);
			}
		}
	}
	countNeighbours(pRenderer, pGrid, pFont);
}

//This function reiterates through every cell, randomly turning them on or off. Basically a randomiser for every cell.
void Grid::resetCell()
{
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			int active = rand() % 2;

			if (active == 0)
				activeCell[i][j] = false;
			else
				activeCell[i][j] = true;
		}
	}
	counted = false;
}

//REMEMBER: AN ARRAY STARTS AT 0! THIS IS WHY YOU'VE HAD A FEW ISSUES HERE
void Grid::countNeighbours(aie::Renderer2D* pRenderer, Grid* pGrid, aie::Font* pFont)
{
	//Function to count how many neighbours an active cell has. Skips over any unactive cells, 
	// and counts the cells above, below, to the right, and to the left
	if (counted == false)
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			for (int j = 0; j < GRID_HEIGHT; j++)
			{
				//Checking the 4 possible neighbours and incrementing the neghbour count if they exist
				if (pGrid->activeCell[i][j])
				{
					pGrid->m_cellNode[i][j]->m_directNeighbours = 0; //Resets the neighbour count each time it runs
					pGrid->m_cellNode[i][j]->m_diagonalNeighbours = 0;

					//Checking directly adjacent cells

					//We need to include the -1 as the array starts at 0, not 1
					//If i is smaller than the maximum width, check to it's right
					if (i < (GRID_WIDTH - 1))
					{
						if (pGrid->activeCell[i + 1][j])
							pGrid->m_cellNode[i][j]->m_directNeighbours++;
					}

					//If i is larger than the first column, check the node to it's left. Otherwise we will check beyond the grind and get weird results
					if (i > 0)
					{
						if (pGrid->activeCell[i - 1][j])
							pGrid->m_cellNode[i][j]->m_directNeighbours++;
					}

					//If j is larger than the first row, check the node above it
					//Notice that as the grid is drawing across and then down, it starts off at 0 on the top of the screen,
					//and increases as it works down the grid. -1 will make the grid go UP.
					if (j > 0)
					{
						if (pGrid->activeCell[i][j - 1])
							pGrid->m_cellNode[i][j]->m_directNeighbours++;
					}

					//If j is smaller than the maximum grid height, check below it
					if (j < (GRID_HEIGHT - 1))
					{
						if (pGrid->activeCell[i][j + 1])
							pGrid->m_cellNode[i][j]->m_directNeighbours++;
					}

					//Checking diagonal cells
					//These next 4 are the same as the 4 above, only we've combined them to get the diagonal cells
					if (i < (GRID_WIDTH - 1) && j > 0)
					{
						if (pGrid->activeCell[i + 1][j - 1] == true)		//Top Right
							pGrid->m_cellNode[i][j]->m_diagonalNeighbours++;
					}

					if (i > 0 && j < (GRID_HEIGHT - 1))
					{
						if (pGrid->activeCell[i - 1][j + 1] == true)		//Top Left
							pGrid->m_cellNode[i][j]->m_diagonalNeighbours++;
					}

					if (i < (GRID_WIDTH - 1) && j < (GRID_HEIGHT - 1))
					{
						if (pGrid->activeCell[i + 1][j + 1] == true)		//Bottom Right
							pGrid->m_cellNode[i][j]->m_diagonalNeighbours++;
					}

					if (i > 0 && j > 0)
					{
						if (pGrid->activeCell[i - 1][j - 1] == true)		//Bottom Left
							pGrid->m_cellNode[i][j]->m_diagonalNeighbours++;
					}

					//Adding the nodes two neighbour groups into one
					pGrid->m_cellNode[i][j]->m_totalNeighbours = (pGrid->m_cellNode[i][j]->m_directNeighbours +
						pGrid->m_cellNode[i][j]->m_diagonalNeighbours);

					//Makes a cell inactive if it has no neighbours
					//if (pGrid->m_cellNode[i][j]->m_totalNeighbours == 0)
					
				}
			}
		}
		counted = true; //We set this to true so that it doesn't recount every frame, which will constantly increment the numbers until we crash
	}
}


//-----------------------------------------------------------------------------------------------------|
// NODE CLASS																						   |
//-----------------------------------------------------------------------------------------------------|

Grid::Node::Node()	//Apparently a nested class needs to reference the class it's inside as well
{

}

Grid::Node::~Node()
{

}

//Function that checks whether the mouse is hovering above a node, to prepare for the mouseClick function (basically shoddy collision)
bool Grid::Node::mouseCheck(Grid* pGrid, int x, int y)
{
	aie::Input* pInput = aie::Input::getInstance();

	Vector2 v2MousePos;

	v2MousePos.x = (float)pInput->getMouseX();
	v2MousePos.y = (float)pInput->getMouseY();

	//hacky check to see whether or not the mouse is hovering over a cell
	//The - 9 after the CELL_SIZE helps to bring the mouse position i line, as the cells have been moved slightly
	if (v2MousePos.x >= (pGrid->m_cellNode[x][y]->m_nodePosition.x - 10) && v2MousePos.y >= (pGrid->m_cellNode[x][y]->m_nodePosition.y - 10))
	{
		if (v2MousePos.x <= (pGrid->m_cellNode[x][y]->m_nodePosition.x + CELL_SIZE - 9) && v2MousePos.y <= (pGrid->m_cellNode[x][y]->m_nodePosition.y + CELL_SIZE - 9))
		{
			if (pInput->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
				return true;
		}
	}
	return false;
}

//This will hopefully be a function wherein we can click on a cell to turn it on or off. Cells will first need an x and y pos however
void Grid::Node::mouseClick(Grid* pGrid, int x, int y)
{
	if (pGrid->activeCell[x][y] == true)
		pGrid->activeCell[x][y] = false;

	else if (pGrid->activeCell[x][y] == false)
		pGrid->activeCell[x][y] = true;

	pGrid->counted = false;
}
//_____________________________________________________________________________________________________|