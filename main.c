#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_CADASTRO 1000
#define OPCAO_SAIR 0
#define OPCAO_MEDICO_CADASTRAR 1
#define OPCAO_MEDICO_CONSULTAR 2
#define OPCAO_PACIENTE_CADASTRAR 3
#define OPCAO_PACIENTE_CONSULTAR 4

//estruturas
struct Medico
{
    int Codigo;
    char Nome[255];
    char Endereco[255];
    char Telefone[255];
};

struct Paciente
{
    int Codigo;
    char Nome[255];
    char Endereco[255];
    char Telefone[255];
};

struct Consulta
{
    int Codigo;
    int CodigoMedico;
    int CodigoPaciente;
    int DiaSemana;
    int Hora;
};

//declaracoes de funcoes
void CadastrarMedico();
void ConsultarMedico();
void ExibirMedico(struct Medico medico);

void CadastrarPaciente();
void ConsultarPaciente();
void ExibirPaciente(struct Paciente paciente);

void LimparTela();

//variaveis globais
struct Medico matriz_medico[MAXIMO_CADASTRO];
struct Paciente matriz_paciente[MAXIMO_CADASTRO];

int main()
{
    printf("\n[BEM VINDO]\n\n");
    for(;;)
    {
        int opcao_menu;
        printf("[MENU] - ESCOLHA UMA OPCAO ABAIXO:\n\n");
        printf("\t[1]. CADASTRAR MEDICO\n\n");
        printf("\t[2]. CONSULTAR MEDICO\n\n");
        printf("\t[3]. CADASTRAR PACIENTE\n\n");
        printf("\t[4]. CONSULTAR PACIENTE\n\n");
        printf("\t[0]. SAIR\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao_menu);
        getchar();

        LimparTela();

        switch(opcao_menu)
        {
            case OPCAO_MEDICO_CADASTRAR:
                CadastrarMedico();
                break;
            case OPCAO_MEDICO_CONSULTAR:
                ConsultarMedico();
                break;
            case OPCAO_PACIENTE_CADASTRAR:
                CadastrarPaciente();
                break;
            case OPCAO_PACIENTE_CONSULTAR:
                ConsultarPaciente();
                break;
            case OPCAO_SAIR:
                printf("\n[ATE LOGO]\n\n");
                return 0;
        }

        printf("\n[TECLE ALGO PARA VOLTAR AO MENU]");
        getchar();

        LimparTela();
    }

    return 0;
}


void CadastrarMedico()
{
    struct Medico novoMedico;

    printf("\n[CADASTRAR MEDICO]\n\n");
    printf("CODIGO....: ");
    scanf("%d", &novoMedico.Codigo);
    getchar();

    if (novoMedico.Codigo == 0 || novoMedico.Codigo > MAXIMO_CADASTRO)
    {
        printf("\n[INSIRA UM CODIGO ENTRE 1-%d]\n", MAXIMO_CADASTRO);
        return;
    }

    printf("NOME......: ");
    gets(novoMedico.Nome);

    printf("ENDERECO..: ");
    gets(novoMedico.Endereco);

    printf("TELEFONE..: ");
    gets(novoMedico.Telefone);

    struct Medico medicoExistente = matriz_medico[novoMedico.Codigo];

    if (medicoExistente.Codigo > 0)
    {
        printf("\n[O CODIGO INFORMADO JA ESTA EM USO]\n");

        char respostaSobrescrever = 'n';
        printf("\n[DESEJA SOBRESCREVER? (S|N)]: ");
        scanf("%s", &respostaSobrescrever);
        getchar();

        if (respostaSobrescrever == 'S' || respostaSobrescrever == 's')
        {
            matriz_medico[novoMedico.Codigo] = novoMedico;
            printf("\n[MEDICO ATUALIZADO]\n\n");
        }
    }
    else
    {
        matriz_medico[novoMedico.Codigo] = novoMedico;
        printf("\n[MEDICO CADASTRADO]\n\n");
    }
}

void ConsultarMedico()
{
    int codigoMedico;

    printf("\n[CONSULTAR MEDICO]\n\n");
    printf("CODIGO....: ");
    scanf("%d", &codigoMedico);
    getchar();

    struct Medico medico = matriz_medico[codigoMedico];

    if(medico.Codigo > 0)
    {
        printf("\n[MEDICO ENCONTRADO]\n\n");
        ExibirMedico(medico);
    }
    else
    {
        printf("\n[MEDICO NAO ENCONTRADO]\n");

        char respostaListarTudo = 'n';
        printf("\n[DESEJA EXIBIR TODOS OS MEDICOS? (S|N)]: ");
        scanf("%s", &respostaListarTudo);
        getchar();

        if (respostaListarTudo == 'S' || respostaListarTudo == 's')
        {
            printf("\n[MEDICOS CADASTRADOS]\n\n");
            for(int codigo = 0; codigo < MAXIMO_CADASTRO; codigo++)
            {
                struct Medico medicoBusca;
                medicoBusca = matriz_medico[codigo];

                if (medicoBusca.Codigo > 0)
                {
                    ExibirMedico(medicoBusca);
                    printf("------------------------------------------\n");
                }
            }
        }
    }
}

void ExibirMedico(struct Medico medico)
{
    printf("CODIGO....: %d \n", medico.Codigo);
    printf("NOME......: %s \n", medico.Nome);
    printf("ENDERECO..: %s \n", medico.Endereco);
    printf("TELEFONE..: %s \n", medico.Telefone);
}

void CadastrarPaciente()
{
    struct Paciente novoPaciente;

    printf("\n[CADASTRAR PACIENTE]\n\n");
    printf("CODIGO....: ");
    scanf("%d", &novoPaciente.Codigo);
    getchar();

    if (novoPaciente.Codigo == 0 || novoPaciente.Codigo > MAXIMO_CADASTRO)
    {
        printf("\n[INSIRA UM CODIGO ENTRE 1-%d]\n", MAXIMO_CADASTRO);
        return;
    }

    printf("NOME......: ");
    gets(novoPaciente.Nome);

    printf("ENDERECO..: ");
    gets(novoPaciente.Endereco);

    printf("TELEFONE..: ");
    gets(novoPaciente.Telefone);

    struct Paciente pacienteExistente = matriz_paciente[novoPaciente.Codigo];

    if (pacienteExistente.Codigo > 0)
    {
        printf("\n[O CODIGO INFORMADO JA ESTA EM USO]\n");

        char respostaSobrescrever = 'n';
        printf("\n[DESEJA SOBRESCREVER? (S|N)]: ");
        scanf("%s", &respostaSobrescrever);
        getchar();

        if (respostaSobrescrever == 'S' || respostaSobrescrever == 's')
        {
            matriz_paciente[novoPaciente.Codigo] = novoPaciente;
            printf("\n[PACIENTE ATUALIZADO]\n\n");
        }
    }
    else
    {
        matriz_paciente[novoPaciente.Codigo] = novoPaciente;
        printf("\n[PACIENTE CADASTRADO]\n\n");
    }
}

void ConsultarPaciente()
{
    int codigoPaciente;

    printf("\n[CONSULTAR PACIENTE]\n\n");
    printf("CODIGO....: ");
    scanf("%d", &codigoPaciente);
    getchar();

    struct Paciente paciente = matriz_paciente[codigoPaciente];

    if(paciente.Codigo > 0)
    {
        printf("\n[PACIENTE ENCONTRADO]\n\n");
        ExibirPaciente(paciente);
    }
    else
    {
        printf("\n[PACIENTE NAO ENCONTRADO]\n");

        char respostaListarTudo = 'n';
        printf("\n[DESEJA EXIBIR TODOS OS PACIENTE? (S|N)]: ");
        scanf("%s", &respostaListarTudo);
        getchar();

        if (respostaListarTudo == 'S' || respostaListarTudo == 's')
        {
            printf("\n[PACIENTES CADASTRADOS]\n\n");
            for(int codigo = 0; codigo < MAXIMO_CADASTRO; codigo++)
            {
                struct Paciente pacienteBusca;
                pacienteBusca = matriz_paciente[codigo];

                if (pacienteBusca.Codigo > 0)
                {
                    ExibirPaciente(pacienteBusca);
                    printf("------------------------------------------\n");
                }
            }
        }
    }
}

void ExibirPaciente(struct Paciente paciente)
{
    printf("CODIGO....: %d \n", paciente.Codigo);
    printf("NOME......: %s \n", paciente.Nome);
    printf("ENDERECO..: %s \n", paciente.Endereco);
    printf("TELEFONE..: %s \n", paciente.Telefone);
}

void LimparTela()
{
    system("cls");
}
