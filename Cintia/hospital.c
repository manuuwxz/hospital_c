#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"  // .c é implementação

//  Emergência: Pilha (último a chegar é atendido primeiro) – capacidade definida por vetor
Paciente pilhaEmergencia[MAX_PILHA];
int topoEmergencia = -1;
// Consultas Agendadas: Fila (primeiro a chegar é atendido primeiro) – capacidade definida por vetor
Paciente filaConsultas[MAX_FILA];
int frenteConsultas = 0;
int trasConsultas = -1;
//  Exames/Laboratório: Fila Circular (máximo de 8 pacientes, remove o mais antigo automaticamente)
Paciente filaExames[MAX_CIRCULAR];
int frenteExames = -1;
int trasExames = -1;
int totalExames = 0;

void  exibirDados(Paciente p) {
    printf("Nome: %s | Idade: %d | Gravidade: %d\n", p.nome, p.idade, p.gravidade);
}

void CadastrarPaciente() {
    Paciente p;
    printf("\nNome do Paciente: ");
    scanf(" %[^\n]", p.nome);
    printf("Idade: ");
    scanf("%d", &p.idade);
    printf("Gravidade (1 a 5): ");
    scanf("%d", &p.gravidade);

    // Regra de Negócio: Gravidade 4 ou 5 vai para Emergência
    if (p.gravidade >= 4) {
        if (topoEmergencia < MAX_PILHA - 1) {
            topoEmergencia++;
            pilhaEmergencia[topoEmergencia] = p;
            printf(">> Direcionado para EMERGÊNCIA\n");
        } else {
            printf("Erro: Emergência lotada!\n");
        }
    } else {
        printf("Setor (2-Consulta, 3-Exame): ");
        scanf("%d", &p.tipo);

        if (p.tipo == 2) { // Fila Linear
            if (trasConsultas < MAX_FILA - 1) {
                trasConsultas++;
                filaConsultas[trasConsultas] = p;
                printf(">> Direcionado para CONSULTAS\n");
            } else {
                printf("Erro: Fila de Consultas cheia!\n");
            }
        } else { // Fila Circular (Exames)
            // Regra: Se estiver cheia (8), remove o mais antigo automaticamente
            if (totalExames == MAX_CIRCULAR) {
                printf("Aviso: Fila de exames cheia. Removendo paciente antigo...\n");
                frenteExames = (frenteExames + 1) % MAX_CIRCULAR;
                totalExames--;
            }
            if (frenteExames == -1) frenteExames = 0;
            trasExames = (trasExames + 1) % MAX_CIRCULAR;
            filaExames[trasExames] = p;
            totalExames++;
            printf(">> Direcionado para EXAMES\n");
        }
    }
}

void AtenderEmergencia() {
    if (topoEmergencia == -1) {
        printf("Emergência vazia.\n");
        return;
    }
    printf("\nAtendendo na Emergência (Último a chegar):\n");
    exibirDados(pilhaEmergencia[topoEmergencia]);
    topoEmergencia--;
}

void AtenderConsulta() {
    if (frenteConsultas > trasConsultas) {
        printf("Fila de consultas vazia.\n");
        return;
    }
    printf("\nAtendendo Consulta (Primeiro a chegar):\n");
    exibirDados(filaConsultas[frenteConsultas]);
    frenteConsultas++;
}

void AtenderExame() {
    if (totalExames == 0) {
        printf("Fila de exames vazia.\n");
        return;
    }
    printf("\nAtendendo Exame (Fila Circular):\n");
    exibirDados(filaExames[frenteExames]);
    frenteExames = (frenteExames + 1) % MAX_CIRCULAR;
    totalExames--;
    if (totalExames == 0) { frenteExames = -1; trasExames = -1; }
}

void AtenderPaciente(){
        int opcao; 
        printf("\nSETORES - Atendimento:");
        printf("\n1- Emergência");
        printf("\n2- Consulta");
        printf("\n3- Exames");
        printf("\n4- Sair");
        printf("\nDigite sua opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            AtenderEmergencia();
            break;
        case 2:
            AtenderConsulta();
            break;
        case 3:
            AtenderExame();
            break;
        case 4:
            printf("Voltando a tela inicial!\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
}

void ExibirPaciente() {
    int i, idx;

    printf("\nLISTA DE ESPERA POR SETOR");

    // 1. EXIBIR PILHA (EMERGÊNCIA) - Do topo para a base
    printf("\nEMERGÊNCIA (Ordem de Atendimento: Último que entra, Primeiro que sai) \n");
    if (topoEmergencia == -1) {
        printf("Vazia.\n");
    } else {
        for (i = topoEmergencia; i >= 0; i--) {
            printf("[%d] ", i);
            exibirDados(pilhaEmergencia[i]);
        }
    }

    // 2. EXIBIR FILA LINEAR (CONSULTAS) - Da frente para o final
    printf("\nCONSULTAS (Ordem de Atendimento: Primeiro que entra, Primeiro que sai)\n");
    if (frenteConsultas > trasConsultas) {
        printf("Vazia.\n");
    } else {
        for (i = frenteConsultas; i <= trasConsultas; i++) {
            printf("[%d] ", i);
            exibirDados(filaConsultas[i]);
        }
    }

    // 3. EXIBIR FILA CIRCULAR (EXAMES) - Percorrendo usando o total de elementos
    printf("\nEXAMES (Fila Circular - Máx 8)\n");
    if (totalExames == 0) {
        printf("Vazia.\n");
    } else {
        for (i = 0; i < totalExames; i++) {
            // Cálculo do índice circular: (frente + deslocamento) % tamanho
            idx = (frenteExames + i) % MAX_CIRCULAR;
            printf("[%d] ", idx);
            exibirDados(filaExames[idx]);
        }
    }
}

void TransferirPaciente() {
    int origem, destino;
    Paciente temporario;
    int houveRemocao = 0;

    printf("\nTransferencia de Paciente");
    printf("\nSair de: \n1-Emergencia \n2-Consulta \n3-Exame: ");
    scanf("%d", &origem);

    // 1. REMOVER DA ORIGEM
    switch (origem) {
        case 1: // Saindo da Emergencia (Pilha - Topo)
            if (topoEmergencia >= 0) {
                temporario = pilhaEmergencia[topoEmergencia];
                topoEmergencia--;
                houveRemocao = 1;
            } else printf("Erro: Emergencia vazia!\n");
            break;

        case 2: // Saindo da Consulta (Fila Linear - Frente)
            if (frenteConsultas <= trasConsultas) {
                temporario = filaConsultas[frenteConsultas];
                frenteConsultas++;
                houveRemocao = 1;
            } else printf("Erro: Fila de Consultas vazia!\n");
            break;

        case 3: // Saindo do Exame (Fila Circular - Frente)
            if (totalExames > 0) {
                temporario = filaExames[frenteExames];
                frenteExames = (frenteExames + 1) % MAX_CIRCULAR;
                totalExames--;
                houveRemocao = 1;
            } else printf("Erro: Fila de Exames vazia!\n");
            break;

        default:
            printf("Opcao de origem invalida!\n");
            return;
    }

    // 2. INSERIR NO DESTINO (Se a remocao deu certo)
    if (houveRemocao) {
        printf("\nTransferir para:\n1-Emergencia \n2-Consulta \n3-Exame: ");
        scanf("%d", &destino);

        switch (destino) {
            case 1: // Para Emergencia (Pilha)
                if (topoEmergencia < MAX_PILHA - 1) {
                    topoEmergencia++;
                    pilhaEmergencia[topoEmergencia] = temporario;
                    printf("Paciente: %s transferido para Emergencia.\n", temporario.nome);
                } else printf("Erro: Setor lotado! Paciente perdido no sistema.\n");
                break;

            case 2: // Para Consulta (Fila)
                if (trasConsultas < MAX_FILA - 1) {
                    trasConsultas++;
                    filaConsultas[trasConsultas] = temporario;
                    printf("Paciente: %s transferido para Consultas.\n", temporario.nome);
                } else printf("Erro: Setor lotado!\n");
                break;

            case 3: // Para Exame (Fila Circular)
                // Se estiver cheia, a regra diz para remover o antigo e colocar o novo
                if (totalExames == MAX_CIRCULAR) {
                    frenteExames = (frenteExames + 1) % MAX_CIRCULAR;
                    totalExames--;
                }
                if (frenteExames == -1) frenteExames = 0;
                trasExames = (trasExames + 1) % MAX_CIRCULAR;
                filaExames[trasExames] = temporario;
                totalExames++;
                printf("Paciente: %s transferido para Exames.\n", temporario.nome);
                break;

            default:
                printf("Opcao de destino invalida! O paciente recebeu alta forçada.\n");
                break;
        }
    }
}

void  Relatorios() {
    printf("\n--- STATUS ATUAL ---\n");
    printf("Emergência (Pilha): %d pacientes\n", topoEmergencia + 1);
    printf("Consultas (Fila): %d pacientes\n", (trasConsultas - frenteConsultas + 1) < 0 ? 0 : (trasConsultas - frenteConsultas + 1));
    printf("Exames (Circular): %d pacientes\n", totalExames);
}