#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "projetil.hpp"
#include <list>

class ProjetilHandler {
public:
    // Adiciona um projétil à lista de projéteis ativos
    void adicionarProjetil(Projetil* projetil);

    // Remove um projétil da lista de projéteis ativos
    void removerProjetil(Projetil* projetil);

    // Atualiza todos os projéteis ativos
    void atualizarProjeteis();

    // Verifica colisões entre projéteis e outros objetos de jogo
    void verificarColisoes(const std::list<ObjetoDeJogo*>& objetos);


    std::list<Projetil*>& getProjeteisAtivos() {
        return projeteisAtivos; // Retorna uma referência não constante
    }
private:
    std::list<Projetil*> projeteisAtivos;

    // Métodos auxiliares com tipo de retorno bool explicitamente declarado
    bool foraDaTela(Projetil* projetil);
};

#endif