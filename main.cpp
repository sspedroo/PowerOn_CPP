#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <cstring>
#include <vector>

using namespace std;

struct Aluno {
    int cpf;
    string nomeDoAluno;
    string dataDeNascimento;
    float peso;
    float altura;
    int status = 0;
};

struct IndiceAluno {
    int cpfIndice;
    int enderecoDoAluno;
};

struct Professores {
    int codigoDoProfessor;
    string nomeDoProfessor;
    string enderecoDoProfessor;
    string telefoneDoProfessor;
    int status = 0;
};

struct IndiceProfessor {
    int codigoProfessor;
    int enderecoProfessor;
};

struct Modalidades {
    int codigoDaModalidade;
    string descricaoDaModalidade;
    int modalidadeCodigoDoProfessor;
    float valorDaAula;
    int limiteDeAlunos;
    int totalDeAlunos;
    int status = 0;
};

struct IndiceModalidade {
    int codigoModalidade;
    int enderecoModalidade;
};

struct Matricula {
    int codigoDaMatricula;
    int cpfDoAluno;
    int matriculaCodigoDaModalidade;
    int quantidadeDeAulas;
    int status = 0;
};

struct IndiceMatricula {
    int codigoMatricula;
    int enderecoMatricula;
};

float calcularImc(float peso, float altura) {
    return peso / (altura * altura);
}

int buscarAluno(struct IndiceAluno indiceAluno[], int contador, int cpfDoAluno) {
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for (; fim >= inicio && cpfDoAluno != indiceAluno[meio].cpfIndice; meio = (inicio + fim) / 2) {
        if (cpfDoAluno > indiceAluno[meio].cpfIndice) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if (cpfDoAluno == indiceAluno[meio].cpfIndice) {
        return indiceAluno[meio].enderecoDoAluno;
    } else {
        return -1;
    }
}

int buscarProfessor(struct IndiceProfessor indiceProfessor[], int contador, int codigoDoProfessor) {
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for (; fim >= inicio && codigoDoProfessor != indiceProfessor[meio].codigoProfessor; meio = (inicio + fim) / 2) {
        if (codigoDoProfessor > indiceProfessor[meio].codigoProfessor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if (codigoDoProfessor == indiceProfessor[meio].codigoProfessor) {
        return indiceProfessor[meio].enderecoProfessor;
    } else {
        return -1;
    }
}

int buscarModalidade(struct IndiceModalidade indiceModalidade[], int contador, int codigoModalidade) {
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for (; fim >= inicio && codigoModalidade != indiceModalidade[meio].codigoModalidade; meio = (inicio + fim) / 2) {
        if (codigoModalidade > indiceModalidade[meio].codigoModalidade) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if (codigoModalidade == indiceModalidade[meio].codigoModalidade) {
        return indiceModalidade[meio].enderecoModalidade;
    } else {
        return -1;
    }
}

int buscarMatricula(struct IndiceMatricula indiceMatricula[], int contador, int codigoDaMatricula) {
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for (; fim >= inicio && codigoDaMatricula != indiceMatricula[meio].codigoMatricula; meio = (inicio + fim) / 2) {
        if (codigoDaMatricula > indiceMatricula[meio].codigoMatricula) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if (codigoDaMatricula == indiceMatricula[meio].codigoMatricula) {
        return indiceMatricula[meio].enderecoMatricula;
    } else {
        return -1;
    }
}

void inserirNovoAluno(struct Aluno aluno[], struct IndiceAluno indiceAluno[], int &contador) {
    cout << "************* CADASTRAR NOVOS ALUNOS ****************";
    const int tamanhoMaximoVetor = 8;

    for (int i = 4; i < tamanhoMaximoVetor;) {

        cout << "\nQUAL INDICE QUE EU TO?: " << i;

        bool isExisting = false;
        while (!isExisting) {

            cout << "\n\n*Digite o CPF do aluno (padrão 8888) " << "(digite 0 para sair): ";
            cin >> aluno[i].cpf;

            if (aluno[i].cpf == 0) {
                break;
            }

            int validarCpf = buscarAluno(indiceAluno, contador, aluno[i].cpf);
            if (validarCpf != -1) {
                cout << "CPF já cadastrado para aluno(a): " << aluno[validarCpf].nomeDoAluno;
            } else {
                isExisting = true;
            }
        }
        if (aluno[i].cpf == 0) {
            break;
        }
        bool nomeAlunoNaoVazio = false;
        while (!nomeAlunoNaoVazio) {
            cout << "\nNome do Aluno(a): ";
            cin.ignore();
            getline(cin, aluno[i].nomeDoAluno);
            if (aluno[i].nomeDoAluno != "") {
                nomeAlunoNaoVazio = true;
            } else {
                cout << "Nome do aluno(a) não pode estar vazio!" << endl;
            }
        }

        bool dataDeNascimentoNaoVazia = false;
        while (!dataDeNascimentoNaoVazia) {
            cout << "\nData de nascimento do Aluno(a): ";
            getline(cin, aluno[i].dataDeNascimento);
            if (aluno[i].dataDeNascimento != "") {
                dataDeNascimentoNaoVazia = true;
            } else {
                cout << "Data de nascimento do aluno não pode ser vazia!" << endl;
            }
        }

        cout << "Peso do Aluno(a): ";
        cin >> aluno[i].peso;
        cout << "Altura do aluno(a): ";
        cin >> aluno[i].altura;
        float imc = calcularImc(aluno[i].peso, aluno[i].altura);
        cout << "\nO IMC do aluno(a) é: " << imc << endl;

        if (imc < 18.5) {
            cout << "O aluno(a) " << aluno[i].nomeDoAluno << " está com Magreza segundo os padrões IMC" << endl;
        } else if (imc >= 18.5 && imc <= 24.99) {
            cout << "O aluno(a) " << aluno[i].nomeDoAluno << " está com Peso normal segundo os padrões IMC" << endl;
        } else if (imc >= 25 && imc <= 29.99) {
            cout << "O aluno(a) " << aluno[i].nomeDoAluno << " está com Sobrepeso segundo os padrões IMC" << endl;
        } else if (imc >= 30 && imc <= 34.99) {
            cout << "O aluno " << aluno[i].nomeDoAluno << " está com Obesidade grau I segundo os padrões IMC" << endl;
        } else if (imc >= 35 && imc <= 39.99) {
            cout << "O aluno " << aluno[i].nomeDoAluno << " está com Obesidade grau II segundo os padrões IMC" << endl;
        } else {
            cout << "O aluno(a) " << aluno[i].nomeDoAluno << " está com Obesidade grau III segundo os padrões IMC"
                 << endl;
        }
        int j;
        for (j = contador - 1; j >= 0 && aluno[i].cpf < indiceAluno[j].cpfIndice; j--) {
            indiceAluno[j + 1] = indiceAluno[j];
        }
        indiceAluno[j + 1].cpfIndice = aluno[i].cpf;
        indiceAluno[j + 1].enderecoDoAluno = i;
        cout << "\n***Aluno cadastrado com Sucesso***" << endl;
        contador++;
        i++;
    }

    cout << "\n\nSaindo da inserção de alunos..." << endl;
    cin.ignore();
};

void inserirNovoProfessor(struct Professores professores[], struct IndiceProfessor indiceProfessor[], int &contador) {
    cout << "\n\n\n************* CADASTRAR NOVOS PROFESSORES ****************";
    const int tamanhoMaximoVetor = 8;
    for (int i = 4; i < tamanhoMaximoVetor;) {
        cout << "\nQUAL INDICE QUE EU TO?: " << i;

        bool isExisting = false;
        while (!isExisting) {
            cout << "\n\n*Digite o código do professor (padrão 88) " << "(digite 0 para sair): ";
            cin >> professores[i].codigoDoProfessor;
            if (professores[i].codigoDoProfessor == 0) {
                break;
            }
            int validaCodigo = buscarProfessor(indiceProfessor, contador, professores[i].codigoDoProfessor);
            if (validaCodigo != -1) {
                cout << "Código ja cadastrado para o professor(a): " << professores[validaCodigo].nomeDoProfessor;
            } else {
                isExisting = true;
            }
        }
        if (professores[i].codigoDoProfessor == 0) {
            break;
        }

        bool nomeProfessorNaoVazio = false;
        while (!nomeProfessorNaoVazio) {
            cout << "Nome do Professor(a): ";
            cin.ignore();
            getline(cin, professores[i].nomeDoProfessor);
            if (professores[i].nomeDoProfessor != "") {
                nomeProfessorNaoVazio = true;
            } else {
                cout << "Nome do professor não estar vazio!" << endl;
            }
        }

        bool enderecoNaoVazio = false;
        while (!enderecoNaoVazio) {
            cout << "Endereço do professor(a): ";
            getline(cin, professores[i].enderecoDoProfessor);
            if (professores[i].enderecoDoProfessor != "") {
                enderecoNaoVazio = true;
            } else {
                cout << "Endereço não pode ser vazio" << endl;
            }
        }

        bool telefoneNaoVazio = false;
        while (!telefoneNaoVazio) {
            cout << "Telefone do professor(a): ";
            getline(cin, professores[i].telefoneDoProfessor);
            if (professores[i].telefoneDoProfessor != "") {
                telefoneNaoVazio = true;
            } else {
                cout << "Telefone não pode ser vazio" << endl;
            }
        }

        int j;
        for (j = contador - 1; j >= 0 && professores[i].codigoDoProfessor < indiceProfessor[j].codigoProfessor; j--) {
            indiceProfessor[j + 1] = indiceProfessor[j];
        }
        indiceProfessor[j + 1].codigoProfessor = professores[i].codigoDoProfessor;
        indiceProfessor[j + 1].enderecoProfessor = i;
        cout << "\n***Professor cadastrado com Sucesso***" << endl;
        contador++;
        i++;
    }
    cout << "\n\nSaindo da inserção de professores...." << endl;
    cin.ignore();
}

void inserirNovaModalidade(struct Modalidades modalidades[], struct IndiceModalidade indiceModalidade[], int &contador,
                           struct Professores professores[], struct IndiceProfessor indiceProfessor[],
                           int &contadorProfessor) {
    cout << "\n\n\n************* CADASTRAR NOVAS MODALIDADES ****************";

    const int tamanhoMaximoVetor = 8;

    for (int i = 4; i < tamanhoMaximoVetor;) {
        cout << "\nQUAL INDICE QUE EU TO?: " << i;

        bool isExisting = false;
        while (!isExisting) {
            cout << "\n\n*Digite o código da Modalidade (padrão 88) " << "(digite 0 para sair): ";
            cin >> modalidades[i].codigoDaModalidade;
            if (modalidades[i].codigoDaModalidade == 0) {
                break;
            }
            int validarCodigo = buscarModalidade(indiceModalidade, contador, modalidades[i].codigoDaModalidade);
            if (validarCodigo != -1) {
                cout << "Codigo já cadastrado para Modalidade: " << modalidades[validarCodigo].descricaoDaModalidade;
            } else {
                isExisting = true;
            }
        }
        if (modalidades[i].codigoDaModalidade == 0) {
            break;
        }
        cin.ignore();
        bool descricaoNaoVazia = false;
        while (!descricaoNaoVazia) {
            cout << "\nDescrição da Modalidade: ";
//            cin.ignore();
            getline(cin, modalidades[i].descricaoDaModalidade);
            if (modalidades[i].descricaoDaModalidade != "") {
                descricaoNaoVazia = true;
            } else {
                cout << "Descrição não pode ser vazia" << endl;
            }
        }

        cout << "\nTotal de alunos cadastrados na Modalidade: ";
        cin >> modalidades[i].totalDeAlunos;

        bool maiorQue0 = false;
        while (!maiorQue0) {
            cout << "\nLimite de alunos que podem estar cadastrado na Modalidade: ";
            cin >> modalidades[i].limiteDeAlunos;
            if (modalidades[i].limiteDeAlunos <= 0) {
                cout << "Limite deve ser maior que 0" << endl;
            } else if(modalidades[i].totalDeAlunos > modalidades[i].limiteDeAlunos){
                cout <<"O limite deve ser maior que o numero de cadastrados"<<endl;
            } else {
                maiorQue0 = true;
            }
        }
        cout << "\nValor da aula da Modalidade: ";
        cin >> modalidades[i].valorDaAula;

        bool encontrouProfessor = false;
        while (!encontrouProfessor) {
            cout << "\nCódigo do professor da Modalidade: ";
            cin >> modalidades[i].modalidadeCodigoDoProfessor;
            int codigoASerProcurado = modalidades[i].modalidadeCodigoDoProfessor;
            int resultadoBuscarProfessor = buscarProfessor(indiceProfessor, contadorProfessor, codigoASerProcurado);
            if (resultadoBuscarProfessor == -1) {
                cout << "Professor não encontrado, digite um código existente";
            } else {
                cout << "Professor(a): " << professores[resultadoBuscarProfessor].nomeDoProfessor << endl;
                encontrouProfessor = true;
            }
        }

        int j;
        for (j = contador - 1;
             j >= 0 && modalidades[i].codigoDaModalidade < indiceModalidade[j].codigoModalidade; j--) {
            indiceModalidade[j + 1] = indiceModalidade[j];
        }
        indiceModalidade[j + 1].codigoModalidade = modalidades[i].codigoDaModalidade;
        indiceModalidade[j + 1].enderecoModalidade = i;
        cout << "\n***Modalidade cadastrada com Sucesso***" << endl;
        contador++;
        i++;
    }
    cout << "\n\nSaindo da inserção de modalidades....";
    cin.ignore();
}

void inserirNovaMatricula(struct Matricula matriculas[], struct IndiceMatricula indiceMatricula[], int &contador,
                          struct Aluno aluno[], struct IndiceAluno indiceAluno[], int &contadorAluno,
                          struct Modalidades modalidades[], struct IndiceModalidade indiceModalidade[],
                          int &contadorModalidade) {
    cout << "\n\n\n************* CADASTRAR NOVAS MATRICULAS ****************";
    const int tamanhoMaximoVetor = 8;

    for(int i = 4; i < tamanhoMaximoVetor;){
        cout << "\nQUAL INDICE QUE EU TO?: " << i;

        bool isExisting = false;
        while(!isExisting) {
            cout << "\n\n*Digite o código da Matricula" << "(digite 0 para sair): ";
            cin >> matriculas[i].codigoDaMatricula;
            if (matriculas[i].codigoDaMatricula == 0) {
                break;
            }
            int validarCodigo = buscarMatricula(indiceMatricula, contador, matriculas[i].codigoDaMatricula);
            if (validarCodigo != -1) {
                cout << "Codigo já cadastrado na matricula do CPF: " << matriculas[validarCodigo].cpfDoAluno << endl;
            } else {
                isExisting = true;
            }
        }
        if (matriculas[i].codigoDaMatricula == 0) {
            break;
        }

        bool isExistingCPF = false;
        while(!isExistingCPF){
            cout << "Digite o CPF do aluno: ";
            cin >> matriculas[i].cpfDoAluno;
            int cpfProcurado = matriculas[i].cpfDoAluno;
            int resultadoBuscaCpf = buscarAluno(indiceAluno, contadorAluno, cpfProcurado);
            if (resultadoBuscaCpf != -1) {
                cout << "Nome do Aluno(a): " << aluno[resultadoBuscaCpf].nomeDoAluno << endl;
                isExistingCPF = true;
            } else {
                cout << "Aluno(a) não encontrado." << endl;
            }
        }

        bool isExistingModalidade = false;
        while(!isExistingModalidade){
            cout << "Digite o código da modalidade: ";
            cin >> matriculas[i].matriculaCodigoDaModalidade;
            int modalidadeProcurada = matriculas[i].matriculaCodigoDaModalidade;
            int resultadoBuscaModalidade = buscarModalidade(indiceModalidade, contadorModalidade, modalidadeProcurada);
            if(resultadoBuscaModalidade != -1){
                cout << "Modalidade: " << modalidades[resultadoBuscaModalidade].descricaoDaModalidade << endl;
            } else {
                cout <<"Modalidade não encontrada." <<endl;
                continue;
            }
            int pessoasCadastradasNaModalidade = modalidades[resultadoBuscaModalidade].totalDeAlunos;
            int limiteDePessoasNaModalidade = modalidades[resultadoBuscaModalidade].limiteDeAlunos;

            if (pessoasCadastradasNaModalidade < limiteDePessoasNaModalidade) {
                cout << "\nHá vagas disponiveis nessa modalidade" << endl;
                modalidades[resultadoBuscaModalidade].totalDeAlunos = modalidades[resultadoBuscaModalidade].totalDeAlunos + 1;
                cout << "\n****Aluno matriculado com sucesso!" << endl;
                cout << "\nAlunos matriculados: " << modalidades[resultadoBuscaModalidade].totalDeAlunos << endl;
                cout << "Limite de alunos da modalidade: " << limiteDePessoasNaModalidade << endl;
                isExistingModalidade = true;
            } else {
                cout << "\nNão há vagas disponíveis nessa modalidade." << endl;
            }
        }
        bool isMaiorQue0 = false;
        while(!isMaiorQue0){
            cout << "Quantidade de aulas: ";
            cin >> matriculas[i].quantidadeDeAulas;

            if(matriculas[i].quantidadeDeAulas <= 0){
                cout << "O numero de aulas não pode ser igual ou menor que 0" <<endl;
            } else {
                isMaiorQue0 = true;
            }
        }
        int j;
        for (j = contador - 1; j >= 0 && matriculas[i].codigoDaMatricula < indiceMatricula[j].codigoMatricula; j--) {
            indiceMatricula[j + 1] = indiceMatricula[j];
        }
        indiceMatricula[j + 1].codigoMatricula = matriculas[i].codigoDaMatricula;
        indiceMatricula[j + 1].enderecoMatricula = i;
        cout << "\n***Matricula cadastrada com Sucesso***" << endl;
        contador++;
        i++;
    }

}

void deletarAluno(struct IndiceAluno indiceAluno[], struct Aluno aluno[], int &contador, int cpfDoAluno){
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for (; fim >= inicio && cpfDoAluno != indiceAluno[meio].cpfIndice; meio = (inicio + fim) / 2) {
        if (cpfDoAluno > indiceAluno[meio].cpfIndice) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    inicio = indiceAluno[meio].enderecoDoAluno;
    if ((cpfDoAluno == indiceAluno[meio].cpfIndice) && aluno[inicio].status == 0){
        aluno[inicio].status = 1;
        cout << "Aluno(a) " << aluno[inicio].nomeDoAluno <<" excluido" <<endl;
    } else {
        cout << "Aluno(a) não encontrado." <<endl;
    }
}

void deletarProfessor(struct IndiceProfessor indiceProfessor[], struct Professores professores[], int &contador, int codigoDoProfessor){
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for (; fim >= inicio && codigoDoProfessor != indiceProfessor[meio].codigoProfessor; meio = (inicio + fim) / 2) {
        if (codigoDoProfessor > indiceProfessor[meio].codigoProfessor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    inicio = indiceProfessor[meio].enderecoProfessor;
    if((codigoDoProfessor == indiceProfessor[meio].codigoProfessor) && professores[inicio].status == 0){
        professores[inicio].status = 1;
        cout << "Professor(a) " << professores[inicio].nomeDoProfessor <<" excluido" <<endl;
    } else {
        cout << "Professor(a) não encontrado." <<endl;
    }
}

void deletarModalidade(struct IndiceModalidade indiceModalidade[], struct Modalidades modalidades[], int &contador, int codigoDaModalidade){
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for (; fim >= inicio && codigoDaModalidade != indiceModalidade[meio].codigoModalidade; meio = (inicio + fim) / 2) {
        if (codigoDaModalidade > indiceModalidade[meio].codigoModalidade) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    inicio = indiceModalidade[meio].enderecoModalidade;
    if((codigoDaModalidade == indiceModalidade[meio].codigoModalidade) && modalidades[inicio].status == 0){
        modalidades[inicio].status = 1;
        cout << "Modalidade " << modalidades[inicio].descricaoDaModalidade << " excluida"<<endl;
    } else {
        cout << "Modalidade não encontrada." <<endl;
    }
}

void deletarMatricula(){

}

void leituraExaustivaAluno(struct IndiceAluno indiceAluno[], struct Aluno aluno[], int contador){
    for(int k = 0; k < contador; k++){
        int i = indiceAluno[k].enderecoDoAluno;
        if (aluno[i].status == 0){
            cout << "\nNome do aluno(a): " <<aluno[i].nomeDoAluno;
            cout << "\nData de nascimento do aluno(a): " <<aluno[i].dataDeNascimento;
            cout << "\nPeso do aluno(a): " <<aluno[i].peso;
            cout << "\nAltura do aluno(a): " <<aluno[i].altura;
        }
    }
}

void leituraExaustivaProfessor(struct IndiceProfessor indiceProfessor[], struct Professores professores[], int contador){
    for(int k = 0; k < contador; k++){
        int i = indiceProfessor[k].enderecoProfessor;
        if(professores[i].status == 0){
            cout <<"\nNome do professor(a): " <<professores[i].nomeDoProfessor;
            cout <<"\nEndereço do professor(a): "<<professores[i].enderecoDoProfessor;
            cout <<"\nTelefone do professor(a): "<<professores[i].telefoneDoProfessor;
        }
    }
}

void leituraExaustivaModalidade(struct IndiceModalidade indiceModalidade[], struct Modalidades modalidades[], int contador){
    for(int k = 0; k < contador; k++){
        int i = indiceModalidade[k].enderecoModalidade;
        if(modalidades[i].status == 0){
            cout << "\nDescrição da modalidade: "
        }
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    Aluno aluno[8] = {
            {.cpf = 4444, .nomeDoAluno = "Pedro", .dataDeNascimento = "16/10/1998", .peso = 80, .altura = 1.80},
            {.cpf = 6666, .nomeDoAluno = "Raquel", .dataDeNascimento = "11/05/2004", .peso = 60, .altura = 1.60},
            {.cpf = 2222, .nomeDoAluno = "Isabela", .dataDeNascimento = "16/02/2004", .peso = 67, .altura = 1.63},
            {.cpf = 8888, .nomeDoAluno = "Gabriel", .dataDeNascimento = "21/06/1998", .peso = 92, .altura = 1.80}
    };

    IndiceAluno indiceAluno[8] = {
            {.cpfIndice = 2222, .enderecoDoAluno = 2},
            {.cpfIndice = 4444, .enderecoDoAluno = 0},
            {.cpfIndice = 6666, .enderecoDoAluno = 1},
            {.cpfIndice = 8888, .enderecoDoAluno = 3}
    };

    Professores professores[8] = {
            {.codigoDoProfessor = 10, .nomeDoProfessor = "Wilson", .enderecoDoProfessor = "Rui Barbosa, 233", .telefoneDoProfessor = "18 99977 - 9999"},
            {.codigoDoProfessor = 30, .nomeDoProfessor = "Luciana", .enderecoDoProfessor = "Vicente de Carvalho, 700", .telefoneDoProfessor = "18 99666 - 6666"},
            {.codigoDoProfessor = 20, .nomeDoProfessor = "Hugo", .enderecoDoProfessor = "André Perine, 33", .telefoneDoProfessor = "18 98181 - 8181"},
            {.codigoDoProfessor = 40, .nomeDoProfessor = "Rafaela", .enderecoDoProfessor = "Luiz Pizza, 2623", .telefoneDoProfessor = "18 99696 - 6969"}
    };

    IndiceProfessor indiceProfessor[8] = {
            {.codigoProfessor = 10, .enderecoProfessor = 0},
            {.codigoProfessor = 20, .enderecoProfessor = 2},
            {.codigoProfessor = 30, .enderecoProfessor = 1},
            {.codigoProfessor = 40, .enderecoProfessor = 3}
    };

    Modalidades modalidades[8] = {
            {.codigoDaModalidade = 100, .descricaoDaModalidade = "Sppining", .modalidadeCodigoDoProfessor = 40, .valorDaAula = 79.90, .limiteDeAlunos = 15, .totalDeAlunos = 14},
            {.codigoDaModalidade = 300, .descricaoDaModalidade = "Musculação", .modalidadeCodigoDoProfessor = 10, .valorDaAula = 60.00, .limiteDeAlunos = 50, .totalDeAlunos = 49},
            {.codigoDaModalidade = 200, .descricaoDaModalidade = "Muay Thai", .modalidadeCodigoDoProfessor = 20, .valorDaAula = 99.90, .limiteDeAlunos = 10, .totalDeAlunos = 8},
            {.codigoDaModalidade = 400, .descricaoDaModalidade = "Pilates", .modalidadeCodigoDoProfessor = 30, .valorDaAula = 110.00, .limiteDeAlunos = 8, .totalDeAlunos = 6}
    };

    IndiceModalidade indiceModalidade[8] = {
            {.codigoModalidade = 100, .enderecoModalidade = 0},
            {.codigoModalidade = 200, .enderecoModalidade = 2},
            {.codigoModalidade = 300, .enderecoModalidade = 1},
            {.codigoModalidade = 400, .enderecoModalidade = 3}
    };

    Matricula matricula[8] = {
            {.codigoDaMatricula = 2, .cpfDoAluno = 044444, .matriculaCodigoDaModalidade = 400, .quantidadeDeAulas = 10},
            {.codigoDaMatricula = 3, .cpfDoAluno = 055555, .matriculaCodigoDaModalidade = 200, .quantidadeDeAulas = 8},
            {.codigoDaMatricula = 4, .cpfDoAluno = 066666, .matriculaCodigoDaModalidade = 100, .quantidadeDeAulas = 6},
            {.codigoDaMatricula = 1, .cpfDoAluno = 077777, .matriculaCodigoDaModalidade = 300, .quantidadeDeAulas = 4}
    };

    IndiceMatricula indiceMatricula[8] = {
            {.codigoMatricula = 1, .enderecoMatricula = 3},
            {.codigoMatricula = 2, .enderecoMatricula = 0},
            {.codigoMatricula = 3, .enderecoMatricula = 1},
            {.codigoMatricula = 4, .enderecoMatricula = 2}
    };
    int contadorAluno = 4;
    int contadorProfessor = 4;
    int contadorModalidade = 4;
    int contadorMatricula = 4;

    inserirNovoAluno(aluno, indiceAluno, contadorAluno);
    inserirNovoProfessor(professores, indiceProfessor, contadorProfessor);
    inserirNovaModalidade(modalidades, indiceModalidade, contadorModalidade, professores, indiceProfessor,
                          contadorProfessor);
    inserirNovaMatricula(matricula, indiceMatricula, contadorMatricula, aluno, indiceAluno, contadorAluno, modalidades, indiceModalidade, contadorModalidade);

    for (int i = 0; i < 8; i++) {
        cout << "\nAluno " << i + 1 << " -------- " << "\nNome: " << aluno[i].nomeDoAluno << endl;
    }

    for (int i = 0; i < 8; i++) {
        cout << "\nCPF DO ALUNO NO INDICE: " << i + 1 << ": " << indiceAluno[i].cpfIndice << ", "
             << indiceAluno[i].enderecoDoAluno
             << endl;
    }

    for (int i = 0; i < 8; i++) {
        cout << "\nProfessor " << i + 1 << " -------- " << "\nNome: " << professores[i].nomeDoProfessor << endl;
    }

    for (int i = 0; i < 8; i++) {
        cout << "\nCODIGO DO PROFESSOR NO INDICE: " << i + 1 << ": " << indiceProfessor[i].codigoProfessor << ", "
             << indiceProfessor[i].enderecoProfessor
             << endl;
    }

    for (int i = 0; i < 8; i++) {
        cout << "\nModalidade " << i + 1 << " -------- " << "\nNome: " << modalidades[i].descricaoDaModalidade << endl;
    }

    for (int i = 0; i < 8; i++) {
        cout << "\nCODIGO DA MODALIDADE NO INDICE: " << i + 1 << ": " << indiceModalidade[i].codigoModalidade << ", "
             << indiceModalidade[i].enderecoModalidade
             << endl;
    }

    getch();
    return 0;
}