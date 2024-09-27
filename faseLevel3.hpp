#ifndef FASELEVEL3_HPP
#define FASELEVEL3_HPP

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>
#include "inimigo.hpp"
#include "player.hpp"
#include "boss.hpp"

class FaseLevel3 : public Fase {
public:
    FaseLevel3(std::string name, const Sprite &bkg) : Fase(name,bkg) {}

    virtual ~FaseLevel3() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

private:
    Player *player;
    TextSprite *life;
    Boss *boss;
    ProjetilHandler handlerProjeteis;
    std::list<ObjetoDeJogo*> colisoes;
    int ataqueEspecialCooldown;
};

#endif 