#include <iostream>
#include <string>

using namespace std;

struct Question {
    string questionText;
    string options[4];  // 4 lựa chọn cho mỗi câu hỏi
    int correctOption;  // Đáp án đúng (0, 1, 2, 3)
};

int main() {
    // Tạo các câu hỏi
    Question quiz[] = {
        {"Cau hoi 1: Thu do cua Viet Nam la?", {"- Ha Noi", "- Ho Chi Minh", "- Da Nang", "- Nha Trang"}, 0},
        {"Cau hoi 2: Lua gao la cay trong chu yeu o vung nao?", {"- Dong bang Song Hong", "- Dong bang song Cuu Long", "- Tay Nguyen", "- Mien nui phia Bac"}, 1},
        {"Cau hoi 3: Ai la nguoi sang lap ra Facebook?", {"- Mark Zuckerberg", "- Steve Jobs", "- Bill Gates", "- Elon Musk"}, 0},
        {"Cau hoi 4: Mon the thao nao có ten goi 'Mon the thao vua'?", {"- Bong ro", "- Bong chuyen", "- Bong da", "- Quan vot"}, 2},
        {"Cau hoi 5: Ngay sinh cua chu tich Ho Chi Minh ?", {"- 19/5/1980", "- 22/4/1980", "- 12/5/1980", "- 19/5/1982"}, 0},
        {"Cau hoi 6: Quoc gia nao co dien tich lon nhat the gioi ?", {"- Trung Quoc", "- Canada", "- Hoa Ky", "- Nga"}, 3},
        {"Cau hoi 7: Viet Nam co bao nhieu tinh thanh?", {"- 58 tinh, 2 thanh pho truc thuoc trung uong", "- 60 tinh, 3 thành phố trực thuộc trung ương", "- 65 tỉnh, 5 thành phố trực thuộc trung ương", "- 63 tỉnh, 5 thành phố trực thuộc trung ương"}, 3},
        {"Câu hoi 8: He mat troi co bao nhieu hanh tinh?", {"- 8", "- 9", "- 10", "- 7"}, 0},
        {"Câu hoi 9: Ai la tac gia cua 'Vo Chong A Phu'?", {"- To Hoai", "- Nguyen Minh Chau", "- Nguyen Tuan", "- Nam Cao"}, 0},
        {"Câu hoi 10: Nuoc nao san xuat nhieu ca phe nhat the gioi?", {"- Viet Nam", "- Brazil", "- Colombia", "- Ethiopia"}, 1}
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;

    cout << "Chao mung ban den voi tro choi do vui !!!" << endl;

    // Lặp qua các câu hỏi
    for (int i = 0; i < totalQuestions; i++) {
        cout << quiz[i].questionText << endl;

        // Hiển thị các lựa chọn
        for (int j = 0; j < 4; j++) {
            cout << quiz[i].options[j] << endl;
        }

        int playerAnswer;
        cout << "Nhap so cau tra loi (1-4): ";
        cin >> playerAnswer;

        // Kiểm tra đáp án
        if (playerAnswer - 1 == quiz[i].correctOption) {
            cout << "Dung roi! +1 Points!" << endl;
            score++;
        }
        else {
            cout << "Sai roi! Cau tra loi dung la: " << quiz[i].options[quiz[i].correctOption] << endl;
        }

        cout << endl;
    }

    cout << "Game End ! Ban da tra loi dung " << score << " tren " << totalQuestions << " cau hoi" << endl;

    return 0;
}
