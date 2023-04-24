#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct Clientes
{
    char nome[MAX];
    int codigo_cliente;
};

struct Conta
{
    int codigoCliente;
    int numeroConta;
    float valorConta;
};
/*@input:
    clientes: vetor onde o cadastro será feito
    *quant: é a posição onde sera gravada

  @output
    0: se não foi possivel cadastar
    1:caso seja possivel    
*/

int cadastrarCliente(Clientes cliente[MAX],int *quant)
{
    //Avalia se há posição livre
    if((*quant)<MAX)
    {
        printf("Informe o nome:");
        scanf("%d",&cliente[*quant].nome);
        printf("Informe o codigo:");
        scanf("%d",&cliente[*quant].codigo_cliente);
        (*quant)=(*quant)+1;
        return 1;
        //(*quant)++ soma mais 1 ao ponteiro
        //*(quant++) o ponteiro pegará o valor de outro endereço
    }
        return 0;
    
}
/*@input:
    contas: vetor onde o cadastro será feito
    *qtdContas: é a posição onde sera gravada a conta

  @output
    0:se não foi possivel cadastar, por falta de espaço ou por não ter cliente
    1:caso seja possivel    
*/

int cadastraConta(Conta contas[MAX],int *qtdContas, Clientes Cliente[MAX], int quant)
{
    int resposta=1,i;

    //verificar de há espaço no vetor
    if(*qtdContas>MAX)
    {
        resposta =0;
    }
    else
    {
        //iniciar a busca pelo cliente
        printf("Código do cliente:");
        scanf("%d",&contas[*qtdContas].codigoCliente);
        resposta = busca(Clientes,quant,contas[*qtdContas].codigoCliente)

        if(resposta==1)//se há cliente com o código
        {
            printf("Numero da conta:");
            scanf("%d",&contas[*qtdContas].numeroConta);
            printf("Valor da conta:");
            scanf("%f",&contas[*qtdContas].valorConta);
        }
        
    }
    return resposta;
}

int busca(Clientes cliente[MAX], int quant, int codigo_cliente)
{
    int i;
    for(i=0; i<quant; i++)
    {
        if(cliente[i].codigo_cliente == codigo_cliente)
        {
            return 1;
        }
    }
    return 0;
}

int buscaConta(Conta contas[MAX], int qtdConta, int codigoCliente)
{
    int i;
    for(i=0; i<qtdquant; i++)
    {
        if(contas[i].codigoCliente == codigoCliente)
        {
            return 1;
        }
    }
    return 0;
}

/*
   remove um cliente se não houver conta associada á ele
*/

int remove(Cliente cliente[MAX], int *quant, Conta contas[MAX], int qtdContas)
    
    {
        // Ler o código a ser removido
        int codigoCliente,i;
        printf("Codigo do cliente:");
        scanf("%d", &codigoCliente);

        //verificar se ele possui conta
        reposta = buscaConta(contas, qtdConta, codigoCliente);

        if(resposta == 1)
        {
            //não pode ser removido
            return 0;
        }

        //remove o cliente
        for(i=0; i<*quant; i++)
        {
            if(cliente[i].codigo_cliente == codigo_cliente)
            {
                //ao encontrar o cliente
                // deve "remover"
                //substituindo as informações
                //pelo cadastro do ultimo cliente
                cliente[i] = clientes[(*quant)-1];

                //atualizar a quantidade de clientes
                (*quant)--;
                return 1; //remoção feita
            }
        }
        return 0; //não encontrou o cliente
    }


