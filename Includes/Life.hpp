#ifndef CLASSES
#define CLASSES
#include <iostream>
#include <iterator>
#include <vector>

class Cell
{
protected:
  bool alive;
public:
  Cell();
  bool Status();/*!< Indicates if a cell is alive or not */
  Cell & operator=(bool i);
};

class Life: public Cell
{
private:
  int Nlin; /*! Grid Height; */
  int NCol; /*! Grid Width; */
  Cell ** Grid;
  //  std::vector <int> Alive_lin; /*! Line Index for Alive cells */
  //  std::vector <int> Alive_col; /*! Line Index for Alive cells */
public:
  Life (int nLin, int nCol);
  ~Life();


  int NeighborsCount(int Line,int Col);
  void CellBirth(int Line,int Col);
};
#endif
