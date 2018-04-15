#ifndef _CLASSES
#define _CLASSES
#include <iostream>
#include <iterator>
#include <vector>
#include <cassert>

typedef struct Alive{
  int Line;
  int Col;
}Alive;

class Cell
{
protected:
  bool alive;
public:
  extern Cell();
  bool Status();/*!< Indicates if a cell is alive or not */
  Cell & operator=(bool i);
};

class Life: public Cell
{
protected:
  int NLin; /*! Grid Height; */
  int NCol; /*! Grid Width; */
  Cell ** Grid;
  //  std::vector <int> Alive_lin; /*! Line Index for Alive cells */
  //  std::vector <int> Alive_col; /*! Line Index for Alive cells */
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

//Class Generation: public Life
#endif


