#include <iostream>
#include "ManagerHeader.h"

using namespace std;

int main()
{
    int opc;
    int linha;
    int coluna;

    cout<<"BEM-VINDO AO CIIIIIRCOOO DE SOLEEED\n"<<endl;
    do
    {
        cout<<"Passa a call das fileiras no teatro: ";
        cin>>linha;
        cout<<"Manda no voice as cadeiras por fileira: ";
        cin>>coluna;
        cout<<endl;
        if(linha<=0)
        {
            if(coluna<=0)
                cout<<"Os valores nao podem ser negativos, fion. Faz de novo ae!\n";
            else
                cout<<"O valor de fileiras nao pode ser negativo, 4Head. Tente novamente!\n";
        }
        else
            if(coluna<=0)
            cout<<"O valor de cadeiras nao pode ser negativo, bronze. Vamo de novo.\n";
    }while(linha<=0 | coluna<=0);

    Matriz m(linha, coluna);

    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            m.v[linha,coluna] = false;
            cout<<m.v[linha,coluna]<<" ";
        }
        cout<<endl;
    }

    do
    {
        cout<<"\nEscolhe uma opcao ae mano!!\n1-Comprar Ingresso\n2-Vender Ingresso\n3-Trocar Assento\n9-Sair daqui\n\nEscolha: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
            do
            {
                cout<<"\n####COMPRANDO INGRESSO####\n";
                cout<<"Digita a fileira ai pra nois: ";
                cin>>linha;
                linha--;
                cout<<"Agora digita a cadeira: ";
                cin>>coluna;
                coluna--;
                if(!m.isDisponivel(linha,coluna))
                    cout<<"\nO fion essa ai nao ta disponivel. Pega outra xD\n";
                else
                {
                    m.venda(linha, coluna);
                    cout<<"\nDAAALEEEE! O ingresso foi vendido com sucesso!\n";
                }
            }while(m.isDisponivel(linha,coluna));
            break;
        case 2:
            do
            {
                cout<<"\n####DEVOLVENDO INGRESSO####\n";
                cout<<"Digita a fileira ai pra nois: ";
                cin>>linha;
                linha--;
                cout<<"Agora digita a cadeira: ";
                cin>>coluna;
                coluna--;
                if(m.isDisponivel(linha,coluna))
                    cout<<"\nO fion essa ai ta livre. Digita o certo xD\n";
                else
                {
                    m.devolucao(linha, coluna);
                    cout<<"\nPo irmao, ai eu fico yotriste! O ingresso foi devolvido...\n";
                }
            }while(!m.isDisponivel(linha,coluna));
            break;
        case 3:
            do
            {
                cout<<"\n####TROCANDO INGRESSO####\n";
                cout<"\n##INGRESSO A SER DEVOLVIDO##\n";
                cout<<"Digita a fileira ai pra nois: ";
                cin>>linha;
                linha--;
                cout<<"Agora digita a cadeira: ";
                cin>>coluna;
                coluna--;
                if(m.isDisponivel(linha,coluna))
                    cout<<"\nO fion essa ai ta livre. Digita o certo xD\n";
                else
                {
                    m.devolucao(linha, coluna);
                    cout<<"\nBeleza irmao, ta marcado...\n";
                }
            }while(!m.isDisponivel(linha,coluna));

            do
            {
                cout<<"\n##INGRESSO SUBSTITUTIVO##\n";
                cout<<"Digita a fileira ai pra nois: ";
                cin>>linha;
                linha--;
                cout<<"Agora digita a cadeira: ";
                cin>>coluna;
                coluna--;
                if(!m.isDisponivel(linha,coluna))
                    cout<<"\nO fion essa ai nao ta disponivel. Pega outra xD\n";
                else
                {
                    m.venda(linha, coluna);
                    cout<<"\nDAAALEEEE! O ingresso foi trocado! HIGH ELO GAMEPLAY BOYZ\n";
                }
            }while(m.isDisponivel(linha,coluna));
            break;
        case 9:
            for(int x=0;x<15;x++)
                cout<<"?\n";
            //cout<<"\nFui de beise xD\n";
            break;
        default:
            cout<<"\nEssa opcao ai nao pode, meu parsa\n!!\n";
            break;
        }
    }while(opc!=9);

    return 0;
}
