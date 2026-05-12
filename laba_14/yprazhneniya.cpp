#include <iostream>
#include <fstream>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <set>
#include <map>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    map<int, int> vertexToIndex;
    int index = 0;
    // _setmode(_fileno(stdout), _O_U16TEXT);  
	ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error, file did not oppend: input.txt" << endl;
        return 1; // завершаем программу с ошибкой если файл не прочитана или не найден
    }

    int u, v;
    vector<pair<int, int>> edges;
    set<int> vertices;
    while (fin >> u >> v) {
    cout << "Edge: " << u << " - " << v << endl;
    edges.push_back({u, v}); // Добавить ребро (u, v)
    vertices.insert(u);      // Добавить вершину u (если уже есть — игнорирует)
    vertices.insert(v);      // Добавить вершину v
    
    for (int v : vertices) vertexToIndex[v] = index++;
    }

    vector<int> vertexList(vertices.begin(), vertices.end());

    for (int i = 0; i< vertexList.size(); i++){
        vertexToIndex[vertexList[i]] = i;
    }

    //создаем матрицу смежности
    int n = vertexList.size();
    vector<vector<int>> matrix(n, vector<int>(n,0));

    // Заполнение Матрицы
    for (auto edge :edges) {
        int u = edge.first;
        int v = edge.second;
        int i = vertexToIndex[u];
        int j = vertexToIndex[v];
        matrix[i][j] = 1;
        matrix[j][i] = 1;   
    }

    cout << "Total vertices: " << vertices.size() << endl;

    ofstream fout("matrix.txt");
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        fout << matrix[i][j] << " ";
    }
    fout << "\n";
}
    fin.close(); 


    //Упражнение 2
    vector<vector<int>> matrix_1;
    ifstream fin("matrix.txt");
    if (!fin.is_open()) {
    cerr << "Ошибка: не удалось открыть matrix.txt!" << endl;
    return 1; // завершаем программу
} 

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<int> row;
        int x;
        while (ss >> x) {
            row.push_back(x); // добавляем числа из строки
    }
    matrix_1.push_back(row); // добавляем строку в матрицу
}
for (auto &r : matrix_1) {
    for (int x : r) cout << x << " ";
    cout << "\n";
}
    
    
}
