# Software de agendamento de consulta

Utilize as informações a seguir para criar um controle automatizado de uma clínica médica.

Sabe-se que essa clínica deseja ter um controle semanal (de segunda a sexta-feira) das consultas 
realizadas. 

A cada dia, cada médico pode realizar, no máximo, duas consultas. 
[regra - 1 medico pode ter 2 consultas/dia]

Considere que serão cadastrados três médicos e cinco pacientes.
[limite de 3 medicos]
[limite de 5 pacientes]

Paciente (código do paciente, nome, endereço, fone)
[estrutura]

Médico (código do médico, nome, endereço, fone)
[estrutura]

Consulta (código da consulta, dia semana, hora, código do médico, código do paciente)
[estrutura]

O programa deverá criar rotinas para:

* Cadastrar os pacientes, não permitindo dois pacientes com o mesmo código;
[nao permitir codigo repetido]

* Cadastrar os médicos, não permitindo dois médicos com o mesmo código;
[nao permitir codigo repetido]

* Cadastrar as consultas, obedecendo às especificações apresentadas;
[1 medico pode ter 2 consultas/dia]
[consultas somente de seg-sex]

* Pesquisar as consultas de determinado médico em certo dia da semana (segunda a sexta-feira);
[consulta por medico]
[consulta por dia semana]

* Mostrar um relatório contendo todas as consultas realizadas em um dia;
[listar consultar por dia semana]