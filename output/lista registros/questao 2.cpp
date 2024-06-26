
#include <iostream>
#include <cstring>
#include <unistd.h>
 
using namespace std;

const int iTam = 1;

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
struct Edificio{
    int    iCodEdificio;
    string sNomeEdificio;
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
   Edificio    VarEdificio; //conforme struct Localização
   string      sSalaRamal;  //número do andar e mais dois dígitos(sequencial).
   string      sRespRamal;  //Necessário apenas o primeiro nome(usuário do Ramal).
   string      sRespAteste; //Necessário apenas o primeiro nome(usuário que atesta fatura).
};
    
//Prototipação de Funções e Procedimentos    
void CadastroDeRamais(CadRamal *pRamal, CadRamal *pVetor); 

//Pesquisa por Ramal, setor, localização, responsáveis (ramal/ateste)
void ListarCadastroParaPesquisa(CadRamal *pVetor, int &pOpc);

//procedimento para imprimir o cadastro
void ImprimirCadastroDeRamais(CadRamal *pVetor);

//Pesquisa nomes no cadastro
bool VerificarExistenciaDoRegistro(CadRamal *pVetor, string pAuxiliar, int &pRamal, int pOpc);

int main(){
    
    //1999 - este valor está definido no enunciado
    CadRamal VarCadRamal;
    
    CadRamal vVetor[iTam];//criando um vetor para 5 elementos

    CadRamal *pRamal;//criando um ponteiro para CadRamal

    pRamal = &VarCadRamal;//inicializando o ponteiro com o endereço de VarCadRamal

    int iOpc, iRamal;
    string sAuxiliar = "";

    do{
        
        system("clear");//limpa o ambiente(tela)
    
        iOpc = 0;
        cout << "\n\t=======================================";
        cout << "\n\tMENU PARA CADASTRO E PESQUISA DE RAMAIS ";
        cout << "\n\t=======================================\n";
        cout << "\n\t   0 para: Número do Ramal.";
        cout << "\n\t   1 para: Setor.";
        cout << "\n\t   2 para: Edifício.";
        cout << "\n\t   3 para: Responsável pelo Ramal.";
        cout << "\n\t   4 para: Responsável pelo Ateste.";
        cout << "\n\t";//   ................................";        
        cout << "\n\t   5 para: Cadastro de Ramais.";
        cout << "\n\t   6 para: Imprimir o Cadastro.";
        cout << "\n\t";//   ................................";         
        cout << "\n\t   7 para: Finalizar o Programa.";        
        cout << "\n\n\t   Informe a Opção desejada = ";
        cin >> iOpc;

        switch(iOpc){
            case 0: 
                
                do{
                    
                    system("clear");//limpa o ambiente(tela)
                    
                    cout << "\n===============";
                    cout << "\nLISTA DE RAMAIS";
                    cout << "\n===============";
                    cout << "\nRamais\n";  
                    
                    for (int i = 0; i < iTam; i++){            
                        ListarCadastroParaPesquisa(&vVetor[i], iOpc);
                        if (iOpc == -1){break;}//nada feito
                    }   
                    
                    if (iOpc == -1){break;}//nada feito
                    
                    cout << "\n\nDigite o número do ramal que deseja pesquisar = ";
                    cin >> iRamal;
    
                    //vou posicionar o registro dentro do vetor
                    if (VerificarExistenciaDoRegistro(vVetor, "", iRamal, iOpc)){//vou utilizar iOpc como flag
                        cout << "\nNúmero do ramal informado não cadastrado!\n";
                        sleep(2);

                    }else{ 
                        //agora vou imprimir na tela o registro posicionado
                        ImprimirCadastroDeRamais(&vVetor[iRamal]);
                        break;
                    }
                    
                }while(true);
                break;
                
            case 1:
                    
                do{
                    system("clear");//limpa o ambiente(tela)
                    
                    cout << "\n================";
                    cout << "\nLISTA DE SETORES";
                    cout << "\n================";
                    cout << "\nSetores\n";  
                    
                    for (int i = 0; i < iTam; i++){            
                        ListarCadastroParaPesquisa(&vVetor[i], iOpc);    
                        if (iOpc == -1){break;}//nada feito
                    }   
                    
                    if (iOpc == -1){break;}//nada feito
                    
                    cout << "\n\nDigite o nome do Setor que deseja pesquisar = ";
                    cin >> sAuxiliar;

                    //vou posicionar o registro dentro do vetor
                    if (VerificarExistenciaDoRegistro(vVetor, sAuxiliar, iRamal, iOpc)){
                        cout << "\nNome do setor informado não cadastrado!\n";
                        sleep(2);

                    }else{ 
                        //agora vou imprimir na tela o registro posicionado
                        ImprimirCadastroDeRamais(&vVetor[iRamal]);
                        break;
                    }
                    
                }while(true);
                break;
                
            case 2:
                    
                do{
                    system("clear");//limpa o ambiente(tela)
                    
                    cout << "\n==================";
                    cout << "\nLISTA DE EDIFÍCIOS";
                    cout << "\n==================";
                    cout << "\nEdifícios\n";  
                    
                    for (int i = 0; i < iTam; i++){            
                        ListarCadastroParaPesquisa(&vVetor[i], iOpc);    
                        if (iOpc == -1){break;}//nada feito
                    }   
                    
                    if (iOpc == -1){break;}//nada feito
                    
                    cout << "\n\nDigite o número do Edifício que deseja pesquisar = ";
                    cin >> iRamal;

                    //vou posicionar o registro dentro do vetor
                    if (VerificarExistenciaDoRegistro(vVetor, "", iRamal, iOpc)){
                        cout << "\nEdifício informado não cadastrado!\n";
                        sleep(2);

                    }else{ 
                        //agora vou imprimir na tela o registro posicionado
                        ImprimirCadastroDeRamais(&vVetor[iRamal]);
                        break;
                    }
                    
                }while(true);
                break;
                
            case 3:
                    
                do{
                    system("clear");//limpa o ambiente(tela)
                    
                    cout << "\n=================================";
                    cout << "\nLISTA DOS RESPONSÁVEIS PELO RAMAL";
                    cout << "\n=================================";
                    cout << "\nResponsáveis\n";  
                    
                    for (int i = 0; i < iTam; i++){            
                        ListarCadastroParaPesquisa(&vVetor[i], iOpc);    
                        if (iOpc == -1){break;}//nada feito
                    }   
                    
                    if (iOpc == -1){break;}//nada feito
                    
                    cout << "\n\nDigite o nome do Responsável que deseja pesquisar = ";
                    cin >> sAuxiliar;
    
                    //vou posicionar o registro dentro do vetor
                    if (VerificarExistenciaDoRegistro(vVetor, sAuxiliar, iRamal, iOpc)){
                        cout << "\nNome do Responsável informado não cadastrado!\n";
                        sleep(2);

                    }else{ 
                        //agora vou imprimir na tela o registro posicionado
                        ImprimirCadastroDeRamais(&vVetor[iRamal]);
                        break;
                    }
                    
                }while(true);
                break;
                
            case 4:
                    
                do{
                    system("clear");//limpa o ambiente(tela)
                    
                    cout << "\n==================================";
                    cout << "\nLISTA DOS RESPONSÁVEIS PELO ATESTO";
                    cout << "\n==================================";
                    cout << "\nResponsáveis\n";  
                    
                    for (int i = 0; i < iTam; i++){            
                        ListarCadastroParaPesquisa(&vVetor[i], iOpc);    
                        if (iOpc == -1){break;}//nada feito
                    }   
                    
                    if (iOpc == -1){break;}//nada feito
                    
                    cout << "\n\nDigite o nome do Responsável que deseja pesquisar = ";
                    cin >> sAuxiliar;
    
                    //vou posicionar o registro dentro do vetor
                    if (VerificarExistenciaDoRegistro(vVetor, sAuxiliar, iRamal, iOpc)){
                        cout << "\nNome do Responsável informado não cadastrado!\n";
                        sleep(2);

                    }else{ 
                        //agora vou imprimir na tela o registro posicionado
                        ImprimirCadastroDeRamais(&vVetor[iRamal]);
                        break;
                    }
                    
                }while(true);
                break;
                
            case 5:   
        
                if (iQtdRegistros == iTam){//a struct já está cheia
                    cout << "\n=======================================================";                
                    cout << "\nSr Usuário, não há espaço livre para novos Cadastros!..";
                    cout << "\n=======================================================\n";
                    sleep(4);
                    break;
                }
            
                for (int i = 0; i < iTam; i++){
                    CadastroDeRamais(pRamal, &vVetor[i]);//Função para cadastrar Ramais
                    vVetor[i] = VarCadRamal; //carregando o vetor com o registro
                    iQtdRegistros += 1;//controla a qtd de Registros na struct
                }
                break;
                
            case 6:     
                    
                system("clear");//limpa o ambiente(tela)
                
                cout << "\n=============================================================";
                cout << "\nLISTAGEM DO CADASTRO DE RAMAIS DO MINISTÉRIO DO MEIO AMBIENTE";
                cout << "\n=============================================================";
        
                if (iQtdRegistros == 0){//a struct está vazia
                    cout << "\n=======================================================";                
                    cout << "\nSr Usuário, não há Registros Cadastros até o momento!..";
                    cout << "\n=======================================================\n";
                    sleep(4);
                    break;
                }
                        
                for (int i = 0; i < iTam; i++){   
                    ImprimirCadastroDeRamais(&vVetor[i]);//procedimento para imprimir o cadastro
                }   

                break;
                
            case 7: 
                return 0;
                
            default:
                cout << "\n\tOpção informada inválida!!\n";
                sleep(1);
        }

    }while(true);
    
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
           sleep(1);
        }

        pVetor = pRamal;//incializando o vetor
        
        //vou criticar se o ramal já está cadastrado
        if (!VerificarExistenciaDoRegistro(pVetor, "", iAux, 0)){
           cout << "\nNúmero do Ramal já está cadastrado\n";
           sleep(1);
           iAux = -1;//fleguei
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

        cout << "\nInforme o código do Edifício 500 ou 505 = ";
        cin  >> pRamal->VarEdificio.iCodEdificio;
        cin.ignore();
        
        //quarta crítica 
        if (pRamal->VarEdificio.iCodEdificio != 500 && 
            pRamal->VarEdificio.iCodEdificio != 505){
           cout << "\nCódigo do Edifício diferente de 500 ou 505\n";
           sleep(2);
        }
        
    }while(pRamal->VarEdificio.iCodEdificio != 500 && 
           pRamal->VarEdificio.iCodEdificio != 505);
    
    cout << "\nInforme o Endereço do Edificio = ";
    getline(cin, pRamal->VarEdificio.sNomeEdificio);

    //garantindo que seja tudo seja letras maíusculas
    for (auto &letra: pRamal->VarEdificio.sNomeEdificio){
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
 
    return;//instrução opcional para procedimentos
}

//Pesquisa nomes no cadastro
bool VerificarExistenciaDoRegistro(CadRamal *pVetor, string pAuxiliar, int &pRamal, int pOpc){
        
    if (pAuxiliar != ""){//vou garantir que só as pesquisas por nomes entre aqui 
        if (iQtdRegistros == 0){//a struct está vazia
            cout << "\n=========================================================";                
            cout << "\nSr Usuário, não há Registros no Cadastro até o momento!..";
            cout << "\n=========================================================\n";
            pRamal = -1;//vou flagar para para mostrar somente este ramal/registro
            sleep(4);
            return true;
        }

        //garantindo que seja tudo seja letras maíusculas
        for (auto &letra: pAuxiliar){
            letra = toupper(letra);
        }
    }

    for (int i = 0; i < iTam; i++){ 
        if (pOpc == 0){//ramal
            if (pVetor[i].iNumRamal == pRamal){
               pRamal = i;//vou flagar para para mostrar somente este ramal/registro
               return false; 
            } 

        }else if (pOpc == 1){//setor
            if (pVetor[i].VarSetor.sSetor == pAuxiliar){
               pRamal = i;//vou flagar para para mostrar somente este ramal/registro
               return false; 
            } 
            
        }else if (pOpc == 2){//edifício
            if (pVetor[i].VarEdificio.iCodEdificio == pRamal){
               pRamal = i;//vou flagar para para mostrar somente este ramal/registro
               return false; 
            } 
            
        }else if (pOpc == 3){//responsável pelo ramal
            if (pVetor[i].sRespRamal == pAuxiliar){
               pRamal = i;//vou flagar para para mostrar somente este ramal/registro
               return false; 
            } 
            
        }else if (pOpc == 4){//responsável pelo ateste
            if (pVetor[i].sRespAteste == pAuxiliar){
               pRamal = i;//vou flagar para para mostrar somente este ramal/registro
               return false; 
            } 
        }
        
    }

    return true; 
    
}

//Pesquisa por Ramal
void ListarCadastroParaPesquisa(CadRamal *pVetor, int &pOpc){ 
        
    if (iQtdRegistros == 0){//a struct está vazia
        cout << "\n=========================================================";                
        cout << "\nSr Usuário, não há Registros no Cadastro até o momento!..";
        cout << "\n=========================================================\n";
        sleep(4);
        pOpc = -1;//vou flagar para para mostrar somente este ramal/registro
        return;
    }
 
    if (pOpc == 0){//lista somente os ramais
        cout << "\n" << pVetor->iNumRamal;
        
    }else if (pOpc == 1){//lista somente os setores
        cout << "\n" << pVetor->VarSetor.sSetor;
    
    }else if (pOpc == 2){//lista somente os edifícios
        cout << "\n"  << pVetor->VarEdificio.iCodEdificio;
        cout << " - " << pVetor->VarEdificio.sNomeEdificio;
    
    }else if (pOpc == 3){//lista somente os responsáveis pelo Ramal
        cout << "\n" << pVetor->sRespRamal;
    
    }else if (pOpc == 4){//lista somente os responsável pelo atesto do ramal
        cout << "\n" << pVetor->sRespAteste;
    
    }

    return; //este comando é opcional em um procedimento do tipo void
    
}

//procedimento para imprimir o cadastro
void ImprimirCadastroDeRamais(CadRamal *pVetor){

    cout << "\n=============================================================";
    cout << "\nRamal                  : " << pVetor->iNumRamal;
    cout << "\nCategoria              : " << pVetor->VarCategoria.iCodCategoria
         << " - ";
    cout << pVetor->VarCategoria.sNomeCategoria;
    cout << "\nSetor                  : " << pVetor->VarSetor.sSetor;
    cout << "\nEdifício               : " << pVetor->VarEdificio.iCodEdificio
         << " - ";
    cout << pVetor->VarEdificio.sNomeEdificio;
    cout << "\nSala                   : " << pVetor->sSalaRamal;
    cout << "\nResponsável pelo Ramal : " << pVetor->sRespRamal;
    cout << "\nResponsável pelo Ateste: " << pVetor->sRespAteste;
    cout << "\n=============================================================\n";
    sleep(2);//aguarda 10 segundos
    
    return; //este comando é opcional em um procedimento do tipo void

}