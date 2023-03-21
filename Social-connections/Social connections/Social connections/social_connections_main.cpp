#include "social_connections.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Нахождение всех пар знакомств через три рукопожатия" << endl;
    Graph g;
    string name;
    cout << "Введите имена. Максимум можно ввести 15 имён или нажать пробел Enter, чтобы закончить." << endl;
    for (int i = 0; i < SIZE; ++i)
    {
        getline(cin, name);
        if (name == " ")
        {
            break;
        }
        g.addName(name);
    }
    cout << g;
    cout << "Теперь введите индексы людей, кто кому приходится другом.\nМаксимум можно ввести 15 связей или нажать любую клавишу, чтобы закончить" << endl;
    int a, b;
    for (int i = 0; i < SIZE; ++i)
    {
        cin >> a >> b;
        if (cin.fail())
        {
            break;
        }
        g.addEdge(g.getIndexOfName(g.getName(a)), g.getIndexOfName(g.getName(b)), 1);
    }
    g.all_pairs_within_three_edges();

    return 0;
}