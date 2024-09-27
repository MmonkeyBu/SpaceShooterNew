#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ASCII_Engine\ObjetoDeJogo.hpp"
#include "meteoro.hpp"

class Player : public ObjetoDeJogo
{
public:
    Player(const ObjetoDeJogo &obj, int life = 100) : ObjetoDeJogo(obj), life(life), powerup(false) {}
    virtual ~Player() {}

    bool isAlive() const { return life != 0; }
    int getLife() const { return life; }

    void sofrerAtaque(int ataque) { 
        // Se o powerup estiver ativado, reduz metade do dano
        if (powerup) {
            ataque /= 2;
        }

        life = ((life - ataque >= 0) ? (life - ataque) : 0); 
    }

    int atacar() const {
        // Se o powerup estiver ativo, aumenta o dano
        return powerup ? 20 : 10;
    }

    void ativarPowerup() { powerup = true; }
    bool possuiPowerup() const { return powerup; }

    // Desativa o powerup após um certo uso (se for temporário)
    void desativarPowerup() { powerup = false; }


private:
    int life;
    bool powerup;
};

#endif
