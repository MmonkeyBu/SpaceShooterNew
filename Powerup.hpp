#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "ObjetoDeJogo.hpp" 
#include "player.hpp"

class PowerUp : public ObjetoDeJogo {
public:
    // Destrutor virtual puro para garantir que as subclasses implementem seus próprios destrutores
    virtual ~PowerUp() = 0; 

    // Método virtual puro para aplicar o efeito do power-up no herói
    virtual void aplicarEfeito(Player& Player) const = 0; 

protected:
    // Construtor da classe base
    PowerUp(const ObjetoDeJogo& obj, int duracao) : ObjetoDeJogo(obj), duracao(duracao) {}

    // Duração do efeito do power-up
    int duracao; 
};

class Escudo : public PowerUp {
public:
    Escudo(const ObjetoDeJogo& obj, int duracao) : PowerUp(obj, duracao) {}

    // Implementação do efeito do escudo
    void aplicarEfeito(Player& Player) const override {
        // Lógica para ativar o escudo no herói (por exemplo, reduzir o dano recebido por um tempo)
    }
};

class MelhoriaTiro : public PowerUp {
public:
    MelhoriaTiro(const ObjetoDeJogo& obj, int duracao) : PowerUp(obj, duracao) {}

    // Implementação do efeito da melhoria de tiro
    void aplicarEfeito(Player& Player) const override {
        // Lógica para melhorar o tiro do herói (por exemplo, aumentar o dano ou a cadência de tiro)
    }
};

#endif // POWERUP_HPP