#include <stdio.h>
#include <stdlib.h>
#include "hospital.h" 

int main(){
    int opcao = 0;
    while (opcao != 6){
        printf("\nHospital Simulado");
        printf("\nSistema de Gerenciamento de Pacientes");
        printf("\n1-Cadastrar novo paciente");
        printf("\n2-Atender paciente em cada setor ");
        printf("\n3-Mostrar pacientes em cada setor");
        printf("\n4-Transferir paciente entre setores");
        printf("\n5-Relatórios");
        printf("\n6-Sair");
        printf("\nDigite sua opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            CadastrarPaciente();
            break;
        case 2:
            AtenderPaciente();
            break;
        case 3:
            ExibirPaciente();
            break;
        case 4:
            TransferirPaciente();
            break;
        case 5:
            Relatorios();
            break;
        case 6:
            printf("Encerrando programa...\n");
            break;
            
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}