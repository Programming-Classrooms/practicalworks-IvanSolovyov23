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
            int m = 3, n = 3; // ������� �������
            vector<double> X(m), Y(n);
            vector<vector<double>> mtr(m, vector<double>(n));
            // ���������� �������� X � Y ���������� ����������
            for (int i = 0; i < m; i++)
            {
                X[i] = rand() / (double)RAND_MAX * 10; // ��������� ����� �� 0 �� 10
            }
            for (int j = 0; j < n; j++)
            {
                Y[j] = rand() / (double)RAND_MAX * 10; // ��������� ����� �� 0 �� 10
            }
            // ���������� ������� ����
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mtr[i][j] = 1 / (X[i] + Y[j]);
                }
            }

            // ����� ������� ����
            cout << "������� ����:" << endl;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << mtr[i][j] << " ";
                }
                cout << endl;
            }
            // ���������� ����� ��������� ������� �������
            vector<double> sum(n, 0);
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < m; i++) {
                    sum[j] += mtr[i][j];
                }
            }
            // ����� ����� ��������� ������� �������
            cout << "����� ��������� ������� �������:" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << "������� " << j << ": " << sum[j] << endl;
            }
        } 
        else
        if (a == '1')
        {
            int m, n;
            cout << "������� ���������� �����: ";
            cin >> m;
            if (m < 0)
            {
                throw std::exception("���������� �� ����� ���� �������������");
            }
            cout << "������� ���������� ��������: ";
            cin >> n;
            if (n < 0)
            {
                throw std::exception("���������� �� ����� ���� �������������");
            }
            vector<double> X(m), Y(n);
            vector<vector<double>> K(m, vector<double>(n));

            cout << "������� �������� ������� X:" << endl;
            for (int i = 0; i < m; i++)
            {
                cout << "X[" << i << "]: ";
                cin >> X[i];
                if (X[i] == 0)
                {
                    throw std::exception("�� ���� ������ ������");
                }
            }

            cout << "������� �������� ������� Y:" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << "Y[" << j << "]: ";
                cin >> Y[j];
                if (Y[j] == 0)
                {
                    throw std::exception("�� ���� ������ ������");
                }
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    K[i][j] = 1 / (X[i] + Y[j]);
                }
            }
            cout << "������� ����:" << endl;
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
            cout << "����� ��������� ������� �������:" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << "������� " << j << ": " << sum[j] << endl;
            }
        }
        else
        {
            //cout << "����� ����������� �������!" << endl;
            throw std::exception("����� ����������� �������!");
        }
    }
    catch (std::exception e) {
        std::cerr << e.what();
    }
    return 0;
}

