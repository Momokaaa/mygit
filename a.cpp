/**
 *      author:   22001010217陈通博
**/
#include<bits/stdc++.h>
using namespace std;

class csv_check {
    vector<string> R_Stu, W_Stu;
    vector<vector<string>> r_Stu, w_Stu;
    int r_count = 0;
    int w_count = 0;
    string inf[17] = {"序号", "学号", "姓名", "年级", "年级", "层次", "实习方式", "单位名称", "企业所在地", "企业详细地址", "企业详细地址", "社会统一信用代码", "实习岗位", "是否专业对口", "企业联系人", "开始时间", "结束时间"};
    
public:
    void input() {
        auto in = [&](vector<string>& Stu, vector<vector<string>> &stu, int& count) {
            int sum = 0;
            string s, temp;
            while (getline(cin, s)) {
                Stu.push_back(s);
                stringstream ss(s);
                int flag = 1;
                vector<string> add;
                while (getline(ss, temp, ',')) {
                    add.push_back(temp);
                }
                stu.push_back(add);
                sum++;
            }
            count = sum;
        };
        freopen("a.csv", "r", stdin);
        in(R_Stu, r_Stu, r_count);
        cin.clear();
        freopen("b.csv", "r", stdin);
        in(W_Stu, w_Stu, w_count);
        cin.clear();
    }

    void check() {
        int seqr = 0, seqw = 0;
        while (seqw < w_count) {
            if (seqr - 1 >= 0 && W_Stu[seqw] == R_Stu[seqr - 1]) {
                cout << w_Stu[seqw][2] << "数据重复" << '\n';
                seqw++;
                continue;
            }
            else {
                int sum = 0;
                for (int j = 0; j < 17; j++) {
                    if (w_Stu[seqw][j] != r_Stu[seqr][j]) {
                        sum++;
                    }
                }
                if (sum > 1) {
                    cout << r_Stu[seqr][2] << "数据遗漏" << '\n';
                    seqr++;
                    continue;
                }
                else {
                    for (int j = 0; j < 17; j++) {
                        if (w_Stu[seqw][j] != r_Stu[seqr][j]) {
                            cout << r_Stu[seqr][2] << ',' << inf[j] <<  "错误, 正确应为" << r_Stu[seqr][j] << ' ' <<  w_Stu[seqw][j] << '\n';
                        }
                    }
                    seqr++, seqw++;
                    continue;
                }
                seqr++, seqw++;
            }
        }
    }

};

int main() {
    csv_check A;
    A.input();
    A.check();
}

