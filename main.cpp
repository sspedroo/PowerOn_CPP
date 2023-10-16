#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>


using namespace std;

struct Aluno {
    int cpf;
    string nomeDoAluno;
    string dataDeNascimento;
    float peso;
    float altura;
    int status;
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
    int status;
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
    int status;
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
    int status;
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
            cout << "Data de nascimento do Aluno(a): ";
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
            cout << "\nNome do Professor(a): ";
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

void deletarMatricula(struct IndiceMatricula indiceMatricula[], struct Matricula matriculas[], int &contador, int codigoDaMatricula, struct IndiceModalidade indiceModalidade[], struct Modalidades modalidades[], int &contadorModalidade){
    int inicio = 0, fim = contador - 1;
    int meio = (inicio + fim) / 2;
    for(; fim >= inicio && codigoDaMatricula != indiceMatricula[meio].codigoMatricula; meio = (inicio + fim) / 2){
        if(codigoDaMatricula > indiceMatricula[meio].codigoMatricula) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    inicio = indiceMatricula[meio].enderecoMatricula;
    if((codigoDaMatricula == indiceMatricula[meio].codigoMatricula) && matriculas[inicio].status == 0){
        matriculas[inicio].status = 1;
        cout <<"Matricula "<< matriculas[inicio].codigoDaMatricula << " excluida"<<endl;
        int modalidadeProcurada = matriculas[inicio].matriculaCodigoDaModalidade;
        int resultadoBuscaModalidade = buscarModalidade(indiceModalidade, contadorModalidade, modalidadeProcurada);
        modalidades[resultadoBuscaModalidade].totalDeAlunos = modalidades[resultadoBuscaModalidade].totalDeAlunos - 1;
    } else {
        cout <<"Matricula não encontrada. "<< endl;
    }
}

void leituraExaustivaAluno(struct IndiceAluno indiceAluno[], struct Aluno aluno[], int contador){
    cout <<"\n\n-------------------------------------------";
    for(int k = 0; k < contador; k++){
        int i = indiceAluno[k].enderecoDoAluno;
        if (aluno[i].status == 0){
            cout << "\n\nNome do aluno(a): " <<aluno[i].nomeDoAluno;
            cout << "\nData de nascimento do aluno(a): " <<aluno[i].dataDeNascimento;
            cout << "\nPeso do aluno(a): " <<aluno[i].peso;
            cout << "\nAltura do aluno(a): " <<aluno[i].altura;
        }
    }
    cout <<"\n\n-------------------------------------------";
    cout << "\nDigite qualquer tecla para sair.";
}

void leituraExaustivaProfessor(struct IndiceProfessor indiceProfessor[], struct Professores professores[], int contador){
    cout <<"\n\n----------------------------------------------------";
    for(int k = 0; k < contador; k++){
        int i = indiceProfessor[k].enderecoProfessor;
        if(professores[i].status == 0){
            cout <<"\n\nNome do professor(a): " <<professores[i].nomeDoProfessor;
            cout <<"\nEndereço do professor(a): "<<professores[i].enderecoDoProfessor;
            cout <<"\nTelefone do professor(a): "<<professores[i].telefoneDoProfessor;
        }
    }
    cout <<"\n\n---------------------------------------------------";
    cout << "\nDigite qualquer tecla para sair.";
}

void leituraExaustivaModalidade(struct IndiceModalidade indiceModalidade[], struct Modalidades modalidades[], int contador, struct IndiceProfessor indiceProfessor[], struct Professores professores[], int contadorProfessor){
    cout <<"\n\n-------------------------------------------";
    for(int k = 0; k < contador; k++){
        int i = indiceModalidade[k].enderecoModalidade;
        if(modalidades[i].status == 0){
            cout << "\n\nDescrição da modalidade: " << modalidades[i].descricaoDaModalidade;
            cout << "\nValor: " << modalidades[i].valorDaAula;
            cout << "\nAlunos matriculados: " << modalidades[i].totalDeAlunos;
            cout << "\nLimite de alunos: " << modalidades[i].limiteDeAlunos;
            cout << "\nCodigo do Professor(a): " << modalidades[i].modalidadeCodigoDoProfessor;
            int professorProcurado = modalidades[i].modalidadeCodigoDoProfessor;
            int resultadoBuscaProfessor = buscarProfessor(indiceProfessor, contadorProfessor, professorProcurado);
            cout << "\nNome do Professor(a): " << professores[resultadoBuscaProfessor].nomeDoProfessor;
        }
    }
    cout <<"\n\n-------------------------------------------";
    cout << "\nDigite qualquer tecla para sair.";
}

void leituraExaustivaMatricula(struct IndiceMatricula indiceMatricula[], struct Matricula matriculas[], int contadorMatricula, struct IndiceModalidade indiceModalidade[], struct Modalidades modalidades[], int contadorModalidade, struct IndiceAluno indiceAluno[], struct Aluno aluno[], int &contadorAluno){
    cout <<"\n\n-------------------------------------------";
    for(int k = 0; k < contadorMatricula; k++){
        int i = indiceMatricula[k].enderecoMatricula;
        if(matriculas[i].status == 0){
            int cpfProcurado = matriculas[i].cpfDoAluno;
            int resultadobuscarAluno = buscarAluno(indiceAluno, contadorAluno, cpfProcurado);
            cout <<"\n\nCPF do Aluno: " << aluno[resultadobuscarAluno].cpf;
            cout <<"\nNome do aluno: " << aluno[resultadobuscarAluno].nomeDoAluno;
            cout <<"\nCodigo da modalidade: " << matriculas[i].matriculaCodigoDaModalidade;
            cout <<"\nQuantidade de aulas: " << matriculas[i].quantidadeDeAulas;
        }
    }
    cout <<"\n\n-------------------------------------------";
    cout << "\nDigite qualquer tecla para sair.";
}

void calcularLucro(struct IndiceModalidade indiceModalidade[], struct Modalidades modalidades[], struct IndiceMatricula indiceMatricula[], struct Matricula matricula[], struct IndiceProfessor indiceProfessor[], struct Professores professores[], int &contadorModalidade, int &contadorMatricula, int &contadorProfessor){
    int codigoDaModalidade;
    cout << "Digite o código da modalidade: ";
    cin >> codigoDaModalidade;

     int resultadoBuscaModalidade = buscarModalidade(indiceModalidade, contadorModalidade, codigoDaModalidade);
     float valorDaAula = modalidades[resultadoBuscaModalidade].valorDaAula;
     int codigoDoProfessor = modalidades[resultadoBuscaModalidade].modalidadeCodigoDoProfessor;
     int resultadobuscaProfessor = buscarProfessor(indiceProfessor, contadorProfessor, codigoDoProfessor);
     cout << "\nDescrição: " << modalidades[resultadoBuscaModalidade].descricaoDaModalidade;
     cout << "\nProfessor(a): " << professores[resultadobuscaProfessor].nomeDoProfessor;

     int quantidadeDeAula = 0;
     for(int i = 0; i < contadorMatricula; i++){
         if(codigoDaModalidade == matricula[i].matriculaCodigoDaModalidade){
             quantidadeDeAula += matricula[i].quantidadeDeAulas;
         }
     }
     cout <<"\nQuantidade de aula: " << quantidadeDeAula;
     float lucro = quantidadeDeAula * valorDaAula;
     cout << "\nLucro: " << lucro;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Aluno aluno[8] = {
            {.cpf = 4444, .nomeDoAluno = "Pedro", .dataDeNascimento = "16/10/1998", .peso = 80, .altura = 1.80, .status = 0},
            {.cpf = 6666, .nomeDoAluno = "Raquel", .dataDeNascimento = "11/05/2004", .peso = 60, .altura = 1.60, .status = 0},
            {.cpf = 2222, .nomeDoAluno = "Isabela", .dataDeNascimento = "16/02/2004", .peso = 67, .altura = 1.63, .status = 0},
            {.cpf = 8888, .nomeDoAluno = "Gabriel", .dataDeNascimento = "21/06/1998", .peso = 92, .altura = 1.80, .status = 0}
    };

    IndiceAluno indiceAluno[8] = {
            {.cpfIndice = 2222, .enderecoDoAluno = 2},
            {.cpfIndice = 4444, .enderecoDoAluno = 0},
            {.cpfIndice = 6666, .enderecoDoAluno = 1},
            {.cpfIndice = 8888, .enderecoDoAluno = 3}
    };

    Professores professores[8] = {
            {.codigoDoProfessor = 10, .nomeDoProfessor = "Wilson", .enderecoDoProfessor = "Rui Barbosa, 233", .telefoneDoProfessor = "18 99977 - 9999", .status = 0},
            {.codigoDoProfessor = 30, .nomeDoProfessor = "Luciana", .enderecoDoProfessor = "Vicente de Carvalho, 700", .telefoneDoProfessor = "18 99666 - 6666", .status = 0},
            {.codigoDoProfessor = 20, .nomeDoProfessor = "Hugo", .enderecoDoProfessor = "André Perine, 33", .telefoneDoProfessor = "18 98181 - 8181", .status = 0},
            {.codigoDoProfessor = 40, .nomeDoProfessor = "Rafaela", .enderecoDoProfessor = "Luiz Pizza, 2623", .telefoneDoProfessor = "18 99696 - 6969", .status = 0}
    };

    IndiceProfessor indiceProfessor[8] = {
            {.codigoProfessor = 10, .enderecoProfessor = 0},
            {.codigoProfessor = 20, .enderecoProfessor = 2},
            {.codigoProfessor = 30, .enderecoProfessor = 1},
            {.codigoProfessor = 40, .enderecoProfessor = 3}
    };

    Modalidades modalidades[8] = {
            {.codigoDaModalidade = 100, .descricaoDaModalidade = "Sppining", .modalidadeCodigoDoProfessor = 40, .valorDaAula = 79.90, .limiteDeAlunos = 15, .totalDeAlunos = 14, .status = 0},
            {.codigoDaModalidade = 300, .descricaoDaModalidade = "Musculação", .modalidadeCodigoDoProfessor = 10, .valorDaAula = 60.00, .limiteDeAlunos = 50, .totalDeAlunos = 49, .status = 0},
            {.codigoDaModalidade = 200, .descricaoDaModalidade = "Muay Thai", .modalidadeCodigoDoProfessor = 20, .valorDaAula = 99.90, .limiteDeAlunos = 10, .totalDeAlunos = 8, .status = 0},
            {.codigoDaModalidade = 400, .descricaoDaModalidade = "Pilates", .modalidadeCodigoDoProfessor = 30, .valorDaAula = 110.00, .limiteDeAlunos = 8, .totalDeAlunos = 6, .status = 0}
    };

    IndiceModalidade indiceModalidade[8] = {
            {.codigoModalidade = 100, .enderecoModalidade = 0},
            {.codigoModalidade = 200, .enderecoModalidade = 2},
            {.codigoModalidade = 300, .enderecoModalidade = 1},
            {.codigoModalidade = 400, .enderecoModalidade = 3}
    };

    Matricula matricula[8] = {
            {.codigoDaMatricula = 2, .cpfDoAluno = 4444, .matriculaCodigoDaModalidade = 400, .quantidadeDeAulas = 10, .status = 0},
            {.codigoDaMatricula = 3, .cpfDoAluno = 8888, .matriculaCodigoDaModalidade = 200, .quantidadeDeAulas = 8, .status = 0},
            {.codigoDaMatricula = 4, .cpfDoAluno = 6666, .matriculaCodigoDaModalidade = 100, .quantidadeDeAulas = 6, .status = 0},
            {.codigoDaMatricula = 1, .cpfDoAluno = 2222, .matriculaCodigoDaModalidade = 300, .quantidadeDeAulas = 4, .status = 0}
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

    int escolha;

    while(escolha != 99) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "----------------------------------"<<endl;
        cout <<"******* Academia PowerOn *********"<<endl;
        cout <<"\n";
        cout <<"****ALUNOS****"<<endl;
        SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
        cout <<"1 - Cadastrar novo aluno(a)"<<endl;
        cout <<"2 - Excluir aluno(a)"<<endl;
        cout <<"3 - Ver todos os alunos"<<endl;
        cout <<"\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout <<"****PROFESSORES****"<<endl;
        SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
        cout <<"4 - Cadastrar novo professor(a)"<<endl;
        cout <<"5 - Excluir professor(a)"<<endl;
        cout <<"6 - Ver todos os professores"<<endl;
        cout <<"\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout <<"****MODALIDADES****"<<endl;
        SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
        cout <<"7 - Cadastrar nova modalidade"<<endl;
        cout <<"8 - Excluir modalidade"<<endl;
        cout <<"9 - Ver todas modalidades"<<endl;
        cout <<"\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout <<"****MATRICULAS****"<<endl;
        SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
        cout <<"10 - Cadastrar nova matricula"<<endl;
        cout <<"11 - Excluir matricula"<<endl;
        cout <<"12 - Ver todas matriculas"<<endl;
        cout <<"\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout <<"****FUNÇÕES ADICIONAIS****"<<endl;
        SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
        cout <<"13 - Calcular lucro de modalidade"<<endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout <<"99 - Encerrar o programa"<<endl;
        SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
        cout <<"\nEscolha uma opção: ";
        cin >> escolha;
        system("cls");

        switch (escolha) {
            case 1:
                cout << "Cadastre até 4 alunos"<<endl;
                inserirNovoAluno(aluno, indiceAluno, contadorAluno);
                getch();
                system("cls");
                break;
            case 2:
                int cpfDoAluno;
                cout << "Digite o CPF do aluno que deseja excluir: "<<endl;
                cin >> cpfDoAluno;
                deletarAluno(indiceAluno, aluno, contadorAluno, cpfDoAluno);
                getch();
                system("cls");
                break;
            case 3:
                cout <<"\a\t\tLista de alunos"<<endl;
                leituraExaustivaAluno(indiceAluno, aluno, contadorAluno);
                getch();
                system("cls");
                break;
            case 4:
                cout << "Cadastre até 4 professores"<<endl;
                inserirNovoProfessor(professores, indiceProfessor, contadorProfessor);
                getch();
                system("cls");
                break;
            case 5:
                int codigoDoProfessor;
                cout <<"Digite o código do professor que deseja excluir: "<<endl;
                cin >> codigoDoProfessor;
                deletarProfessor(indiceProfessor, professores, contadorProfessor, codigoDoProfessor);
                getch();
                system("cls");
                break;
            case 6:
                cout <<"\a\t\tLista de professores"<<endl;
                leituraExaustivaProfessor(indiceProfessor, professores, contadorProfessor);
                getch();
                system("cls");
                break;
            case 7:
                cout << "Cadastre até 4 modalidades: "<<endl;
                inserirNovaModalidade(modalidades, indiceModalidade, contadorModalidade, professores, indiceProfessor, contadorProfessor);
                getch();
                system("cls");
                break;
            case 8:
                int codigoDaModalidade;
                cout << "Digite o código da modalidade que deseja excluir: "<<endl;
                cin >> codigoDaModalidade;
                deletarModalidade(indiceModalidade, modalidades, contadorModalidade, codigoDaModalidade);
                getch();
                system("cls");
                break;
            case 9:
                cout <<"\a\tLista de modalidades"<<endl;
                leituraExaustivaModalidade(indiceModalidade, modalidades, contadorModalidade, indiceProfessor, professores, contadorProfessor);
                getch();
                system("cls");
                break;
            case 10:
                cout <<"Cadastre até 4 matriculas"<<endl;
                inserirNovaMatricula(matricula, indiceMatricula, contadorMatricula, aluno, indiceAluno, contadorAluno, modalidades, indiceModalidade, contadorModalidade);
                getch();
                system("cls");
                break;
            case 11:
                int codigoDaMatricula;
                cout << "Digite o código da matricula que deseja excluir: " <<endl;
                cin >> codigoDaMatricula;
                deletarMatricula(indiceMatricula,matricula, contadorMatricula, codigoDaMatricula, indiceModalidade, modalidades, contadorModalidade);
                getch();
                system("cls");
                break;
            case 12:
                cout <<"\a\tLista de Matriculas"<<endl;
                leituraExaustivaMatricula(indiceMatricula, matricula, contadorMatricula, indiceModalidade, modalidades, contadorModalidade, indiceAluno, aluno, contadorAluno);
                getch();
                system("cls");
                break;
            case 13:
                calcularLucro(indiceModalidade, modalidades, indiceMatricula, matricula, indiceProfessor, professores, contadorModalidade, contadorMatricula, contadorProfessor);
                getch();
                system("cls");
                break;
            case 99:
                cout << "Programa finalizado";
                escolha = 99;
                break;
            default:
                cout << "Escolha inválida!";
                getch();
                system("cls");
                break;
        }
    }
    return 0;
}