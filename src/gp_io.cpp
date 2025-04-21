#include <arduino.h>


#include "gp_io.h"


class gp_io {

    private:
    int gp_io_di;



    public:
    void setgp_io(int gpio) {
        gp_io_di = gpio;
    }


    int getgp_io() {

        return gp_io_di;
    }


    uint8_t nivel_alt = HIGH;
    uint8_t nivel_bai = LOW;



};