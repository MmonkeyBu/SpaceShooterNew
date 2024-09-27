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


    Projetil(const ObjetoDeJogo& obj, int velocidade, Direcao direcao) 
        : ObjetoDeJogo(obj), velocidade(velocidade), direcao(direcao) {}

    virtual ~Projetil() {}

    void update() override;


protected:
    int velocidade;
    Direcao direcao; 
};

#endif