#include "Projetil.hpp"

void Projetil::update() {
    // Verifica a direção do projétil e atualiza a posição
    if (direcao == Direcao::CIMA) {
        // Move o projétil para cima com a velocidade definida
        setPosL(getPosL() - velocidade);
    } else if (direcao == Direcao::BAIXO) {
        setPosL(getPosL() + velocidade);
    }
    // Outras direções, se houver, como esquerda/direita
}
