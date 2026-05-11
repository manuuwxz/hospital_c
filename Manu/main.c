// bibliotecas pra usar o printf e scanf
#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"

// pilha (ultimo que entra, primeiro que sai)
struct Paciente emergencia[max];
int topo = -1; // ultimo paciente da pilha (-1 pq não entrou ninguem, quando entrar vira 0 e assim continua)

// fila (primeiro que entra, primeiro que sai)
struct Paciente consulta[max];
int inicio = 0;
int fim = -1;

// fila circular (quando chega no final, volta pro inicio)
struct Paciente exame[8];
int inicioExame = 0; // quem vai ser atendido
int fimExame = -1; // proximo paciente entra
int totalExame = 0; // total de pacientes

int main()
{
    int opcao = 0; // menu

    while(opcao != 6)
    {
        printf("\n MENU \n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Atender paciente\n");
        printf("3 - Mostrar pacientes\n");
        printf("4 - Transferir paciente\n");
        printf("5 - Relatorios\n");
        printf("6 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) // verifica qual posicao foi escolhida
        {
            case 1: // cadastrar paciente
            {
                struct Paciente p;

                printf("Digite seu nome: ");
                scanf("%s", p.nome); // guardando a informacao digitada

                printf("Digite sua idade: ");
                scanf("%d", &p.idade);

                printf("Qual e a gravidade? (1 - 5) ");
                scanf("%d", &p.gravidade);

                if (p.gravidade < 1 || p.gravidade > 5)
                {
                    printf("Gravidade invalida\n"); // se colocar 0 ou maior que 5 é invalida
                    break;
                }

                printf("Digite o tipo de atendimento: (1-Emergencia 2-Consulta 3-Exame)\n");
                scanf("%d", &p.tipo);

                if (p.tipo < 1 || p.tipo > 3)
                {
                    printf("Tipo invalido\n");
                    break;
                }

                printf("\nPaciente cadastrado!\n");

                printf("Nome: %s\n", p.nome); // mostra a informacao digitada
                printf("Idade: %d\n", p.idade);
                printf("Gravidade: %d\n", p.gravidade);
                printf("Tipo: %d\n", p.tipo);

                if (p.gravidade >= 4) // pacientes 4 e 5 vão para emergencia
                {
                    topo++; // proxima posicao na pilha

                    emergencia[topo] = p; // guarda o paciente na pilha

                    printf("Paciente foi para emergencia!\n");
                }

                else if (p.tipo == 2)
                {
                    fim++; // proxima posicao da fila

                    consulta[fim] = p; // guarda o paciente na fila

                    printf("Paciente foi para consulta!\n");
                }

                else if (p.tipo == 3)
                {
                    // fila cheia
                    if (totalExame == 8) // verifica se a fila ta cheia
                    {
                        printf("Fila de exame cheia!\n");
                        printf("Paciente mais antigo removido!\n");

                        inicioExame = (inicioExame + 1) % 8; // remove o mais antigo

                        totalExame--; // diminui quantidade
                    }

                    fimExame = (fimExame + 1) % 8; // proxima posicao

                    exame[fimExame] = p; // guarda paciente

                    totalExame++; // aumenta total

                    printf("Paciente foi para exame!\n");
                }

                break;
            }

            case 2: // atender paciente
            {
                int setor;

                printf("\n1 - Emergencia\n");
                printf("2 - Consulta\n");
                printf("3 - Exame\n");

                printf("Escolha o setor: ");
                scanf("%d", &setor);

                // emergencia (pilha)
                if (setor == 1)
                {
                    if (topo == -1) // nenhum paciente
                    {
                        printf("Emergencia vazia!\n");
                    }

                    else
                    {
                        printf("\nPaciente atendido:\n");

                        printf("Nome: %s\n", emergencia[topo].nome); // mostra o nome do paciente no topo
                        printf("Idade: %d\n", emergencia[topo].idade);
                        printf("Gravidade: %d\n", emergencia[topo].gravidade);

                        topo--; // remove o paciente da pilha
                    }
                }

                // consulta (fila)
                else if (setor == 2)
                {
                    if (inicio > fim) // fila vazia
                    {
                        printf("Fila de consulta vazia!\n");
                    }

                    else
                    {
                        printf("\nPaciente atendido:\n");

                        printf("Nome: %s\n", consulta[inicio].nome); // mostra o primeiro paciente da fila
                        printf("Idade: %d\n", consulta[inicio].idade);
                        printf("Gravidade: %d\n", consulta[inicio].gravidade);

                        inicio++; // remove o paciente da fila
                    }
                }

                // exame (fila circular)
                else if (setor == 3)
                {
                    if (totalExame == 0) // fila vazia
                    {
                        printf("Fila de exame vazia!\n");
                    }

                    else
                    {
                        printf("\nPaciente atendido:\n");

                        printf("Nome: %s\n", exame[inicioExame].nome);
                        printf("Idade: %d\n", exame[inicioExame].idade);
                        printf("Gravidade: %d\n", exame[inicioExame].gravidade);

                        inicioExame = (inicioExame + 1) % 8;

                        totalExame--;
                    }
                }

                break;
            }

            case 3:
            {
                int setor;
                int i;

                printf("\n1 - Emergencia\n");
                printf("2 - Consulta\n");
                printf("3 - Exame\n");

                printf("Escolha o setor: ");
                scanf("%d", &setor);

                // emergencia (pilha)
                if (setor == 1)
                {
                    if (topo == -1)
                    {
                        printf("Emergencia vazia!\n");
                    }

                    else
                    {
                        printf("\nPacientes da emergencia:\n");

                        for (i = topo; i >= 0; i--) // começa no topo
                        {
                            printf("Nome: %s\n", emergencia[i].nome);
                            printf("Idade: %d\n", emergencia[i].idade);
                            printf("Gravidade: %d\n\n", emergencia[i].gravidade);
                        }
                    }
                }

                // consulta (fila)
                else if (setor == 2)
                {
                    if (inicio > fim)
                    {
                        printf("Fila de consulta vazia!\n");
                    }

                    else
                    {
                        printf("\nPacientes da consulta:\n");

                        for (i = inicio; i <= fim; i++) // mostra o inicio até o fim
                        {
                            printf("Nome: %s\n", consulta[i].nome);
                            printf("Idade: %d\n", consulta[i].idade);
                            printf("Gravidade: %d\n\n", consulta[i].gravidade);
                        }
                    }
                }

                // exame (fila circular)
                else if (setor == 3)
                {
                    if (totalExame == 0)
                    {
                        printf("Fila de exame vazia!\n");
                    }

                    else
                    {
                        printf("\nPacientes do exame:\n");

                        for (i = 0; i < totalExame; i++) // volta do começo
                        {
                            int posicao = (inicioExame + i) % 8;

                            printf("Nome: %s\n", exame[posicao].nome);
                            printf("Idade: %d\n", exame[posicao].idade);
                            printf("Gravidade: %d\n\n", exame[posicao].gravidade);
                        }
                    }
                }

                break;
            }

            case 4:
            {
                int origem; // saida
                int destino; // destino

                struct Paciente temp; // paciente temporario

                printf("\n1 - Emergencia\n");
                printf("2 - Consulta\n");
                printf("3 - Exame\n");

                printf("De qual setor vai sair? ");
                scanf("%d", &origem);

                // emergencia
                if (origem == 1)
                {
                    if (topo == -1)
                    {
                        printf("Emergencia vazia!\n");
                    }

                    else
                    {
                        temp = emergencia[topo]; // pega o paciente do topo

                        topo--; // remove da pilha

                        printf("Paciente removido da emergencia!\n");
                    }
                }

                // consulta
                else if (origem == 2)
                {
                    if (inicio > fim)
                    {
                        printf("Consulta vazia!\n");
                    }

                    else
                    {
                        temp = consulta[inicio]; // pega o primeiro da fila

                        inicio++; // remove da fila

                        printf("Paciente removido da consulta!\n");
                    }
                }

                // exame
                else if (origem == 3)
                {
                    if (totalExame == 0)
                    {
                        printf("Exame vazio!\n");
                    }

                    else
                    {
                        temp = exame[inicioExame]; // guarda paciente

                        inicioExame = (inicioExame + 1) % 8; // remove paciente

                        totalExame--;

                        printf("Paciente removido do exame!\n");
                    }
                }

                printf("\nPara qual setor vai?\n");
                printf("1 - Emergencia\n");
                printf("2 - Consulta\n");
                printf("3 - Exame\n");

                scanf("%d", &destino);

                // emergencia
                if (destino == 1)
                {
                    topo++;

                    emergencia[topo] = temp;

                    printf("Paciente transferido para emergencia!\n");
                }

                // consulta
                else if (destino == 2)
                {
                    fim++;

                    consulta[fim] = temp;

                    printf("Paciente transferido para consulta!\n");
                }

                // exame
                else if (destino == 3)
                {
                    // fila cheia
                    if (totalExame == 8)
                    {
                        inicioExame = (inicioExame + 1) % 8;

                        totalExame--;
                    }

                    fimExame = (fimExame + 1) % 8;

                    exame[fimExame] = temp;

                    totalExame++;

                    printf("Paciente transferido para exame!\n");
                }

                break;
            }

            case 5: // relatorios

                printf("\nRELATORIOS\n");

                // emergencia (topo + 1 = quantidade de pacientes)
                printf("Pacientes na emergencia: %d\n", topo + 1);

                // consulta
                // se o inicio passar do fim significa que nao tem mais pacientes
                if (inicio > fim)
                {
                    printf("Pacientes na consulta: 0\n");
                }

                else
                {
                    // calcula quantidade de pacientes da fila
                    printf("Pacientes na consulta: %d\n", fim - inicio + 1);
                }

                // exame
                printf("Pacientes no exame: %d\n", totalExame); // guarda quantos pacientes existem

                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida\n");
        }
    }

    return 0;
}