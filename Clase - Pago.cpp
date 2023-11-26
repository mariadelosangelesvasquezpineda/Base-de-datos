#include "Clase - Pago.h"
#include <iostream>
#include <cstring>

Pago::Pago(float monto) : monto(monto) {}

PagoEnEfectivo::PagoEnEfectivo(float monto, float cambio) : Pago(monto), cambio(cambio) {}

void PagoEnEfectivo::procesarPago() {
    std::cout << "Pago en efectivo de " << monto << " procesado. Cambio: " << cambio << std::endl;
}

PagoConTarjeta::PagoConTarjeta(float monto, const char* numeroTarjeta, const char* tipo) : Pago(monto) {
    strcpy(this->numeroTarjeta, numeroTarjeta);
    strcpy(this->tipo, tipo);
}

void PagoConTarjeta::procesarPago() {
    std::cout << "Pago con tarjeta de " << monto << " procesado. Tarjeta: " << numeroTarjeta << ", Tipo: " << tipo << std::endl;
}
