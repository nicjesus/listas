#include <iostream>
#include <cstring>
#include <unistd.h>
#include <ctype.h>
//Permite eliminar a instrução std:: 
using namespace std;

//constante para determinar o tamanho da Struct CadRamal
const int iTam = 3;

//esta variável irá controlar a quantidade de registros na struct de acordo
//com const int iTam = 3;
int iQtdRegistros = 0;

/*
• Categoria 0: não faz ligação.
• Categoria 1: ligação interna.
• Categoria 2: logação local (fixo).
• Categoria 3: ligação local (fixo e celular).
• Categoria 4: ligação local (fixo) e DDD (fixo).
• Categoria 5: ligação local (fixo e celular) e DDD (fixo e celular).
• Categoria 6: ligação local (fixo e celular), DDD (fixo e celular) e DDI.
*/
struct Categoria{
    int    iCodCategoria;
    string sNomeCategoria;
};
/*
•SETEL: Seção de Telecomunicações.
•DIBEN: Divisão de Benefícios.
•PATRIMÔNIO.
•PROTOCOLO.
*/
struct Setor{
    string sSetor;
};
/*
Utilize o Código 500 para a indicação do edifício
sede ou 505 para o edifício localizado na SEPN 505 Asa
Norte.
*/
struct Localizacao{
    int    iCodLocal;
    string sNomeLocal;
};
/*
1. Numero do ramal.
2. Categoria.
3. Setor.
4. Edifício de localização.
5. Sala.
6. Responsável pelo ramal.
7. Responsável pelo ateste da conta telefônica.
*/
struct CadRamal{
   int         iNumRamal;   //range entre 1000 e 2999
   Categoria   VarCategoria;//conforme struct Categorias
   Setor       VarSetor;    //conforme struct Setor
   Localizacao VarLocal;    //conforme struct Localização
   string      sSalaRamal;  //número do andar e mais dois dígitos(sequencial).
   string      sRespRamal;  //Necessário apenas o primeiro nome(usuário do Ramal).
   string      sRespAteste; //Necessário apenas o primeiro nome(usuário que atesta fatura).
};
    
//Prototipação de Funções e Procedimentos    
void CadastroDeRamais(CadRamal *Ramal, CadRamal *pVetor); 

//Crítica da existência de ramal já cadastrado
bool VerificaRamal(CadRamal *pVetor, int &pAux);

//procedimento para imprimir o cadastro
void ImprimirCadastroDeRamais(CadRamal *pVetor);

int main(){
    
    CadRamal VarCadRamal;
 
    CadRamal iVetor[5];//criando um vetor do tipo CadRamal com x elementos
    
    CadRamal *pPonte;//criando um ponteiro para CadRamal

    pPonte = &VarCadRamal;//inicializando o ponteiro com o endereço do tipo CadRamal
        
    if (iQtdRegistros == iTam){//a struct já está cheia
        cout << "\n=======================================================";                
        cout << "\nSr Usuário, não há espaço livre para novos Cadastros!..";
        cout << "\n=======================================================";
        sleep(4);
        return 0;
    }

    //vou entrar com os dados na estrutura
    for (int i = 0; i < iTam; i++){
        //Função para cadastrar Ramais
        CadastroDeRamais(pPonte, &iVetor[i]);
        iVetor[i] = VarCadRamal;//salvando o registro cadastrado no vetor
        iQtdRegistros += 1;//controla a qtd de Registros na struct
    }

    //agora vou imprimir os dados da estrutura
    for (int i = 0; i < iTam; i++){
        system("clear");//limpa o ambiente(tela)
        cout << "\n==============================================================";
        cout << "\nIMPRESSÃO DO CADASTRO DE RAMAIS DO MINISTÉRIO DO MEIO AMBIENTE";
        cout << "\n==============================================================\n";
        
        //procedimento para imprimir o cadastro
        ImprimirCadastroDeRamais(&iVetor[i]);
    }
    
    return 0;
}

//Função para cadastrar Ramais
void CadastroDeRamais(CadRamal *pRamal, CadRamal *pVetor){

    system("clear");//limpa o ambiente(tela)
    
    cout << "\n=================================================";
    cout << "\nCADASTRO DE RAMAIS DO MINISTÉRIO DO MEIO AMBIENTE";
    cout << "\n=================================================\n";

    int iAux = 0;

    do{//Entrada e crítica do número do ramal
        cout << "\nInforme o número do Ramal entre 1000 e 3000 = ";
        cin  >> iAux;
        
        //primeira crítica 
        if (iAux < 999 || iAux > 2999){
           cout << "\nNúmero do Ramal fora do intervalo 1000 até 2999\n";
           sleep(2);
        }

        pVetor = pRamal;//incializando o vetor

        //vou criticar se o ramal já está cadastrado        
        if (!VerificaRamal(pVetor, iAux)){
           cout << "\nNúmero do Ramal já está cadastrado\n";
           sleep(1);
           iAux = -1;//flaguei
        }

        if (iAux != -1){
           pRamal->iNumRamal = iAux;
        }
        
    }while(iAux < 999 || iAux > 2999);

    do{//entrada e crítica da categoria
        cout << "\nInforme o código da Categoria entre 0 e 6 = ";
        cin  >> pRamal->VarCategoria.iCodCategoria;
        cin.ignore();
        //segunda crítica 
        if (pRamal->VarCategoria.iCodCategoria < 0 || 
            pRamal->VarCategoria.iCodCategoria > 6){
           cout << "\nCódigo da Categoria fora do intervalo 0 até 6\n";
           sleep(2);
        }
        
    }while(pRamal->VarCategoria.iCodCategoria < 0 || 
           pRamal->VarCategoria.iCodCategoria > 6);
    
    cout << "\nInforme a descrição da Categoria = ";
    getline(cin, pRamal->VarCategoria.sNomeCategoria);
    
    //garantindo que seja tudo seja letras maíusculas
    for (auto &letra: pRamal->VarCategoria.sNomeCategoria){
        letra = toupper(letra); 
    }
 
    do{//entrada e crítica do setor
        cout << "\nInforme a descrição do Setor = ";
        getline(cin, pRamal->VarSetor.sSetor);

        //terceira crítica 
        if (pRamal->VarSetor.sSetor == " "){
           cout << "\nDescrição do Setor deve ser preenchida\n";
           sleep(2);
        }
        
    }while(pRamal->VarSetor.sSetor == " ");
    
    //garantindo que seja tudo seja letras maíusculas
    for (auto &letra: pRamal->VarSetor.sSetor){
        letra = toupper(letra); 
    }

    do{//entrada e crítica da categoria

        cout << "\nInforme o código da Localização 500 ou 505 = ";
        cin  >> pRamal->VarLocal.iCodLocal;
        cin.ignore();
        
        //quarta crítica 
        if (pRamal->VarLocal.iCodLocal != 500 && pRamal->VarLocal.iCodLocal != 505){
           cout << "\nCódigo da Localização diferente de 500 ou 505\n";
           sleep(2);
        }
        
    }while(pRamal->VarLocal.iCodLocal != 500 && pRamal->VarLocal.iCodLocal != 505);
    
    cout << "\nInforme a descrição da Localização = ";
    getline(cin, pRamal->VarLocal.sNomeLocal);

    //garantindo que seja tudo seja letras maíusculas
    for (auto &letra: pRamal->VarLocal.sNomeLocal){
        letra = toupper(letra); 
    }

    do{//entrada e crítica da sala
        cout << "\nInforme o número do andar + o número da sala = ";
        getline(cin, pRamal->sSalaRamal);

        //quinta crítica 
        if (pRamal->sSalaRamal == " "){
           cout << "\nNúmero do andar + o número da sala deve ser preenchido\n";
           sleep(2);
        }
        
    }while(pRamal->sSalaRamal == " ");

    do{//entrada e crítica do Responsável pelo ramal
        cout << "\nInforme o nome do Responsável pelo Ramal = ";
        getline(cin, pRamal->sRespRamal);

        //sexta crítica 
        if (pRamal->sRespRamal == " "){
           cout << "\nO nome do Responsável pelo Ramal deve ser preenchido\n";
           sleep(2);
        }
        
    }while(pRamal->sRespRamal == " ");
    
    //garantindo que seja tudo seja letras maíusculas
    for (auto &letra: pRamal->sRespRamal){
        letra = toupper(letra); 
    }

    do{//entrada e crítica do Responsável pelo ramal
        cout << "\nInforme o nome do Responsável pelo Ateste = ";
        getline(cin, pRamal->sRespAteste);

        //sétima crítica 
        if (pRamal->sRespAteste == " "){
           cout << "\nO nome do Responsável pelo Ateste deve ser preenchido\n";
           sleep(2);
        }
        
    }while(pRamal->sRespAteste == " ");
    
    //garantindo que seja tudo seja letras maíusculas
    for (auto &letra: pRamal->sRespAteste){
        letra = toupper(letra); 
    }

    return;
}

//Pesquisa por Ramal - crítica do cadastro
bool VerificaRamal(CadRamal *pVetor, int &pAux){

    for (int i = 0; i < iTam; i++){  
        if (pVetor[i].iNumRamal == pAux){
           return false;//nada feito - ramal já cadastrado
        }
    }

    return true; 
    
}

//procedimento para imprimir o cadastro
void ImprimirCadastroDeRamais(CadRamal *pVetor){
    
    cout << "\nRamal                  : " << pVetor->iNumRamal;
    cout << "\nCategoria              : " << pVetor->VarCategoria.iCodCategoria
         << " - ";
    cout << pVetor->VarCategoria.sNomeCategoria;
    cout << "\nSetor                  : " << pVetor->VarSetor.sSetor;
    cout << "\nEdifício               : " << pVetor->VarLocal.iCodLocal
         << " - ";
    cout << pVetor->VarLocal.sNomeLocal;
    cout << "\nSala                   : " << pVetor->sSalaRamal;
    cout << "\nResponsável pelo Ramal : " << pVetor->sRespRamal;
    cout << "\nResponsável pelo Ateste: " << pVetor->sRespAteste;
    cout << "\n==============================================================\n";
    
    sleep(2);//aguarda 10 segundos
    
    return; //este comando é opcional em um procedimento do tipo void

}


