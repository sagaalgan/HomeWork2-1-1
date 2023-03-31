#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("in.txt");
    if (!file.is_open())
    {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return 0;
    }

    std::string n;
    file >> n;
    int k = std::stoi(n);
    int* N = new int[k];
    int y = k;
    while (y == k)
    {
        for (int i = 0; i < k; i++)
        {
            file >> N[i];
        }
        int t = N[0];
        for (int i = 0; i < k - 1; i++)
        {
            N[i] = N[i + 1];
        }
        N[k - 1] = t;
        y++;
    }
    std::string n1;
    file >> n1;
    int k1 = std::stoi(n1);
    int* M = new int[k1];
    int g = k1;
    while (!file.eof())
    {
        for (int i = 0; i < k1; i++)
        {
            file >> M[i];
        }
        int t = M[k1 - 1];
        for (int i = k1 - 2; i >= 0; i--)
        {
            M[i + 1] = M[i];
        }
        M[0] = t;
    }
    std::ofstream out("out.txt");
    out << k1 << std::endl;
    for (int i = 0; i < k1; i++)
    {
        out << M[i] << " ";
    }
    out << std::endl << k << std::endl;
    for (int i = 0; i < k; i++)
    {
        out << N[i] << " ";
    }
    delete[] N;
    delete[] M;
    file.close();
    out.close();
}