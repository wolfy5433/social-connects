#include "social_connections.h"

using namespace std;

Graph::Graph()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }
    nameCount = 0;
}

string Graph::getName(int index) const
{
    return name[index];
}

int Graph::getIndexOfName(string gname) const
{
    for (int i = 0; i < nameCount; ++i)
    {
        if (name[i] == gname)
        {
            return i;
        }
    }
    return 0;
}

void Graph::addName(string gname) 
{
    name[nameCount++] = gname;
}

void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] != 0;
}

bool Graph::vertexExists(string gname)
{
    for (int i = 0; i < nameCount; ++i)
    {
        if (name[i] == gname)
        {
            return true;
        }
    }
    return false;
}



void Graph::all_pairs_within_three_edges() 
{
    // инициализация матрицы путей
    int weights[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (i == j)
            {
                weights[i][j] = 0;
            }
            else
            {
                if (edgeExists(i, j))
                {
                    weights[i][j] = matrix[i][j];
                }
                else
                {
                    weights[i][j] = VERYBIGINT;
                }
            }
        }
    }
    // ---------------------------

    // итераций по k-ой вершине
    for (int k = 0; k < nameCount; ++k)
    {
        string ck = name[k];

        // итераций по i-ой вершине
        for (int i = 0; i < nameCount; ++i)
        {
            if (i == k)
            {
                continue;
            }
            string ci = name[i];

            // итераций по j-ой вершине
            for (int j = 0; j < nameCount; ++j)
            {
                if (j == k)
                {
                    continue;
                }
                string cj = name[j];

                // сравнение путей
                if (weights[getIndexOfName(ci)][getIndexOfName(ck)] + weights[getIndexOfName(ck)][getIndexOfName(cj)] < weights[getIndexOfName(ci)][getIndexOfName(cj)])
                {
                    weights[getIndexOfName(ci)][getIndexOfName(cj)] = weights[getIndexOfName(ci)][getIndexOfName(ck)] + weights[getIndexOfName(ck)][getIndexOfName(cj)];
                }
                // ----сравнение путей--------

            }
            // ---итераций по j-ой вершине-------

        }
        // ------итераций по i-ой вершине----------

    }
    // -----------итераций по k-ой вершине-----------

    for (int i = 0; i < nameCount; ++i)
    {  
        for (int j = 0; j < nameCount; ++j)
        {
            cout << name[j] << ':' << weights[i][getIndexOfName(name[j])] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < nameCount; ++i)
    {
        for (int j = 0; j < nameCount; ++j)
        {
            if (weights[i][getIndexOfName(name[j])] <= 3 && weights[i][getIndexOfName(name[j])] != 0)
            {
                cout << name[i] << " и " << name[j] << " друзья!" << endl;
            }
            else if (weights[i][getIndexOfName(name[j])] == 0)
            {
                continue;
            }
            else
            {
                //cout << endl;
                //cout <<name[i] << " ne znaet " << name[j] << '\n' << "---------------------" << endl;
                continue;
            }
        }
    }
}

ostream& operator<<(ostream& os, const Graph& gr)
{
    //for (int i = 0; i < gr.nameCount; i++)
    //{
    //    for (int j = 0; j < gr.nameCount; j++)
    //    {
    //        os << gr.matrix[i][j] << ' ';
    //    }
    //    os << endl;
    //}
    //os << '\n';
    for (int i = 0; i < gr.nameCount; i++)
    {
        os << gr.getIndexOfName(gr.name[i]) << ':' << ' ' << gr.name[i] << endl;
    }
    os << endl;

    return os;
}