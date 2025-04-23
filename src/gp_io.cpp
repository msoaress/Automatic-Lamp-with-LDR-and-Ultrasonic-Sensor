#include <arduino.h> // importação de biblioteca padrão do arduino


#include "gp_io.h" // importação ou link com o arquivo headle gp_io.h


class gp_io {  // definição da classe

    private:  // privado
    int gp_io_di; // criação do atributo



    public: // publico

    // obs: atributos privados so tera acesso ultilizado os metodos set e get acrercidos do nome de sua classe

    void setgp_io(int gpio) {  // metodo publico set para alteração ou definição do valor em gp_io_di
        gp_io_di = gpio;   // atribui  um valor a gp_io_di
    }


    int getgp_io() {  // metodo publico get para exibir o valor armazenado em gp_io_di

        return gp_io_di;  // retorna o valor ou seja a gpio atribuida
    }


    uint8_t nivel_alt = HIGH; // uint8_t: "unsigned interge 8 bits type", nivel_alt recebe higth que e 1
    uint8_t nivel_bai = LOW;  // uint8_t: "unsigned interge 8 bits type", nivel_bai recebe low que e 0



};