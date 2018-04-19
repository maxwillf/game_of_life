#include "Gen.hpp"
#include <iostream>
#include <vector>
void Update(std::vector <Gen> &Game)
{
  int count;
  int index = Game.size()-1;
  Gen dump(Game[index].Linhas(),Game[index].Colunas());
  Game.push_back(dump);
  for (int i = 0; i < Game[index].Linhas(); ++i) {
    for (int j = 0; j < Game[index].Colunas(); ++j) {

      count = Game[index].NeighborsCount(i,j);

      if(Game[index](i,j)){
        if(count < 2 or count > 3){
          Game[index +1 ].Death(i,j);
        }
      }
      else if(count == 3) {
        Game[index +1 ].Birth(i,j);

      }
    }

  }

}


int main(int argc, char *argv[])
{
  Gen dump(8,8);
  // Try[0].Print();
  std::vector<Gen> Try;
  Try.push_back(dump);
  Try[0].Birth(2, 2);
  Try[0].Birth(2, 4);
  Try[0].Birth(3, 2);
  Try[0].Birth(3, 3);
  Try[0].Birth(3, 4);
  Try[0].Birth(4, 2);
  Try[0].Birth(4, 4);
  Update(Try);
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if(Try[0](i,j) > 0){
        std::cout << "i " << i << " j " << j << " Neighbors: " << Try[0].NeighborsCount(i,j) << std::endl;
      }
    }

  }

  Try[0].Print();
  Try[1].Print();
  return 0;
}
