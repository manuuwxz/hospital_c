ATIVIDADE EM GRUPO – ESTRUTURA DE DADOS

Alunas:
Emanuelly de Oliveira Rodrigues - 202512546
Cintia M. Bernardo - 202512564

Tema: Pilha, Fila e Fila Circular

Título da Atividade: Hospital Simulado – Sistema de Gerenciamento de Pacientes

Objetivo
Desenvolver um sistema em linguagem C que simule o fluxo de pacientes em um
hospital utilizando Pilha, Fila e Fila Circular, implementadas com vetores (arrays).

Cenário
Um hospital possui três setores com regras diferentes de atendimento:

- Emergência:
Pilha (último a chegar é atendido primeiro) – capacidade definida por
vetor

- Consultas Agendadas:
Fila (primeiro a chegar é atendido primeiro) – capacidade definida por
vetor

- Exames/Laboratório:
Fila Circular (máximo de 8 pacientes, remove o mais antigo
automaticamente)

Requisitos Obrigatórios

1. Cadastro de Paciente
- Nome (string)
- Idade (int)
- Gravidade (1 a 5)
- Tipo de Atendimento (1-Emergência, 2-Consulta, 3-Exame)
  
2. Menu Principal
- Cadastrar novo paciente
- Atender paciente em cada setor
- Mostrar pacientes em cada setor
- Transferir paciente entre setores
- Relatórios
- Sair
  
3. Implementação das Estruturas
- Pilha: vetor (array) com controle de topo
- Fila: vetor (array) com controle de início e fim
- Fila Circular: vetor de tamanho 8 com índices circulares
  
4. Regras de Negócio
- Pacientes com gravidade 4 ou 5 devem ser direcionados para Emergência
- Ao atender, exibir os dados do paciente removido
- Na fila circular, ao atingir a capacidade máxima, remover automaticamente o
paciente mais antigo

Entregas
1. Código fonte (.c e .h)
