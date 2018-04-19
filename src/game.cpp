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

      /* std::cout << "I: "<< i << std::endl;
         std::cout << "J: " << j << std::endl; */
      count = Game[index].NeighborsCount(i,j);

      if(Game[index](i,j)){
        if(count < 2 or count > 3){
          Game[index +1 ].Death(i,j);
        }
        else if(Game[index](i,j)){
          Game[index +1].Birth(i,j); /* as celulas que não morreram permanecem vivas */
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
  std::vector<Gen> Try;
  Try.push_back(dump);
  Try[0].Birth(2, 2);
  Try[0].Birth(2, 4);
  Try[0].Birth(3, 2);
  Try[0].Birth(3, 3);
  Try[0].Birth(3, 4);
  Try[0].Birth(4, 2);
  Try[0].Birth(4, 4);
  // Update(Try);
  /* for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if(Try[0](i,j) > 0){
        std::cout << "i " << i << " j " << j << " Neighbors: " << Try[0].NeighborsCount(i,j) << std::endl;
      }
    }
    } */
  int i = 0;
  std::string entry_dump;
  Try[i].Print();
  i++;
  Update(Try);
  std::cout << "See the next generation? press y" << std::endl;
  while(std::cin >> entry_dump){

    if((Try[i].Extinct())){
      std::cout << "Extinct at Generation " << i+1 << std::endl;
      break;
    }
    Try[i].Print();
    i++;
    Update(Try);
    std::cout << "See the next generation? press y" << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
