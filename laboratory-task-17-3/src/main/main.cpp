#include "../functions/functions.hpp"




int main() 
{
    try {
        std::set<std::string> lakeFish = { "Карп", "Вобла", "Акула", "Сом", "Золотая" };
        std::set<std::string> fisherman1 = { "Карп", "Акула" };
        std::set<std::string> fisherman2 = { "Вобла", "Золотая" };
        std::set<std::string> fisherman3 = { "Вобла", "Карп" };

        // Объединение всех уловов
        std::set<std::string> allFishermenCatch;


        std::set_union(fisherman1.begin(), fisherman1.end(),
            fisherman2.begin(), fisherman2.end(),
            std::inserter(allFishermenCatch, allFishermenCatch.begin()));


        std::set<std::string> temp;
        std::set_union(allFishermenCatch.begin(), allFishermenCatch.end(),
            fisherman3.begin(), fisherman3.end(),
            std::inserter(temp, temp.begin()));


        allFishermenCatch.swap(temp);

        // Рыба, которую не поймал ни один рыбак
        std::set<std::string> fishInLakeNotCaught;


        std::set_difference(lakeFish.begin(), lakeFish.end(),
            allFishermenCatch.begin(), allFishermenCatch.end(),
            std::inserter(fishInLakeNotCaught, fishInLakeNotCaught.begin()));

        // Проверка файла
        std::ofstream fin("src/main/result.txt");
        checkFile(fin);

        // Улов
        printSet("Fish caught by fisherman 1:", fisherman1, fin);
        printSet("Fish caught by fisherman 2:", fisherman2, fin);
        printSet("Fish caught by fisherman 3:", fisherman3, fin);


        // Рыба, пойманная по крайней мере одним рыбаком
        printSet("Fish caught by at least one fisherman: ", allFishermenCatch, fin);

        // Рыба есть, но не поймана (не то чтобы есть, но по сути есть)
        printSet("Fish in the lake but not caught by any fisherman: ", fishInLakeNotCaught, fin);

        fin.close(); // СЭР, есть не забыть закрыть файл, СЭР

        std::cout << "Fish report generated:\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
    return 0;
}