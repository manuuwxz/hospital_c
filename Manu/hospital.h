#ifndef HOSPITAL_H
#define HOSPITAL_H

// tamanho maximo é 10, vai de 0 a 9
#define max 10

// cadastro dos pacientes
struct Paciente
{
    char nome[50];
    int idade;
    int gravidade;
    int tipo;
};

#endif