#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int DiaSemana;
    char Hora[10];
};

//declaracoes de funcoes
void ConfigurarMatrizDiasSenama();
void Menu();
void CadastrarMedico();
void CadastrarPaciente();
void CadastrarConsulta();
void PesquisarConsulta();
int SelecionarDiaDaSemana();
int SelecionarMedico();
int SelecionarPaciente();
void ExibirConsulta(struct Consulta consulta);
void LimparTela();

//variaveis globais
struct Medico matriz_medico[MAXIMO_MEDICOS + 1];
struct Paciente matriz_paciente[MAXIMO_PACIENTES + 1];

struct Consulta matriz_consulta[MAXIMO_DIAS_SEMANA][MAXIMO_MEDICOS * MAXIMO_CONSULTA_DIA_POR_MEDICO + 1];
static int ControleCodigoConsultaSeg = 1;
static int ControleCodigoConsultaTer = 1;
static int ControleCodigoConsultaQua = 1;
static int ControleCodigoConsultaQui = 1;
static int ControleCodigoConsultaSex = 1;
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

    int diaConsulta = SelecionarDiaDaSemana();
    LimparTela();

    char horarioConsulta[10];
    printf("\nINFORME O HORARIO DA CONSULTA (00:00): ");
    gets(horarioConsulta);
    LimparTela();

    int codigoMedico;
    int medicoDisponivel;

    do
    {
        codigoMedico = SelecionarMedico();
        LimparTela();

        medicoDisponivel = MedicoEstaDisponivel(diaConsulta, codigoMedico);
    }
    while(medicoDisponivel < 0);

    int codigoPaciente = SelecionarPaciente();
    LimparTela();

    struct Consulta novaConsulta;
    novaConsulta.DiaSemana = diaConsulta;
    strcpy(novaConsulta.Hora, horarioConsulta);
    novaConsulta.CodigoMedico = codigoMedico;
    novaConsulta.CodigoPaciente = codigoPaciente;

    switch(novaConsulta.DiaSemana)
    {
        case 0:
            novaConsulta.Codigo = ControleCodigoConsultaSeg++;
            break;
        case 1:
            novaConsulta.Codigo = ControleCodigoConsultaTer++;
            break;
        case 2:
            novaConsulta.Codigo = ControleCodigoConsultaQua++;
            break;
        case 3:
            novaConsulta.Codigo = ControleCodigoConsultaQui++;
            break;
        case 4:
            novaConsulta.Codigo = ControleCodigoConsultaSex++;
            break;
    }

    matriz_consulta[novaConsulta.DiaSemana][novaConsulta.Codigo] = novaConsulta;

    LimparTela();
    printf("CONSULTA CADASTRADA:\n");
    ExibirConsulta(novaConsulta);
}

int SelecionarDiaDaSemana()
{
    printf("SELECIONE UM DIA DA SEMANA:\n\n");

    for(int diaSemana = 0; diaSemana < 5; diaSemana++)
        printf("[%d]-%s  ", diaSemana, matriz_dia_semana[diaSemana]);

    printf("\n");

    int diaSemana;
    printf("\nOPCAO: ");
    scanf("%d", &diaSemana);
    getchar();

    printf("\nDIA SELECIONADO: [%s]\n", matriz_dia_semana[diaSemana]);

    return diaSemana;
}

int SelecionarMedico()
{
    int codigoMedicoSelecionado;

    printf("SELECIONE UM MEDICO\n\n");

    for(int codigoMedico = 1; codigoMedico <= MAXIMO_MEDICOS; codigoMedico++)
    {
        struct Medico medico = matriz_medico[codigoMedico];
        if (medico.Codigo > 0)
        {
            printf("COD..: %d\n", medico.Codigo);
            printf("NOME.: %s\n", medico.Nome);
            printf("--------------------------\n");
        }
    }

    printf("\nCOD MEDICO: ");
    scanf("%d", &codigoMedicoSelecionado);
    getchar();

    printf("\n");

    return codigoMedicoSelecionado;
}

int MedicoEstaDisponivel(int diaConsulta, int codigoMedico)
{
    int maximoConsultasPorDia = MAXIMO_MEDICOS * MAXIMO_CONSULTA_DIA_POR_MEDICO + 1;
    int quantidadeConsultasMedido = 0;

    for (int codigoConsulta = 0; codigoConsulta < maximoConsultasPorDia; codigoConsulta++)
    {
        struct Consulta consulta = matriz_consulta[diaConsulta][codigoConsulta];

        if (consulta.Codigo > 0 && consulta.CodigoMedico == codigoMedico)
        {
            quantidadeConsultasMedido++;
        }
    }

    if (quantidadeConsultasMedido == 2)
    {
        printf("\nMEDICO COM AGENDA LOTADA!");
        getchar();
        LimparTela();
        return -1;
    }

    return 1;
}

int SelecionarPaciente()
{
    int codigoPacienteSelecionado;

    printf("SELECIONE UM PACIENTE\n\n");

    for(int codigoPaciente = 1; codigoPaciente <= MAXIMO_PACIENTES; codigoPaciente++)
    {
        struct Paciente paciente = matriz_paciente[codigoPaciente];
        if (paciente.Codigo > 0)
        {
            printf("COD..: %d\n", paciente.Codigo);
            printf("NOME.: %s\n", paciente.Nome);
            printf("--------------------------\n");
        }
    }

    printf("\nCOD PACIENTE: ");
    scanf("%d", &codigoPacienteSelecionado);
    getchar();

    printf("\n");

    return codigoPacienteSelecionado;
}

void PesquisarConsulta()
{
    int maximoConsultasPorDia = (MAXIMO_MEDICOS * MAXIMO_CONSULTA_DIA_POR_MEDICO + 1);
    int diaDaSemana = SelecionarDiaDaSemana();
    LimparTela();

    printf("CONSULTAS MARCADAS: %s\n\n", matriz_dia_semana[diaDaSemana]);

    for(int codigoConsulta = 1; codigoConsulta <= maximoConsultasPorDia; codigoConsulta++)
    {
        struct Consulta consulta = matriz_consulta[diaDaSemana][codigoConsulta];

        if(consulta.Codigo > 0)
        {
            ExibirConsulta(consulta);
            printf("......................................\n");
        }
    }

    printf("\nFILTRAR POR MEDICO (s/n)? ");
    char respostaFiltarPorMedico = 'n';
    scanf("%s", &respostaFiltarPorMedico);

    if (respostaFiltarPorMedico == 's' || respostaFiltarPorMedico == 'S')
    {
        LimparTela();
        int codigoMedico = SelecionarMedico();
        struct Medico medico = matriz_medico[codigoMedico];
        LimparTela();

        printf("CONSULTAS MARCADAS: %s\n", matriz_dia_semana[diaDaSemana]);
        printf("MEDICO: %s\n\n", medico.Nome);

        for(int codigoConsulta = 1; codigoConsulta <= maximoConsultasPorDia; codigoConsulta++)
        {
            struct Consulta consulta = matriz_consulta[diaDaSemana][codigoConsulta];

            if(consulta.Codigo > 0 && consulta.CodigoMedico == codigoMedico)
            {
                ExibirConsulta(consulta);
                printf("......................................\n");
            }
        }
    }
}

void ExibirConsulta(struct Consulta consulta)
{
    printf("COD........: %d\n", consulta.Codigo);
    printf("DIA........: %s\n", matriz_dia_semana[consulta.DiaSemana]);
    printf("HORA.......: %s\n", consulta.Hora);

    struct Medico medico = matriz_medico[consulta.CodigoMedico];
    printf("MEDICO.....: %s\n", medico.Nome);

    struct Paciente paciente = matriz_paciente[consulta.CodigoPaciente];
    printf("PACIENTE...: %s\n", paciente.Nome);
}

void LimparTela()
{
    system("cls");
}
