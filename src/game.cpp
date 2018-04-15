#include "../Includes/Life.hpp"
int main(int argc, char *argv[])
{
  Life Try (8,8);
  Try.CellBirth(2, 2);
  Try.CellBirth(2, 4);
  Try.CellBirth(3, 2);
  Try.CellBirth(3, 3);
  Try.CellBirth(3, 4);
  Try.CellBirth(4, 2);
  Try.CellBirth(4, 4);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if(Try(i,j).Status() > 0){
        std::cout << "i " << i << " j " << j << " Neighbors: " << Try.NeighborsCount(i,j) << std::endl;
      }
    }

  }

  Try.Print();
  return 0;
}
