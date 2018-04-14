#include "Life.hpp"

bool Cell::Status() /*!< Indicates if a cell is alive or not */

  {
    return alive;
  }

Cell & Cell::operator=(bool i)
  {
    alive = i;
    return *this;
  }

Life::Life (int nLin, int nCol)
  {

    Nlin = nLin;
    NCol = nCol;

    Grid = new Cell *[nLin];

    for (int i = 0; i < nLin; ++i) {
      Grid[i] = new Cell[nCol];
    }

  }

Life::~Life()
  {
	for (int i = 0; i < Nlin; ++i) {
		delete [] Grid[i];
	}
	delete [] Grid;
  }

int Life::NeighborsCount(int Line,int Col)
  {
    int count = 0;

    for (int i = -1; i < 1; ++i) {
      for (int j = -1; j < 1; ++j) {
        count += Grid[Line+i][Col+j].Status();
      }

    }
    return count;
  }

void Life::CellBirth(int Line,int Col)
  {
    Grid[Line][Col] = true;
  }
