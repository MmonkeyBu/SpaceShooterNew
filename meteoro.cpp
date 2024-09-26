#include "meteoro.hpp"

bool Meteoro::verificarForaDaTela() { 
    int posL = this->getPosL();  
    if (posL > 80) {  
        this->desativarObj();  
        return true;  
    }

    return false; 
}

int Meteoro::atacar() {
        return 50;
}