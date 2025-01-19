#pragma once
#include "Grid.h"

#define MAZE GridManager::Instance()

class GridManager
{
private:
	Grid* currentGrid;
	GridManager() = default;

	~GridManager() {}
	GridManager(const GridManager&) = delete;
	GridManager& operator =(const GridManager&) = delete;

public:
	
	inline static GridManager& Instance()
	{
		static GridManager manager;
		return manager;
	}

	void SetGrid(Grid* _grid) { currentGrid = _grid; }
	inline Grid* GetGrid() { return currentGrid; }
	
	Vector2D GetRandomGridPoint() 
	{
		Vector2D rand_cell(-1, -1);
		while (!currentGrid->isValidCell(rand_cell))
			rand_cell = Vector2D((float)(rand() % currentGrid->getNumCellX()), (float)(rand() % currentGrid->getNumCellY()));

		return rand_cell;
	}
};