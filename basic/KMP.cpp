#include <cstdio>
#include <cstdlib>
#include <cstring>

void cal_next(char *str, int *next, int len)
{
    next[0] = -1;//next[0]��ʼ��Ϊ-1
    int k = -1;
    for (int q = 1; q <= len-1; q++)
    {
        while (k > -1 && str[k + 1] != str[q])
        {
            k = next[k];//��ǰ����
        }
        if (str[k + 1] == str[q])
        {
            k = k + 1;
        }
        next[q] = k;
    }
}

    int KMP(char *str, int slen, char *ptr, int plen)
   {
    int *next = new int[plen];
    cal_next(ptr, next, plen);
    int k = -1;
    for (int i = 0; i < slen; i++)
    {
        while (k >-1&& ptr[k + 1] != str[i])//ptr��str��ƥ�䣬��k>-1����ʾptr��str�в���ƥ�䣩
            k = next[k];//��ǰ����
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1)//˵��k�ƶ���ptr����ĩ��
        {
            //cout << "��λ��" << i-plen+1<< endl;
            //k = -1;//���³�ʼ����Ѱ����һ��
            //i = i - plen + 1;//i��λ����λ�ã����forѭ��i++���Լ�������һ��������Ĭ�ϴ�������ƥ���ַ������Բ����ص�������л������ͬѧָ������
            return i-plen+1;//������Ӧ��λ��
        }
    }
    return -1;
}


int main()
{
        char str[] = "bacbababadababacambabacaddababacasdsd";
    char ptr[] = "ababaca";
    int a = KMP(str, 36, ptr, 7);
    printf("%d",a);
    return 0;

}