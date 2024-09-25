#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "ASCII_Engine\ObjetoDeJogo.hpp"
#include <cstdlib> // Para usar rand e srand
#include <ctime>   // Para usar time

class Enemy : public ObjetoDeJogo {
public:
    Enemy(const ObjetoDeJogo& obj, int life = 30, int velAtaque = 3);

    virtual ~Enemy() {}

    bool isAlive() const;

    void sofrerAtaque(int ataque);

    int atacar();

    bool getDirecao() const;

    void setDirecao(bool novaDirecao);

    bool dropPowerUp() const;

    // Declaração do método update()
    void update() override;

private:
    int life;
    int velAtaque, contAtaque;
    bool direcao; // true para baixo, false para cima
    int posicaoInicialL;
    // int limiteInferior;
};

#endif // ENEMY_HPP