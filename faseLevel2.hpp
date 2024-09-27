#ifndef FASELEVEL2_HPP
#define FASELEVEL2_HPP

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>
#include "meteoro.hpp"
#include "player.hpp"

class FaseLevel2 : public Fase {
public:
    FaseLevel2(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
   

    virtual ~FaseLevel2() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

private:
    Player *player;
    TextSprite *life;
    std::list<ObjetoDeJogo*> colisoes;
    std::list<Meteoro*> meteoros;
    int MeteorosApagados;
};

#endif 