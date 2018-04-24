#ifndef _Gen
#define _Gen
#include <cassert>
#include <iostream>
#include <fstream>
/*! A Class for all the methods and variables related to a single instance of 
 * the evolution */
class Gen
{
private:
  int NLin; 
  int NCol; 
  bool ** Grid;
public:
  Gen (int nLin, int nCol);
  Gen(const Gen &gen);
  ~Gen();


  int NeighboursCount(int Line,int Col); 
  /*! returns the numbers of lines for the grid */
  int Linhas(){ return NLin; };
  /*! returns the numbers of columns for the grid */
  int Colunas(){ return NCol; }; 
  void Birth(int Line,int Col);  
  void Death(int Line, int Col); 
  void Print(std::ostream &out = std::cout, char alive= '*',char lines = '_');
  bool Extinct(); 
  bool operator()(int Line, int Col);
  Gen& operator=(const Gen& rhs); 
  bool operator ==(const Gen & rhs); 
};

#endif


