#include "inimigo.hpp"

Enemy::Enemy(const ObjetoDeJogo& obj, int life, int velAtaque)
    : ObjetoDeJogo(obj), life(life), velAtaque(velAtaque), contAtaque(velAtaque) {}

bool Enemy::isAlive() const {
    return life != 0;
}

void Enemy::sofrerAtaque(int ataque) {
    life = (life - ataque >= 0) ? (life - ataque) : 0;
}

int Enemy::atacar() {
    if (--contAtaque == 0) {
        contAtaque = velAtaque;
        return 10;
    }
    return 0;
}

bool Enemy::getDirecao() const {
    return direcao;
}

void Enemy::setDirecao(bool novaDirecao) {
    direcao = novaDirecao;
}

bool Enemy::dropPowerUp() const {

    int numeroAleatorio = rand() % 100;

    return numeroAleatorio < 25;
}

void Enemy::update() {
    if (direcao) { // Movendo para baixo
        setPosL(getPosL() + 1);
        if (getPosL() >= 70) {
            direcao = false; // Inverte a direção
        }
    } else { // Movendo para cima
        setPosL(getPosL() - 1);
        if (getPosL() <= 5) {
            direcao = true; // Inverte a direção
        }
    }
}