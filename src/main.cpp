#include "Gen.hpp"
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>


int Stable(std::vector <Gen> &Game);
void Update(std::vector <Gen> &Game);
Gen input(std::string filename);

int main(int argc, char *argv[])
{
	if (argc != 2){
	std::cout << "Please execute it like this : ./game input.dat " << std::endl;
	} 
	std::vector<Gen> Life;
	Gen gen1 = input(argv[1]);
	Life.push_back(gen1);
	std::ofstream ofs("historico.txt");
	int linha, coluna;

	int i = 0;
	std::string entry_dump;
	system("clear");
	Life[i].Print();
	i++;
	Update(Life);
	std::cout << "Wanna see the next generation? press y. Or n if you don't" << std::endl;
	while(std::cin >> entry_dump){

   		if(entry_dump[0] == 'n' or entry_dump[0] == 'N')
		{
			return 0;	
		}
		else{
			system("clear");
			Life[i].Print();
			Life[i].Print(ofs);

			if((Life[i].Extinct())){
				std::cout << "Extinct at Generation " << i+1 << std::endl;
				break;
			}
			int stability = Stable(Life);
   
   			if(stability >= 0){
				std::cout <<" Stable from Generation " << stability<< " To Generation "<<i << std::endl;
				break;
			}

		i++;
		Update(Life);
		std::cout << "Wanna see the next generation? press y. Or n if you don't" << std::endl;
		std::cout << std::endl;
		}
	}
  return 0;
}

/*! Atualiza a configuraçao para a proxima geraçao conforme as regras do jogo */
void Update(std::vector <Gen> &Game) 
{
	int count;
	int index = Game.size()-1;
	Gen dump(Game[index].Linhas(),Game[index].Colunas());
	Game.push_back(dump);
	for (int i = 0; i < Game[index].Linhas(); ++i) {
		for (int j = 0; j < Game[index].Colunas(); ++j) {

			count = Game[index].NeighboursCount(i,j);

			if(Game[index](i,j)){
				if(count < 2 or count > 3){
					continue; /* As celulas que morreram nesta geração
								 simplesmente não nascerão na próxima*/
				}
				else if(Game[index](i,j)){
					Game[index +1].Birth(i,j); /* as celulas que não morreram
												  permanecem vivas */
				}
			}
			else if(count == 3) {
				Game[index +1 ].Birth(i,j);

			}
		}

	}

}

/*! retorna a frequência do ciclo de estabilidade, ou -1 caso não seja estável */

int Stable(std::vector <Gen> &Game) {
	for (int i = 0; i < Game.size()-1; ++i) {
		if(Game[i] == Game.back()){
			return i+1;
		}
	}
	return -1;
}

/*! Initializes a <Gen> object according to a input file
 *\param std::string filename : Receives the .dat filename
 */
Gen input(std::string filename)
{
	std::ifstream ifs(filename);
	std::string line;
	int Lin,Col;
	int line_index = 0;
	int col_index = 0;
	char alive;	
	char temp_cell;
	std::getline(ifs,line);
	std::stringstream temp(line);
	temp >> Lin >> Col;
	std::cout << Lin << Col << std::endl;
	Gen temp_gen = Gen(Lin,Col);
	while(std::getline(ifs,line)){
	
		std::stringstream temp2(line);
		if(line_index == 0){

			temp2 >> alive;
		}
		else {

			while(temp2 >> temp_cell){
			//	std::cout << col_index << "  " << line_index << std::endl;
				if(temp_cell == alive){
					temp_gen.Birth(line_index-1,col_index);
				}
				col_index++;
			}
			col_index = 0;
		}
		line_index++;
	}
	return temp_gen;
}

