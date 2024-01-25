#include "header.hpp"

int main()
{
    int N,M,a,b,start;
    std::string method;

    // input jumlah node dari graph
    std::cin >> N;
    Search search(N);

    // input jumlah edge yang akan dimasukkan
    std::cin >> M;
    // input directed edge antara node sebanyak M kali
    for(int i=0; i<M; i++){
        std::cin >> a >> b;
        search.edge(a, b);
    }

    // input node start/origin yang ingin digunakan
    std::cin >> start;

    // memilih metode yang mau digunakan (DFS atau BFS)
    std::cin >> method;

    // menjalankan bfs atau dfs sesuai pilihan
    if(method == "DFS")
        search.dfs(start);
    else if(method == "BFS")
        search.bfs(start);
    
    std::cout << std::endl; //endline di akhir setelah output hasil
    return 0;
}