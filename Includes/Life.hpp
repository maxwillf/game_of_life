#ifndef _Life
#define _Life

#include "Gen.hpp"
#include <vector>
class Life: public Gen
{
	private:
	std::vector <Gen> Lifespan;/*! vector of all generations */

	public:
	Life(int Nlin, int NCol);
	//Life(Gen &gen);
	~Life();


};
#endif
