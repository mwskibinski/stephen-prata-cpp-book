#include <iostream>

void ep(void);
void cs(void);

int main()
{
    ep();
    ep();
    cs();
    cs();

    return 911;
}

void ep(void)
{
    std::cout << "Entliczek pentliczek\n";
}

void cs(void)
{
    std::cout << "Czerwony stoliczek\n";
}
