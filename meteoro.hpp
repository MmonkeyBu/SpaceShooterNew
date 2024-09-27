#ifndef METEORO_HPP
#define METEORO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"  
#include "Handler.hpp"            
#include "inimigo.hpp"                    


class Meteoro : public ObjetoDeJogo{
public:

	Meteoro(const ObjetoDeJogo &obj, int dano = 50)
		: ObjetoDeJogo(obj), dano(dano) {}
	
	int posL = getPosL();

    int getDano() const { return dano; }
	bool verificarForaDaTela();

	int atacar();
	
private:
    int dano;  
	int life;
};

#endif
