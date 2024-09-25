#ifndef PROJETIL_HPP
#define PROJETIL_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Projetil : public ObjetoDeJogo {
public:
    enum class Direcao {
        CIMA,
        BAIXO,
        ESQUERDA,
        DIREITA
    };

    // Construtor da classe base
    Projetil(const ObjetoDeJogo& obj, int velocidade, Direcao direcao) 
        : ObjetoDeJogo(obj), velocidade(velocidade), direcao(direcao) {}

    // Destrutor virtual 
    virtual ~Projetil() {}

    // Sobrescreve o método update da classe base para mover o projétil
    void update() override;


protected:
    int velocidade;
    Direcao direcao; // Direção do movimento
};

#endif