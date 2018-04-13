#include <iostream>
#include <iterator>
#include <cstdbool>
#include <vector>
class Cell
{
private:
  _Bool alive;

public:
  Cell()
  {
    alive = false;
  }

  _Bool Status() /*!< Indicates if a cell is alive or not */

  {
    return alive;
  }


};


class Life
{
private:
  int Nlin; /*! Grid Height; */
  int NCol; /*! Grid Width; */
  Cell ** Grid;
  std::vector <int> Alive_lin; /*! Line Index for Alive cells */
  std::vector <int> Alive_col; /*! Line Index for Alive cells */


public:
  Life (int nLin, int nCol)
  {

    Nlin = nLin;
    NCol = nCol;

    Grid = new Cell *[nLin];

    for (int i = 0; i < nLin; ++i) {
      Grid[i] = new Cell[nCol];
    }

  }

};

int Neighbors(Cell * Lin, Cell * Col)
   {
    
   }


int main(int argc, char *argv[])
{
  
  return 0;
}
