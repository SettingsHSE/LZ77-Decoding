#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Node
{
    int offset;
    int length;
    char next;

    Node(int of, int le, char ne)
    {
        offset = of;
        length = le;
        next = ne;
    }
};

std::string Decode(const std::vector<Node*>& encoded)
{
    std::string answer;
    for(auto & node : encoded)
    {
        if(node->length > 0)
        {
            int start = answer.length() - node->offset;
            for (int k = 0; k < node->length; k++)
            {
                answer += answer[start + k];
            }
        }
        answer += node->next;
    }
    return answer;
}

int main()
{
    std::fstream fin;
    fin.open("input.txt", std::ios::in);
    if(fin.is_open()) {
        int N;
        fin >> N;

        std::vector<Node*> encoded;

        int offset, length;
        char next;
        for (int i = 0; i < N; i++) {
            fin >> offset >> length >> next;
            encoded.push_back(new Node(offset, length, next));
        }

        fin.close();

        std::string decoded = Decode(encoded);

        std::fstream fout;
        fout.open("output.txt", std::ios::out);
        fout << decoded;
        fout.close();
    }

    return 0;
}