#include    <fstream>
#include    <vector>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

const int NLIM = 100005;

int N, M;
vector < int > Edge[NLIM];

bool beenThere[NLIM];
int answer;

void DFS(int Node)
{
    beenThere[Node] = true;
    for (unsigned int i = 0; i < Edge[Node].size(); i++)
    {
        int Next = Edge[Node][i];
        if (!beenThere[Next])
            DFS(Next);
    }
}

void Read()
{
    fin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int x, y;
        fin >> x >> y;
        Edge[x].push_back(y);
        Edge[y].push_back(x);
    }
    for (int i = 1; i <= N; i++)
    {
        if (!beenThere[i])
        {
            answer += 1;
            DFS(i);
        }
    }
    fout << answer << "\n";
}

int main()
{
    Read();
    return 0;
}