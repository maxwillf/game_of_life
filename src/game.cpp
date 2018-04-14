#include <iostream>
#include <iterator>
#include <vector>
class Cell
{
protected:
  bool alive;
public:
  Cell()
  {
    alive = false;
  }

  bool Status() /*!< Indicates if a cell is alive or not */

  {
    return alive;
  }

  Cell & operator=(bool i)
  {
    alive = i;
    return *this;
  }

};


class Life: public Cell
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

  

  ~Life()
  {
	for (int i = 0; i < Nlin; ++i) {
		delete [] Grid[i];
	}
	delete [] Grid;
  }

  int NeighborsCount(int Line,int Col)
  {
    int count = 0;

    for (int i = -1; i < 1; ++i) {
      for (int j = -1; j < 1; ++j) {
        count += Grid[Line+i][Col+j].Status();
      }

    }
    return count;
  }

  void CellBirth(int Line,int Col)
  {
    Grid[Line][Col] = true;
  }
};


int main(int argc, char *argv[])
{
  Life Try (8,8);
  Try.CellBirth(2, 1);
  Try.CellBirth(1, 2);
  std::cout << "Teste " << Try.NeighborsCount(2,2)<< std::endl;
  return 0;
}
