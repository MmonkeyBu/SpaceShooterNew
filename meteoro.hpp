#ifndef METEORO_HPP
#define METEORO_HPP

#include "ASCII_Engine\ObjetoDeJogo.hpp"

class Meteoro : public ObjetoDeJogo
{
public:
	Meteoro(const ObjetoDeJogo &obj, int dano = 50) : ObjetoDeJogo(obj) {}
	virtual ~Meteoro()	{}
	
     int getDano() const { return dano; }

private:
	bool open;
    int dano;
};

#endif
