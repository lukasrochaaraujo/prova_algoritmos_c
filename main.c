#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_DIAS_SEMANA 5
#define MAXIMO_CONSULTA_DIA_POR_MEDICO 2
#define MAXIMO_MEDICOS 3
#define MAXIMO_PACIENTES 5

#define OPCAO_MEDICO_CADASTRAR 1
#define OPCAO_PACIENTE_CADASTRAR 2
#define OPCAO_CONSULTA_CADASTRAR 3
#define OPCAO_PESQUISAR_CONSULTA 4
#define OPCAO_SAIR 0

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
    char DiaSemana[3];
    char Hora[5];
};

//declaracoes de funcoes
void ConfigurarMatrizDiasSenama();
void Menu();

void CadastrarMedico();
void ExibirMedico(struct Medico medico);

void CadastrarPaciente();
void ExibirPaciente(struct Paciente paciente);

void CadastrarConsulta();
void PesquisarConsulta();
void ExibirConsulta(struct Consulta consulta);

void LimparTela();

//variaveis globais
struct Medico matriz_medico[MAXIMO_MEDICOS + 1];
struct Paciente matriz_paciente[MAXIMO_PACIENTES + 1];
struct Consulta matriz_consulta[MAXIMO_DIAS_SEMANA][MAXIMO_MEDICOS * MAXIMO_CONSULTA_DIA_POR_MEDICO];
char* matriz_dia_semana[5];

int main()
{
    ConfigurarMatrizDiasSenama();
    Menu();

    return 0;
}

void ConfigurarMatrizDiasSenama()
{
    matriz_dia_semana[0] = "SEG";
    matriz_dia_semana[1] = "TER";
    matriz_dia_semana[2] = "QUA";
    matriz_dia_semana[3] = "QUI";
    matriz_dia_semana[4] = "SEX";
}

void Menu()
{
    printf("\n[BEM VINDO]\n\n");

    for(;;)
    {
        int opcao_menu;
        printf("[MENU] - ESCOLHA UMA OPCAO ABAIXO:\n\n");
        printf("\t[1]. CADASTRAR MEDICO\n\n");
        printf("\t[2]. CADASTRAR PACIENTE\n\n");
        printf("\t[3]. CADASTRAR CONSULTA\n\n");
        printf("\t[4]. PESQUISAR CONSULTA\n\n");
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
            case OPCAO_PACIENTE_CADASTRAR:
                CadastrarPaciente();
                break;
            case OPCAO_CONSULTA_CADASTRAR:
                CadastrarConsulta();
                break;
            case OPCAO_PESQUISAR_CONSULTA:
                PesquisarConsulta();
                break;
            case OPCAO_SAIR:
                printf("\n[ATE LOGO]\n\n");
                return;
        }

        printf("\n[TECLE ALGO PARA VOLTAR AO MENU]");
        getchar();

        LimparTela();
    }
}

void CadastrarMedico()
{
    struct Medico novoMedico;

    printf("\n[CADASTRAR MEDICO]\n\n");
    printf("CODIGO....: ");
    scanf("%d", &novoMedico.Codigo);
    getchar();

    if (novoMedico.Codigo == 0 || novoMedico.Codigo > MAXIMO_MEDICOS)
    {
        printf("\n[INSIRA UM CODIGO ENTRE 1-%d]\n", MAXIMO_MEDICOS);
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
    }
    else
    {
        matriz_medico[novoMedico.Codigo] = novoMedico;
        printf("\n[MEDICO CADASTRADO]\n\n");
    }
}

void CadastrarPaciente()
{
    struct Paciente novoPaciente;

    printf("\n[CADASTRAR PACIENTE]\n\n");
    printf("CODIGO....: ");
    scanf("%d", &novoPaciente.Codigo);
    getchar();

    if (novoPaciente.Codigo == 0 || novoPaciente.Codigo > MAXIMO_PACIENTES)
    {
        printf("\n[INSIRA UM CODIGO ENTRE 1-%d]\n", MAXIMO_PACIENTES);
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
    }
    else
    {
        matriz_paciente[novoPaciente.Codigo] = novoPaciente;
        printf("\n[PACIENTE CADASTRADO]\n\n");
    }
}

void CadastrarConsulta()
{
    printf("\n[CADASTRAR CONSULTA]\n\n");

    //selecao dia semana
    printf("\n[SELECIONE UM DIA DA SEMANA]\n\n");

    for(int diaSemana = 0; diaSemana < 5; diaSemana++)
        printf("[%d]-%s  ", diaSemana, matriz_dia_semana[diaSemana]);

    printf("\n");

    int diaSemana;
    printf("\nOPCAO: ");
    scanf("%d", &diaSemana);
    getchar();

    printf("\n[DIA SELECIONADO] - [%s]\n", matriz_dia_semana[diaSemana]);

    //selecao medico (lembrar limite consultas/dia)
    printf("\n[SELECIONE UM MEDICO]\n");
    getchar();

    //selcao paciente
    printf("\n[SELECIONE UM PACIENTE]\n");
    getchar();

    //registrar consulta
}

void PesquisarConsulta()
{

}

void ExibirConsulta(struct Consulta consulta)
{
    printf("CODIGO.....: %d \n", consulta.Codigo);
    printf("DIA SEMANA.: %s \n", consulta.DiaSemana);
    printf("HORARIO....: %s \n", consulta.Hora);
    printf("MEDICO.....: %d \n", consulta.CodigoMedico);
    printf("PACIENTE...: %d \n", consulta.CodigoPaciente);
}

void LimparTela()
{
    system("cls");
}
