#ifndef FASELEVELFINAL_HPP
#define FASELEVELFINAL_HPP
#include <string>
#include <list>
#include <conio.h>
#include "ASCII_Engine/Fase.hpp"
#include "player.hpp"

class FaseLevel4 : public Fase {
public:
    FaseLevel4(std::string name, const Sprite &bkg) : Fase(name,bkg) {}

    virtual ~FaseLevel4() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);
private:
    TextSprite *Mensagemfinal;
    Player *player;
};

#endif 