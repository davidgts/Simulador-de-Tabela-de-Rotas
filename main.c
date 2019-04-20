#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tabela_Roteamento.h"
//////////////////////////////////////////////////////////////////////////
void menu (void);void sobre_Sistema(void);tlista inserir_Dado(tlista L);
void apresentar_Dados(tlista *L);void remove_Dado(tlista *L);

int main(){
   setlocale(LC_ALL, "Portuguese");
   menu();
}
////////////////////////////////////////////////////////////////////////////////////////////
void menu (void){
   tlista p;
   p = NULL;
   char opc;
   do{
     system("cls");
     puts("         ______________________________");
     puts("");
     puts("         Projeto de Estrutura de Dados");
     puts("_______________________________________________________");
     puts("");
     puts("Simulador de Leitura e escrita de tabela de roteamento ");
     puts("");
     puts("Informe a sua opção !");
     puts("1 - Inserir Dado na Tabela de Rota");
     puts("2 - Apresentar a Tabela de Rota");
     puts("3 - Remover dado na tabela de Rota");
     puts("4 - Sobre o Software");
     puts("ESC - Sair do Programa");
     opc = getche();
     setbuf(stdin,NULL);
     switch (opc){
        case '1':p = inserir_Dado(p);break;
        case '2':apresentar_Dados(&p);break;
        case '3':remove_Dado(&p);break;
        case '4':sobre_Sistema();break;
        default:{
            if (opc == 27)
                break;
            printf("\nOpção Invalida [ PRESSIONE QUALQUER TECLA !]");
            getch();
            break;
        }
     }

   }while(opc != 27);
}
/////////////////////////////////////////////////////////////////////////////////////////
tlista inserir_Dado(tlista L){

 t_elem info;
 tlista p = NULL;
 int r;

 system("cls");
 puts("Insira os Valores !");
 info.protocolo = 'S';
 puts("IP destino:");
 gets(info.ip_destino);
 setbuf(stdin,NULL);

 puts("Mascara de Rede:");
 gets(info.mascara);
 setbuf(stdin,NULL);

 puts("Interface de Saida:");
 gets(info.end_interface_saida);
 setbuf(stdin,NULL);

 puts("Distancia Administrativa :");
 scanf("%d",&info.metrica);
 setbuf(stdin,NULL);

 r = inserir(&L,1,info);
 p = L;
 puts("Inserido com Sucesso !");
 printf("\n\n[Meio de inserção] - %c  \n[IP] - %s \n[Mascara] - %s \n[Interface de Saída] - %s \n[Distância Administrativa] - %d \n",p->dado.protocolo, p->dado.ip_destino , p->dado.mascara,p->dado.end_interface_saida,p->dado.metrica);
 getch();
 if (!r){
   puts("Erro !");
 }
 return L;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void apresentar_Dados(tlista *L){

  int i;
  tlista p;
  system("cls");
  printf("\n\n\n");
  printf("Codigos Podem ser : \nC - Diretamente conectada, S - estática,\nR - RIP, O - OSPF\n");
  puts("_______________________________________________________________________________");
  printf("\n");
  printf("                  Tabela de Rotas - Simulação    \n");
  p = *L;

  if (vazia(p)){
    puts("Tabela Vazia [Pressione Qualquer tecla e Insira dados !]");
    getch();
    return;
  }

   while(p != NULL){
      puts("_______________________________________________________");
      printf("[Meio de inserção] - %c  \n[IP] - %s \n[Máscara] - %s  \n[Interface de Saída] - %s \n[Distância Administrativa] - %d\n",p->dado.protocolo, p->dado.ip_destino ,p->dado.mascara, p->dado.end_interface_saida, p->dado.metrica);
      puts("_______________________________________________________");
      p = p->prox;
  }

  getch();
}
///////////////////////////////////////////////////////////////////////////////////////
void remove_Dado(tlista *L){
   t_elem info;
   int retorno;
   system("cls");
   puts("Remove dados da tabela");
   puts("Informe o IP destino:");
   gets(info.ip_destino);

    retorno = remover_val (L,info);

  if(retorno == 1){
     puts("Removeu");
   }else{
      if(retorno == 2){
        puts("Lista Vazia ! - [Insira Valor Primeiro na Tabela]");
      }else
          puts("Valor não encontrado !");
    }
   getch();
}
////////////////////////////////////////////////////////////////////////////////////////////////
void sobre_Sistema(void){
   system("cls");
   puts("          IFPB - Instituto Federal da Paraiba");
   puts("           Seminário de Estrutura de Dados ");
   puts("|______________________________________________________|");
   puts("|                                                      |");
   puts("|Simulador de tabela de roteamento Versão:Beta         |");
   puts("|Alunos Envolvidos no desenvolvimento do software :    |");
   puts("|______________________________________________________|");
   puts("David Machado - Programador");
   puts("Eric Vinícius - Colaborador Técnico");
   puts("Lucas Arruda - Colaborador Técnico");
   puts("Thomas Duarte - Colaborador de Interface ao Usuario");

   getch();
}


