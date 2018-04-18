#include "Cell.hpp"
#include "Gen.hpp"
#include <iostream>
Gen::Gen (int nLin, int nCol)
  {

    NLin = nLin;
    NCol = nCol;

    Grid = new bool *[nLin];

    for (int i = 0; i < nLin; ++i) {
      Grid[i] = new bool[nCol];
    }

    Grid = {0};
    for (int i = 0; i < NLin; ++i) {
      for (int j = 0; j < NCol; ++j) {
       Grid[i][j]  = false;
      }
    }
    for (int i = 0; i < NLin; ++i) {
      for (int j = 0; j < NCol; ++j) {
        std::cout << Grid[i][j] << std::endl;
      }
    }

  }

/*Gen::Gen(const Gen &gen)
{
 NLin = gen.NLin;
 NCol = gen.NCol;

 Grid = new bool *[gen.NLin];

 for (int i = 0; i < gen.NLin; ++i) {
   Grid[i] = new bool[gen.NCol];
 }

 for (int i = 0; i < gen.NLin; ++i) {
	 for (int j = 0; j < gen.NCol; ++j) {
     Grid[i][j] = gen.Grid[i][j];
	 }
 }
}
*/
Gen::~Gen()
  {
	for (int i = 0; i < NLin; ++i) {
		delete [] Grid[i];
	}
	delete [] Grid;
  }

int Gen::NeighborsCount(int Line,int Col)
  {
    int count = 0;

    for (int i = -1; i <=1; ++i) {
      for (int j = -1; j <=1; ++j) {
        if(( Line+i < NLin and Col+j < NCol  ) and (Line+i > 0 and Col+j > 0)){
          if(!(i == 0 and j == 0)){
          count += Grid[Line+i][Col+j];
          }
        }
      }

    }
    return count;
  }

void Gen::Birth(int Line,int Col)
  {
    Grid[Line][Col] = true;
  }
void Gen::Death(int Line, int Col)
{
  Grid[Line][Col] = false;
}
/*bool Gen::Status(int Line, int Col) Deprecated probably
{
  return Grid[Line][Col];
  }*/

bool Gen::operator()(int Line, int Col)
{
  assert(Line >= 0 && Line < NLin);
  assert(Col >= 0 && Col < NCol);
  return Grid[Line][Col];
}
void Gen::Print()
{

  for (int i = 0; i < NLin; ++i) {
    for (int j = 0; j < NCol; ++j) {

    if ( Grid[i][j] == 1 ){
        std::cout << "*";
      }
      else {
        std::cout << "_";
      }
    }
    std::cout << std::endl;
    }

}

Gen& Gen::operator=(const Gen &rhs)
{
  for (int i = 0; i < NLin; ++i) {
    for (int j = 0; j < NCol; ++j) {
      Grid[i][j] = rhs.Grid[i][j];
    }

  }

}
