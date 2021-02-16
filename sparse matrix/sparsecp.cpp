#include <iostream>
#include <windows.h>
using namespace std;
class element
{
public:
    int i, j, data;
};
class sparsecp
{
private:
    int m, n, size;
    element *e;

public:
    sparsecp(int m, int n, int size);
    ~sparsecp();
    sparsecp operator+(sparsecp &s);
    friend istream &operator>>(istream &is, sparsecp &s);
    friend ostream &operator<<(ostream &os, sparsecp &s);
};

sparsecp::sparsecp(int m, int n, int size)
{
    this->m = m;
    this->n = n;
    this->size = size;
    this->e = new element[size];
}

sparsecp::~sparsecp()
{
    delete[] e;
}

sparsecp sparsecp::operator+(sparsecp &s)
{
    int i, j, k;
    sparsecp *sum = new sparsecp(m, n, size + s.size);
    i = j = k = 0;
    while (i < size && j < s.size)
    {
        if (e[i].i < s.e[j].i)
        {
            sum->e[k++] = e[i++];
        }
        else if (e[i].i > s.e[j].i)
        {
            sum->e[k++] = s.e[j++];
        }
        else if(e[i].i == s.e[j].i)
        {
             if (e[i].j < s.e[j].j)
        {
            sum->e[k++] = e[i++];
        }
        else if (e[i].j > s.e[j].j)
        {
            sum->e[k++] = s.e[j++];
        }else
        {
            sum->e[k]=e[i];
            sum->e[k++].data=e[i++].data+s.e[j++].data;
        }
        
        }
        

    }
    for(;i<size;i++)sum->e[k++]=e[i];
    for(;j<size;j++)sum->e[k++]=e[j];
      sum->size=k;
    return *sum;
}
ostream &operator<<(ostream &os, sparsecp &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.e[k].i == i && s.e[k].j == j)
            {
                cout << s.e[k++].data << "\t";
            }
            else
            {
                cout << "0\t";
            }
        }
        cout << "\n";
    }
    return os;
}
istream &operator>>(istream &is, sparsecp &s)
{
    cout << "enter non zero element :-\n";
    cout << "enter row col data\n";
    for (int i = 0; i < s.size; i++)
    {
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].data;
    }

    return is;
}
int main()
{
    sparsecp sparsec(5, 5, 5);
    cin >> sparsec;
    cout << sparsec;
    system("pause");
    return 0;
}
