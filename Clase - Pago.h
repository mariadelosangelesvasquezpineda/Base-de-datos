#pragma once
#include <iostream>

class Pago {
protected:
    float monto;

public:
    Pago(float monto);

    virtual void procesarPago() = 0;
};

class PagoEnEfectivo : public Pago {
private:
    float cambio;

public:
    PagoEnEfectivo(float monto, float cambio);

    void procesarPago() override;
};

class PagoConTarjeta : public Pago {
private:
    char numeroTarjeta[17];
    char tipo[10];

public:
    PagoConTarjeta(float monto, const char* numeroTarjeta, const char* tipo);

    void procesarPago() override;
};

