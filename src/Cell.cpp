#include "Cell.hpp"

Cell::Cell ()
{
	alive = false;
}

bool Cell::Status() /*!< Indicates if a cell is alive or not */

{
  return alive;
}

Cell& Cell::operator=(bool i)
{
  alive = i;
  return *this;
}

