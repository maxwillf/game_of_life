#ifndef _Gen
#define _Gen
#include <cassert>
class Gen
{
protected:
  int NLin; /*! Grid Height; */
  int NCol; /*! Grid Width; */
  bool ** Grid;
public:
  Gen (int nLin, int nCol);
  Gen(const Gen &gen);
  ~Gen();


  int NeighborsCount(int Line,int Col);
  int Linhas(){ return NLin; };
  int Colunas(){ return NCol; };
  void Birth(int Line,int Col);
  void Death(int Line, int Col);
  void Print();
  bool Status(int Line, int Col); /*! Deprecated for now */
  bool Extinct();
  bool operator()(int Line, int Col);/*! Returns Grid[i][j] using tuples (i,j) */
  Gen& operator=(const Gen& rhs);
  bool operator ==(const Gen & rhs);
};

#endif


