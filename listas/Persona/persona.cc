#include"persona.h"
bool Persona::operator == (Persona *p2)
{
    return numeroDocumento == p2->getNumeroDocumento();
}

bool Persona::operator >(Persona *p2)
{
    return numeroDocumento > p2->getNumeroDocumento();
}
