#include "Projetil.hpp"

void Projetil::update() {

    if (direcao == Direcao::CIMA) {
        
        setPosL(getPosL() - velocidade);
    } else if (direcao == Direcao::BAIXO) {
        setPosL(getPosL() + velocidade);
    }
    
}
