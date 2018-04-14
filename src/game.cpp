#include "../Includes/Life.hpp"
int main(int argc, char *argv[])
{
  Life Try (8,8);
  Try.CellBirth(2, 1);
  Try.CellBirth(1, 2);
  std::cout << "Teste " << Try.NeighborsCount(2,2)<< std::endl;
  return 0;
}
