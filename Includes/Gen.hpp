#ifndef _Gen
#define _Gen
#include <cassert>
#include "Cell.hpp"
class Gen: public Cell
{
protected:
  int NLin; /*! Grid Height; */
  int NCol; /*! Grid Width; */
  Cell ** Grid;
public:
  Gen (int nLin, int nCol);
  ~Gen();


  int NeighborsCount(int Line,int Col);
  void CellBirth(int Line,int Col);
  void Print();
  bool Status(int Line, int Col); /*! Deprecated for now */
  Cell& operator()(int Line, int Col);/*! Returns Grid[i][j] using tuples (i,j) */
  Gen& operator=(const Gen& rhs);
};

#endif


