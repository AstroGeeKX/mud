#include <iostream>
#include <string>
#include <cstdio>

// �ƹ���Դ���࣬�Ĵ���ȫ��ɾ�⣬Ȼ���Ķ�����������
class Suff
{
public:
    std::string s;
    void *p; // ָ����Դ

    Suff() : s("Ĭ�Ϲ���Ķ���")
    {
        p = malloc(1);
        std::cout << "���ù��캯��" << std::endl;
    }

    // ɾ���Ĵ���
    // Suff(Suff &&) = delete;
    Suff(Suff const &) = delete;            // ��ʡ�Բ�д
    // Suff &operator=(Suff &&) = delete;      // ��ʡ�Բ�д
    // Suff &operator=(Suff const &) = delete; // ��ʡ�Բ�д
    
    // **��������**
    // explicit Suff(Suff const &that) : s("��������Ķ���")
    // {
    //     std::cout << "���ÿ������캯��" << std::endl;
    // }

    // **�ƶ�����** �ƶ����������Դ���ڣ���ԭ��Դ���٣������Ͳ������������Դ�����
    Suff(Suff &&that) : s("�ƶ�����Ķ���"), p(that.p)
    {
        that.p = nullptr; // һ��Ҫ�ѶԷ��ÿգ�
        std::cout << "�����ƶ����캯��" << std::endl; 
    }

    // **������ֵ** ��ֵ���ǹ��죬��ʹ�����Ĵ���������û�й���
    // Suff &operator=(Suff const &that)
    // {
    //     s = "������ֵ�Ķ���";
    //     std::cout << "���ÿ�����ֵ����" << std::endl;
    //     return *this;
    // }

    ~Suff()
    {
        if (p)
        {
            std::cout << "~����" << " " << s;
            std::cout << " �ͷ�ָ��p" << std::endl;
            free(p);
        }
        else
        {
            std::cout << "~����" << " " << s << std::endl;
        }
    }
};

void func(Suff x)
{
}

// ��Դ����һ���ص������ƶ����죬��Դת�ƣ���������ͷ���Դ
// �ƶ������ｫԭ��Դ������գ�������������if�ж���Դָ���Ƿ����Ȼ�����ͷ�

int main()
{
    auto suff = Suff();
    func(std::move(suff));
    // Suff suff2(std::move(suff)); // suff2�������� suff3�ƶ����� move��c++�ؼ���std::move()
    // �����ƶ�����û��ʵ�֣���ʹ����move������ֵ����ô����ʽ���ÿ�������
    // Suff suff3;
    // suff3 = suff; // �״δ����¶���ֻ����ù�������Ǹ�ֵ =��ֵ��ת��Ϊ()����

    return 0;
}
