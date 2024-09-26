#ifndef GAME_HPP
#define GAME_HPP

#include "FaseLevel1.hpp"
#include "faseLevel2.hpp"
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
		
		buffer.clear();
		fase1.init();

		int ret1 = fase1.run(buffer);

		if (ret1 == Fase::END_FASE) {
			std::cout << "Passou de fase!" << std::endl;
			buffer.clear();
			fase2.init();
			fase2.run(buffer);
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
