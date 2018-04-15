#include "Cell.hpp"
Life::Life (int nLin, int nCol)
  {

    NLin = nLin;
    NCol = nCol;

    Grid = new Cell *[nLin];

    for (int i = 0; i < nLin; ++i) {
      Grid[i] = new Cell[nCol];
    }

  }

Life::~Life()
  {
	for (int i = 0; i < NLin; ++i) {
		delete [] Grid[i];
	}
	delete [] Grid;
  }

int Life::NeighborsCount(int Line,int Col)
  {
    int count = 0;

    for (int i = -1; i <=1; ++i) {
      for (int j = -1; j <=1; ++j) {
        if(( Line+i < NLin and Col+j < NCol  ) and (Line+i > 0 and Col+j > 0)){
          if(!(i == 0 and j == 0)){
          count += Grid[Line+i][Col+j].Status();
          }
        }
      }

    }
    return count;
  }

void Life::CellBirth(int Line,int Col)
  {
    Grid[Line][Col] = true;
  }

bool Life::Status(int Line, int Col)
{
  return Grid[Line][Col].Status();
}

Cell& Life::operator()(int Line, int Col)
{
  assert(Line >= 0 && Line < NLin);
  assert(Col >= 0 && Col < NCol);
  return Grid[Line][Col];
}
void Life::Print()
{

  for (int i = 0; i < NLin; ++i) {
    for (int j = 0; j < NCol; ++j) {

    if ( Grid[i][j].Status() == 1 ){
        std::cout << "*";
      }
      else {
        std::cout << "_";
      }
    }
    std::cout << std::endl;
    }

}

Life& Life::operator=(const Life &rhs)
{
  for (int i = 0; i < NLin; ++i) {
    for (int j = 0; j < NCol; ++j) {
      Grid[i][j] = rhs.Grid[i][j];
    }

  }

}
/*int Life::CheckCells()
{

  for (int i ; i < NLin; ++i) {
    for (int j; j < NCol; ++j) {
      
    }

  }

}
*/
