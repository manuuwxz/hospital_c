#ifndef HOSPITAL_H
#define HOSPITAL_H

#define MAX_PILHA 100
#define MAX_FILA 100
#define MAX_CIRCULAR 8

typedef struct{
        char nome[50];
        int idade;
        int gravidade;
        int tipo;
    }Paciente;

void CadastrarPaciente();
void AtenderEmergencia();
void AtenderConsulta();
void AtenderExame();
void AtenderPaciente();
void TransferirPaciente();
void ExibirPaciente();
void Relatorios();
void limparBuffer();

#endif 