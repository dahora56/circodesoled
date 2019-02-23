#ifndef MANAGERHEADER_H_INCLUDED
#define MANAGERHEADER_H_INCLUDED

struct Matriz
{
    bool *v;
    unsigned int contador;
    int LINHA, COLUNA;

    Matriz(int lin, int col)
    {
        LINHA = lin;
        COLUNA = col;
        v=new bool[lin*col];
        for(int i =0;i<lin;i++)
        {
            for(int j=0;j<col;j++)
            {
                v[i*col+j] = false;
            }
        }
    }

    bool isDisponivel(int linha, int coluna)
    {
        return !v[linha*COLUNA+coluna];
    }

    void venda(int linha, int coluna)
    {
        contador++;
        v[linha*COLUNA+coluna]=true;
    }
    void devolucao(int linha, int coluna)
    {
        contador--;
        v[linha*COLUNA+coluna]=false;
    }
};

#endif // MANAGERHEADER_H_INCLUDED
