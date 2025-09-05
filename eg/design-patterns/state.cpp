#include <iostream>
#include <vector>
using namespace std;

// 抽象状态
class Sanji;
class AbstractState {
   public:
    virtual void working(Sanji* sanji) = 0;
    virtual ~AbstractState() {}
};

// 上午状态
class ForenoonState : public AbstractState {
   public:
    void working(Sanji* sanji) override;
};
// 中午状态
class NoonState : public AbstractState {
   public:
    void working(Sanji* sanji) override;
};
// 下午状态
class AfternoonState : public AbstractState {
   public:
    void working(Sanji* sanji) override;
};
// 晚上状态
class EveningState : public AbstractState {
   public:
    void working(Sanji* sanji) override;
};

// 三治类定义
class Sanji {
   public:
    Sanji() { m_state = new ForenoonState; }
    void working() { m_state->working(this); }
    void setState(AbstractState* state) {
        if (m_state != nullptr) {
            delete m_state;
        }
        m_state = state;
    }
    void setClock(int time) { m_clock = time; }
    int getClock() { return m_clock; }
    ~Sanji() { delete m_state; }

   private:
    int m_clock = 0;  // 时钟
    AbstractState* m_state = nullptr;
};

void ForenoonState::working(Sanji* sanji) {
    int time = sanji->getClock();
    if (time < 8) {
        cout << "当前时间<" << time << ">点, 准备早餐, 布鲁克得多喝点牛奶..."
             << endl;
    } else if (time > 8 && time < 11) {
        cout << "当前时间<" << time << ">点, 去船头钓鱼, 储备食材..." << endl;
    } else {
        sanji->setState(new NoonState);
        sanji->working();
    }
}

void NoonState::working(Sanji* sanji) {
    int time = sanji->getClock();
    if (time < 13) {
        cout << "当前时间<" << time << ">点, 去厨房做午饭, 给路飞多做点肉..."
             << endl;
    } else {
        sanji->setState(new AfternoonState);
        sanji->working();
    }
}

void AfternoonState::working(Sanji* sanji) {
    int time = sanji->getClock();
    if (time < 15) {
        cout << "当前时间<" << time
             << ">点, 准备下午茶, 给罗宾和娜美制作爱心甜点..." << endl;
    } else if (time > 15 && time < 18) {
        cout << "当前时间<" << time << ">点, 和乔巴去船尾钓鱼, 储备食材..."
             << endl;
    } else {
        sanji->setState(new EveningState);
        sanji->working();
    }
}

void EveningState::working(Sanji* sanji) {
    int time = sanji->getClock();
    if (time < 19) {
        cout << "当前时间<" << time << ">点, 去厨房做晚饭, 让索隆多喝点汤..."
             << endl;
    } else {
        cout << "当前时间<" << time << ">点, 今天过得很高兴, 累了睡觉了..."
             << endl;
    }
}

int main() {
    Sanji* sanji = new Sanji;
    // 时间点
    vector<int> data{7, 10, 12, 14, 16, 18, 22};
    for (const auto& item : data) {
        sanji->setClock(item);
        sanji->working();
    }
    delete sanji;

    return 0;
}

// 作者: 苏丙榅
// 链接:
// https://subingwen.cn/design-patterns/state/#2-3-%E5%B7%A5%E4%BD%9C%E6%97%A5%E5%BF%97
// 来源: 爱编程的大丙
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
