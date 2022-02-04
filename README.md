# Software de agendamento de consulta

Utilize as informações a seguir para criar um controle automatizado de uma clínica médica.

Sabe-se que essa clínica deseja ter um controle semanal (de segunda a sexta-feira) das consultas realizadas. 

A cada dia, cada médico pode realizar, no máximo, duas consultas. 

Considere que serão cadastrados três médicos e cinco pacientes.

Paciente (código do paciente, nome, endereço, fone)

Médico (código do médico, nome, endereço, fone)

Consulta (código da consulta, dia semana, hora, código do médico, código do paciente)

O programa deverá criar rotinas para:

* Cadastrar os pacientes, não permitindo dois pacientes com o mesmo código;
* Cadastrar os médicos, não permitindo dois médicos com o mesmo código;
* Cadastrar as consultas, obedecendo às especificações apresentadas;
* Pesquisar as consultas de determinado médico em certo dia da semana (segunda a sexta-feira);
* Mostrar um relatório contendo todas as consultas realizadas em um dia;