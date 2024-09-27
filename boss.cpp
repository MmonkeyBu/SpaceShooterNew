#include "boss.hpp"
#include <iostream>

Boss::Boss(const ObjetoDeJogo& obj, int life, int velAtaque)
    : Enemy(obj, life, velAtaque), ataqueEspecialCooldown(10) {
    // Inicializa a direção aleatoriamente
    direcaoMovimento = static_cast<Direcao>(rand() % 4); // CIMA, BAIXO, ESQUERDA ou DIREITA
}

int Boss::atacar() {
    if (--contAtaque == 0) {
        contAtaque = velAtaque;
        return 30; // Ataque do Boss causa mais dano
    }
    return 0;
}

void Boss::update() {
    // Mover na direção atual
direcaoMovimento = static_cast<Direcao>(rand() % 4); // Aleatoriamente seleciona uma direção
    switch (direcaoMovimento) {
        case Direcao::CIMA:
            setPosL(getPosL() - 2); 
            if (getPosL() <= 3) { 
                setPosL(5); 
                direcaoMovimento = Direcao::BAIXO; 
            }
            break;

        case Direcao::BAIXO:
            setPosL(getPosL() + 2); 
            if (getPosL() >= 45) { 
                setPosL(45); 
                direcaoMovimento = Direcao::CIMA; 
            }
            break;

        case Direcao::ESQUERDA:
            setPosC(getPosC() - 2); 
            if (getPosC() <= 0) {
                setPosC(0); 
                direcaoMovimento = Direcao::DIREITA; 
            }
            break;

        case Direcao::DIREITA:
            setPosC(getPosC() + 2); 
            if (getPosC() >= 200) { 
                setPosC(80); 
                direcaoMovimento = Direcao::ESQUERDA; 
            }
            break;
    }

}

bool Boss::dropPowerUp() const {
    int numeroAleatorio = rand() % 100;
    return numeroAleatorio < 50; 
}
