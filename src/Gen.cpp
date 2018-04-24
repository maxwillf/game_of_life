#include "Gen.hpp"
/*! Construtor
 * \param int nLin : The number of lines in the Grid 
 * \param int nCol : The number of columns in the Grid 
  */
Gen::Gen (int nLin, int nCol)
{
	assert(nLin >= 0);
	assert(nCol >= 0);
	NLin = nLin;
	NCol = nCol;

	Grid = new bool *[nLin];

	for (int i = 0; i < nLin; ++i) {
		Grid[i] = new bool[nCol];
	}

	for (int i = 0; i < NLin; ++i) {
		for (int j = 0; j < NCol; ++j) {
			Grid[i][j]  = false;
		}
	}
}

/*! Copy Constructor
 * \param const Gen &gen : The object to be copied
 * */
Gen::Gen(const Gen &gen)
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
/*! The Class Destructor */
Gen::~Gen()  
{
	for (int i = 0; i < NLin; ++i) {
		delete [] Grid[i];
	}
	delete [] Grid;
}
/*! Neighbours Counter
 * \param int Line: The number of lines in the Grid 
 * \param int Col: The number of columns in the Grid 
  */
int Gen::NeighboursCount(int Line,int Col)
{
	int count = 0;

	for (int i = -1; i <=1; ++i) {
		for (int j = -1; j <=1; ++j) {
			if(( Line+i < NLin and Col+j < NCol  ) and (Line+i >= 0 and Col+j >= 0)){
				if(!(i == 0 and j == 0)){
					count += Grid[Line+i][Col+j];
				}
			}
		}

	}
	return count;
}
/*! Cell Birth
 * \param int Line: The horizontal position of the cell that is going to be born
 * \param int Col: The vertical position of the cell that is going to be born
  */                                   
void Gen::Birth(int Line,int Col)
{
	Grid[Line][Col] = true;
}
/*! Cell Death
 *\param int Line: The horizontal position of the cell that is going to die
 *\param int Col: The vertical position of the cell that is going to die
  */                                                                   
void Gen::Death(int Line, int Col)
{
	Grid[Line][Col] = false;
}
/*! Operator () overload, returns Grid[i][j]
 * \param int Line: The number of lines in the Grid 
 * \param int Col: The number of lines in the Grid 
  */                                                
bool Gen::operator()(int Line, int Col)
{
	assert(Line >= 0 && Line < NLin);
	assert(Col >= 0 && Col < NCol);
	return Grid[Line][Col];
}
/*! Assignment operator overload
 * \param Const Gen &rhs: A <Gen> class variable to be assigned
 * */
Gen& Gen::operator=(const Gen &rhs)
{
	for (int i = 0; i < NLin; ++i) {
		for (int j = 0; j < NCol; ++j) {
			Grid[i][j] = rhs.Grid[i][j];
		}
	}
	return *this;
}
/*! Equality operator overload
 * Compares if the two object's Grids are the same
 *\param Const Gen &rhs: Object to be compared
 */

bool Gen::operator ==(const Gen & rhs)
{
	for(int i = 0; i < NLin; i++){
		for(int j = 0; j < NCol; j++){
			if (Grid[i][j] != rhs.Grid[i][j]){
				return false;
			}
		}
	}
	return true;
}
/*! Generation Print method
 * \param std::ostream &out: File to print the step (defauls to std::cout)
 * \param char alive: symbol to represent living cells
 * \param char lives: symbol to represent dead cells
  */
void Gen::Print(std::ostream &out, char alive, char lines)
{
	for (int i = 0; i < NLin; ++i) {
		for (int j = 0; j < NCol; ++j) {
			if ( Grid[i][j] == 1 ){
				out << alive;
			}
			else {
				out << lines;
			}
		}
		out << std::endl;
	}
	out << std::endl;
}
/*! Extinction Checker
 *	if all cells are dead, it's extinct.
 * */
bool Gen::Extinct()
{
	for (int i = 0; i < NLin; ++i) {
		for (int j = 0; j < NCol; ++j) {
			if(Grid[i][j]){
				return false;
			}	
		}
	}
	return true;
}
