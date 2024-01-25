#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
 
class Search{
    int node;    // jumlah node
    std::list<int> *adj;    // adjacency lists
public:
    Search(int node){ // constructor
        this->node = node;
        adj = new std::list<int>[node];
    }
    void edge(int a, int b){ // fungsi untuk menambahkan edge dari graph
        adj[a].push_back(b); // menambahkan b ke list a
    } 

    void dfs(int s){
        // membuat semua node menjadi blom terkunjungi
        std::vector<bool> visit(node, false);
    
        // membuat stack
        std::stack<int> stack;
    
        // push node start/origin
        stack.push(s);
        
        // melakukan perulangan hingga stack kosong
        while (!stack.empty())
        {
            // menyimpan atas dari stack
            s = stack.top();
            stack.pop(); // lalu meremove nya

            // mereverse adjacency list agar output seperti pada soal
            reverse(adj[s].begin(), adj[s].end());
            
            // hanya mencetak s bila node nya belum dikunjungi
            if (!visit[s])
            {   // jika belum maka mencetak s lalu membuat node nya menjadi status visited
                std::cout << s << " ";
                visit[s] = true;
            }
    
            // memasukkan node yang berdampingan dengan node s ke stack (kalau belum visited)
            for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
                if (!visit[*i])
                    stack.push(*i);
        }
    }  
    
    void bfs(int s){
        // membuat semua node menjadi blom terkunjungi
        std::vector<bool> visit(node, false);
    
        // membuat list
        std::list<int> queue;
    
        // membuat node start menjadi status visited lalu memasukkan ke list
        visit[s] = true;
        queue.push_back(s);
    
        while(!queue.empty())
        {
            // mencetak s (elemen list terdepan)
            s = queue.front();
            std::cout << s << " ";
            // lalu mengeluarkannya dari list
            queue.pop_front();
    
            // mendapatkan node yang berdampingan dengan s lalu memasukkan nya kedalam list
            for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visit[*i])
                {
                    visit[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
};
