#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "projetil.hpp"
#include <list>

class ProjetilHandler {
public:

    void adicionarProjetil(Projetil* projetil);


    void removerProjetil(Projetil* projetil);


    void atualizarProjeteis();


    void verificarColisoes(const std::list<ObjetoDeJogo*>& objetos);


    std::list<Projetil*>& getProjeteisAtivos() {
        return projeteisAtivos; 
    }
private:
    std::list<Projetil*> projeteisAtivos;

    virtual bool foraDaTela(Projetil* projetil);
};

#endif