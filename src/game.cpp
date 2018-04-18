#include "Gen.hpp"
#include <iostream>
#include <vector>
void Update(std::vector <Gen> Game, int Gen_number )
{
  int count;
  Gen dump(Game[Gen_number].Linhas(),Game[Gen_number].Colunas());
  Game.push_back(dump);
  for (int i = 0; i < Game[Gen_number].Linhas(); ++i) {
    for (int j = 0; j < Game[Gen_number].Colunas(); ++j) {

      count = Game[Gen_number].NeighborsCount(i,j);

      if(Game[Gen_number](i,j)){
        if(count < 2 or count > 3){
          Game[Gen_number +1 ].Death(i,j);
        }
      }
      else if(count == 3) {
        Game[Gen_number +1 ].Birth(i,j);

      }
    }

  }

}


int main(int argc, char *argv[])
{
   Gen dump(8,8);
  // dump.Print();
  std::vector<Gen> Try;
  //  Try.push_back(dump);
  dump;
  dump.Birth(2, 2);
  dump.Birth(2, 4);
  dump.Birth(3, 2);
  dump.Birth(3, 3);
  dump.Birth(3, 4);
  dump.Birth(4, 2);
  dump.Birth(4, 4);
//  Gen dump2 = dump;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if(dump(i,j) > 0){
        std::cout << "i " << i << " j " << j << " Neighbors: " << dump.NeighborsCount(i,j) << std::endl;
      }
    }

  }

  dump.Print();
  // Try[1].Print();
  return 0;
}
