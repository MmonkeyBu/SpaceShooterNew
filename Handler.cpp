#include "Handler.hpp"

void ProjetilHandler::adicionarProjetil(Projetil* projetil) {
    projeteisAtivos.push_back(projetil);
}

void ProjetilHandler::removerProjetil(Projetil* projetil) {
    projetil->desativarObj();
    projeteisAtivos.remove(projetil);
    delete projetil; // liberar a memória!
}

void ProjetilHandler::atualizarProjeteis() {
    for (auto it = projeteisAtivos.begin(); it != projeteisAtivos.end(); ) {
        (*it)->update();

        // Verificar se o projétil saiu da tela ou atingiu seu tempo de vida (se aplicável)
        if (foraDaTela(*it)) {
            it = projeteisAtivos.erase(it); 
        } else {
            ++it;
        }
    }
}

void ProjetilHandler::verificarColisoes(const std::list<ObjetoDeJogo*>& objetos) {
    for (auto itProj = projeteisAtivos.begin(); itProj != projeteisAtivos.end(); ) {
        bool colidiu = false;

        for (auto objeto : objetos) {
            if ((*itProj)->colideCom(*objeto)) {

                (*itProj)->desativarObj();

                colidiu = true; 
                break; 
            }
        }

        // Se colidiu, remover o projétil da lista
        if (colidiu) {
            itProj = projeteisAtivos.erase(itProj); // Remove o projétil da lista
        } else {
            ++itProj; // Avança para o próximo projétil
        }
    }
}

bool ProjetilHandler::foraDaTela(Projetil* projetil) {
    int posL = projetil->getPosL();

    if (posL < 4 || posL > 80) {
        projetil->desativarObj();
        return true; // Projétil está fora dos limites
    }

    return false; // Projétil ainda está dentro da tela
}
