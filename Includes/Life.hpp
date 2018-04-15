#ifndef _Life
#define _Life
#include <cassert>
#include "Cell.hpp"
class Life: public Cell
{
protected:
  int NLin; /*! Grid Height; */
  int NCol; /*! Grid Width; */
  Cell ** Grid;
public:
  Life (int nLin, int nCol);
  ~Life();


  int NeighborsCount(int Line,int Col);
  void CellBirth(int Line,int Col);
  void Print();
  bool Status(int Line, int Col); /*! Deprecated for now */
  Cell& operator()(int Line, int Col);/*! Returns Grid[i][j] using tuples (i,j) */
  Life& operator=(const Life& rhs);
};

#endif


