#include <iostream>
#include <fstream>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <set>

using namespace std;

int main()
{
    // _setmode(_fileno(stdout), _O_U16TEXT);  
	ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error, file did not oppend: input.txt" << endl;
        return 1; // завершаем программу с ошибкой
    }
    int u, v;
    vector<pair<int, int>> edges;
    set<int> vertices;
    while (fin >> u >> v) {
    cout << "Edge: " << u << " - " << v << endl;
    edges.push_back({u, v}); // Добавить ребро (u, v)
    vertices.insert(u);      // Добавить вершину u (если уже есть — игнорирует)
    vertices.insert(v);      // Добавить вершину v
    }
    cout << "Total vertices: " << vertices.size() << endl;
    fin.close(); // можно и без этого (деструктор закроет), но явно — лучше

}
