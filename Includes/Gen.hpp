#ifndef _Gen
#define _Gen
#include <cassert>
#include <iostream>
#include <fstream>
/*! A Class for all the methods and variables related to a single instance of the evolution */
class Gen
{
private:
  int NLin; /*!< Grid Height; */
  int NCol; /*!< Grid Width; */
  bool ** Grid;
public:
  Gen (int nLin, int nCol); /*!< Construtor */
  Gen(const Gen &gen); /*!< Copy Constructor */
  ~Gen();


  int NeighboursCount(int Line,int Col); /*!< Counts the numbers of neighbors for the current cell*/
  int Linhas(){ return NLin; };  /*!< returns the numbers of lines for the grid */
  int Colunas(){ return NCol; }; /*!< returns the numbers of columns for the grid */
  void Birth(int Line,int Col);  /*!< The Cell in the [Line][Col] index is born */
  void Death(int Line, int Col); /*!< The Cell in the [Line][Col] index dies */
  void Print(std::ostream &out = std::cout, char alive= '*',char lines = '_'); /*!< Prints current generation
																				 to a file, or to std::cout
																				 (default); */
  bool Extinct(); /*!< Checks if current generation is extinct */
  bool operator()(int Line, int Col);/*!< Returns Grid[i][j] using tuples (i,j) */
  Gen& operator=(const Gen& rhs); /*!< Assignement operator overload */
  bool operator ==(const Gen & rhs); /*!< Equality operator overload */
};

#endif


