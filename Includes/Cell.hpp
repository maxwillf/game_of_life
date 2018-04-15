#ifndef _Cell
#define _Cell
typedef struct Alive{
  int Line;
  int Col;
}Alive;

class Cell
{
protected:
  bool alive;
public:
  Cell();
  bool Status();/*!< Indicates if a cell is alive or not */
  Cell & operator=(bool i);
};

#endif
