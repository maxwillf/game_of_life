#include "Life.hpp"

Life::Life(int NLin, int NCol)
{
	Lifespan.push_back(Gen(NLin,NCol));
}

Life::~Life()
{
 delete [] Lifespan;
}

