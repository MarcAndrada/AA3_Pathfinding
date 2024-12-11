#include "Grid.h"

using namespace std;

Grid::Grid(char* filename)
{
	num_cell_x = SRC_WIDTH / CELL_SIZE;
	num_cell_y = SRC_HEIGHT / CELL_SIZE;

	// Initialize the terrain matrix from file (for each cell a zero value indicates it's a wall, positive values indicate terrain cell cost)
	std::ifstream infile(filename);
	std::string line;
	std::vector<std::vector<int>> terrain;
	while (std::getline(infile, line))
	{
		vector<int> terrain_row;
		std::stringstream lineStream(line);
		std::string cell;
		while (std::getline(lineStream, cell, ','))
			terrain_row.push_back(atoi(cell.c_str()));
		SDL_assert(terrain_row.size() == num_cell_x);
		terrain.push_back(terrain_row);
	}
	SDL_assert(terrain.size() == num_cell_y);
	infile.close();

	for (int i = 0; i < terrain.size(); i++)
	{
		this->terrain.push_back(std::vector<Node*>());
		for (int j = 0; j < terrain[i].size(); j++)
		{
			this->terrain[i].push_back(new Node(Vector2D(j, i), terrain[i][j]));
		}
	}
}

Grid::~Grid()
{
}

int Grid::getNumCellX()
{
	return num_cell_x;
}

int Grid::getNumCellY()
{
	return num_cell_y;
}

std::vector<Node*> Grid::getNeighbours(Node* node)
{
	std::vector<Node*> neighbours;

	//Arriba
	if (node->getPosition().y > 0 && terrain[node->getPosition().y - 1][node->getPosition().x] != nullptr)
		neighbours.push_back(terrain[node->getPosition().y - 1][node->getPosition().x]);
	//Abajo
	if (node->getPosition().y < num_cell_y - 1 && terrain[node->getPosition().y + 1][node->getPosition().x] != nullptr)
		neighbours.push_back(terrain[node->getPosition().y + 1][node->getPosition().x]);
	//Derecha
	if (node->getPosition().y < num_cell_y - 1 && terrain[node->getPosition().y][node->getPosition().x + 1] != nullptr)
		neighbours.push_back(terrain[node->getPosition().y][node->getPosition().x + 1]);
	//Izquierda
	if (node->getPosition().y > 0 && terrain[node->getPosition().y][node->getPosition().x - 1] != nullptr)
		neighbours.push_back(terrain[node->getPosition().y][node->getPosition().x - 1]);

	return neighbours;
}

Vector2D Grid::cell2pix(Vector2D cell)
{
	int offset = CELL_SIZE / 2;
	return Vector2D(cell.x*CELL_SIZE + offset, cell.y*CELL_SIZE + offset);
}

Vector2D Grid::pix2cell(Vector2D pix)
{
	return Vector2D((float)((int)pix.x / CELL_SIZE), (float)((int)pix.y / CELL_SIZE));
}

bool Grid::isValidCell(Vector2D cell)
{
	if ((cell.x < 0) || (cell.y < 0) || (cell.y >= terrain.size()) || (cell.x >= terrain[0].size()))
		return false;
	return !(terrain[(unsigned int)cell.y][(unsigned int)cell.x]->getType() == 0);
}