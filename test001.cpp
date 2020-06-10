// ˮ�ɻ����Ķ����ǣ������������ÿһλ���ϵ��ݴ�֮�� ��ά���ٿƵĶ���

/*
    ��ʼ��һ��0~9��n�η������飬
    ���α�������ÿһ���� ����ѭ���� /10 �� ÿ��֮�����ݵ�n�η�ȡ�����
    �жϽ��һ�¼��ɣ�
*/

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n: The number of digits
     * @return: All narcissistic numbers with n digits
     */
    vector<int> getNarcissisticNumbers(int n) {
        vector<int> results;
        if (n == 0)
            return results;

        vector<int> powers(10, 0);
        for (int i = 1; i < 10; ++i) {
            powers[i] = pow(i, n);          //0~9��n�η�
        }

        int upperLimit = pow(10, n) - 1;    //����
        int lowerLimit = (n == 1) ? 0 : pow(10, n - 1); //����

        for (int num = lowerLimit; num <= upperLimit; ++num) {
            vector<int> digits(n, 0);
            long long powSum = 0;
            int saveNum = num;
            for (int i = 0; i < n; ++i) {
                digits[i] = saveNum % 10;
                powSum += powers[digits[i]];
                saveNum /= 10;
            }

            if (num == powSum)
                results.push_back(num);
        }

        return results;
    }
};
