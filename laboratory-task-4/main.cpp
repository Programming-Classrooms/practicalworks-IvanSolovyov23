#include <iostream>
#include <vector>
#include <ctime>


using std:: vector;
using std:: cout;
using std:: cin;
using std:: endl;


int main()
{
    try
    {
        setlocale(LC_ALL, "RU");
        char a = '0';
        cout << "0 - Random, 1- Personal choose" << endl;
        cin >> a;
        if (a == '0')
        {
            srand(time(NULL));
            int m = 3, n = 3; // Размеры матрицы
            vector<double> X(m), Y(n);
            vector<vector<double>> mtr(m, vector<double>(n));
            // Заполнение векторов X и Y случайными значениями
            for (int i = 0; i < m; i++)
            {
                X[i] = rand() / (double)RAND_MAX * 10; // Случайное число от 0 до 10
            }
            for (int j = 0; j < n; j++)
            {
                Y[j] = rand() / (double)RAND_MAX * 10; // Случайное число от 0 до 10
            }
            // Заполнение матрицы Коши
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mtr[i][j] = 1 / (X[i] + Y[j]);
                }
            }

            // Вывод матрицы Коши
            cout << "Матрица Коши:" << endl;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << mtr[i][j] << " ";
                }
                cout << endl;
            }
            // Нахождение суммы элементов каждого столбца
            vector<double> sum(n, 0);
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < m; i++) {
                    sum[j] += mtr[i][j];
                }
            }
            // Вывод суммы элементов каждого столбца
            cout << "Сумма элементов каждого столбца:" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << "Столбец " << j << ": " << sum[j] << endl;
            }
        } 
        else
        if (a == '1')
        {
            int m, n;
            cout << "Введите количество строк: ";
            cin >> m;
            if (m < 0)
            {
                throw std::exception("Количество не может быть отрицательным");
            }
            cout << "Введите количество столбцов: ";
            cin >> n;
            if (n < 0)
            {
                throw std::exception("Количество не может быть отрицательным");
            }
            vector<double> X(m), Y(n);
            vector<vector<double>> K(m, vector<double>(n));

            cout << "Введите элементы вектора X:" << endl;
            for (int i = 0; i < m; i++)
            {
                cout << "X[" << i << "]: ";
                cin >> X[i];
                if (X[i] == 0)
                {
                    throw std::exception("На ноль делить нельзя");
                }
            }

            cout << "Введите элементы вектора Y:" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << "Y[" << j << "]: ";
                cin >> Y[j];
                if (Y[j] == 0)
                {
                    throw std::exception("На ноль делить нельзя");
                }
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    K[i][j] = 1 / (X[i] + Y[j]);
                }
            }
            cout << "Матрица Коши:" << endl;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << K[i][j] << " ";
                }
                cout << endl;
            }
            vector<double> sum(n, 0);
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < m; i++)
                {
                    sum[j] += K[i][j];
                }
            }
            cout << "Сумма элементов каждого столбца:" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << "Столбец " << j << ": " << sum[j] << endl;
            }
        }
        else
        {
            //cout << "Читай внимательно условие!" << endl;
            throw std::exception("Читай внимательно условие!");
        }
    }
    catch (std::exception e) {
        std::cerr << e.what();
    }
    return 0;
}

