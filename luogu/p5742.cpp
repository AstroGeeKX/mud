// P5742 【深基7.例11】评等级

#include <iostream>
#include <vector>

using namespace std;

struct Students
{
    int academicScore = 0;
    int qualityScore = 0;
    int comprehensiveScore = 0;

    int calComprehensiveScore()
    {
        comprehensiveScore = 7 * academicScore + 3 * qualityScore;
        return comprehensiveScore;
    }
};

int main()
{
    int n;
    int damn; // 这是个没有用的占位符
    cin >> n;
    vector<Students> scores(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> damn >> scores[i].academicScore >> scores[i].qualityScore;
        scores[i].calComprehensiveScore(); // 计算总分，内容存在结构体成员变量里
    }
    for (size_t i = 0; i < n; i++)
    {
        if (scores[i].academicScore + scores[i].qualityScore > 140 && scores[i].comprehensiveScore >= 800)
            cout << "Excellent" << endl;
        else
            cout << "Not excellent" << endl;
    }
    
    return 0;
}