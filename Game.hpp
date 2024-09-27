#ifndef GAME_HPP
#define GAME_HPP

#include "faseLevel1.hpp"
#include "faseLevel2.hpp"
#include "faseLevel3.hpp"
#include "fasefinal.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(220,80);
		FaseLevel1 fase1("Fase1",Sprite("rsc/fase2.img"));
		FaseLevel2 fase2("Fase2",Sprite("rsc/fase3.img"));
		FaseLevel3 fase3("Fase3",Sprite("rsc/fase2.img"));
		FaseLevel4 fase4("Fase4",Sprite("rsc/decolando_3.img"));
		
		buffer.clear();
		fase1.init();

		int ret1 = fase1.run(buffer);

		if (ret1 == Fase::END_FASE) {
			std::cout << "Passou de fase!" << std::endl;
			buffer.clear();
			fase2.init();

			int ret2 = fase2.run(buffer);
			if(ret2 == Fase::END_FASE){
				std::cout << "Passou de fase!" << std::endl;
				buffer.clear();
				fase3.init();

				int ret3 = fase3.run(buffer); 
				if(ret3 == Fase::END_FASE){
					std::cout << "Passou de fase!" << std::endl;
					buffer.clear();
					fase4.init();
					
					int ret4 = fase4.run(buffer); 
				}
				if (ret3 == Fase::GAME_OVER) {
				std::cout << "VOCE PERDEU..." << std::endl;
			} 

			if (ret3 == Fase::QUIT_GAME) {
				std::cout << "Saindo..." << std::endl;
			}
		
			}
			if (ret2 == Fase::GAME_OVER) {
				std::cout << "VOCE PERDEU..." << std::endl;
			} 

			if (ret2 == Fase::QUIT_GAME) {
				std::cout << "Saindo..." << std::endl;
			}
		}

		if (ret1 == Fase::GAME_OVER) {
			std::cout << "VOCE PERDEU..." << std::endl;
		} 

		if (ret1 == Fase::QUIT_GAME) {
			std::cout << "Saindo..." << std::endl;
		}
	}
};

#endif // GAME_HPP
