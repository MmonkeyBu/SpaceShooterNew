#ifndef BOSS_HPP
#define BOSS_HPP

#include "inimigo.hpp"

enum class Direcao {
    CIMA,
    BAIXO,
    ESQUERDA,
    DIREITA
};

class Boss : public Enemy {
public:
    Boss(const ObjetoDeJogo& obj, int life = 100, int velAtaque = 2);

    ~Boss() override {}

    int atacar() override;

    void update() override;

    bool dropPowerUp() const;

private:
    int ataqueEspecialCooldown; // Tempo para o ataque especial
    Direcao direcaoMovimento;   // Direção do movimento
};

#endif // BOSS_HPP
