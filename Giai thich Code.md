#include <iostream>
#include <string>
#include <iostream>: Thư viện này cung cấp các chức năng để thực hiện nhập (input) và xuất (output) dữ liệu trong C++. Nó cho phép chúng ta sử dụng cin (nhập dữ liệu) và cout (xuất dữ liệu).

#include <string>: Thư viện này cho phép chúng ta sử dụng kiểu dữ liệu chuỗi (string), giúp làm việc với văn bản dễ dàng hơn.


using namespace std;
Lệnh này cho phép chúng ta sử dụng các thành phần trong không gian tên std mà không cần phải viết std:: trước mỗi từ khóa như cout, cin, string, v.v.


struct Question {
    string questionText;
    string options[4];  // 4 lựa chọn cho mỗi câu hỏi
    int correctOption;  // Đáp án đúng (0, 1, 2, 3)
};
struct Question: Đây là khai báo một cấu trúc dữ liệu để lưu trữ thông tin của một câu hỏi. Cấu trúc này bao gồm:

string questionText: Chuỗi lưu trữ câu hỏi.

string options[4]: Mảng lưu trữ 4 lựa chọn cho câu hỏi. Mỗi phần tử trong mảng là một chuỗi (ví dụ: "- Hà Nội").

int correctOption: Lưu trữ chỉ số (index) của lựa chọn đúng trong mảng options. Các chỉ số này bắt đầu từ 0 (ví dụ: nếu đáp án đúng là lựa chọn thứ nhất, thì giá trị của correctOption sẽ là 0).


int main() {
int main(): Đây là hàm main(), điểm bắt đầu của chương trình. Mọi chương trình C++ đều bắt đầu từ hàm này.


    Question quiz[] = {
Question quiz[]: Đây là mảng quiz, chứa các câu hỏi trong trò chơi. Mảng này có kiểu Question (cấu trúc đã khai báo trước đó) và chứa nhiều câu hỏi.


        {"Câu hỏi 1 Thủ đô của Việt Nam là", {"- Hà Nội", "- Hồ Chí Minh", "- Đà Nẵng", "- Nha Trang"}, 0},
Mỗi phần tử của mảng quiz là một câu hỏi, với cấu trúc:

Câu hỏi: Một chuỗi (ví dụ: "Câu hỏi 1 Thủ đô của Việt Nam là").

Các lựa chọn: Một mảng chứa 4 lựa chọn (ví dụ: {"- Hà Nội", "- Hồ Chí Minh", "- Đà Nẵng", "- Nha Trang"}).

Đáp án đúng: Chỉ số của lựa chọn đúng (ví dụ: 0 cho lựa chọn đầu tiên là "Hà Nội").

Cả mảng quiz chứa 10 câu hỏi, mỗi câu hỏi có dạng tương tự như vậy.


 int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
 sizeof(quiz): Trả về kích thước của toàn bộ mảng quiz (tính bằng byte).
 sizeof(quiz[0]): Trả về kích thước của một phần tử trong mảng quiz (tức là một câu hỏi).

Khi chia sizeof(quiz) cho sizeof(quiz[0]), ta được số lượng câu hỏi trong mảng (tổng số phần tử trong mảng quiz).


    int score = 0;
int score = 0;: Khai báo biến score để theo dõi số điểm của người chơi. Ban đầu, điểm là 0.


    cout << "Chào mừng bạn đến với trò chơi đố vui" << endl;
cout: Xuất thông báo chào mừng đến người chơi. Sau thông báo, endl sẽ chèn một ký tự xuống dòng.


    for (int i = 0; i < totalQuestions; i++) {
for (int i = 0; i < totalQuestions; i++): Vòng lặp này sẽ lặp qua tất cả các câu hỏi trong mảng quiz. Biến i bắt đầu từ 0 và sẽ tiếp tục cho đến totalQuestions - 1.


        cout << quiz[i].questionText << endl;
cout << quiz[i].questionText << endl;: In ra câu hỏi hiện tại (sử dụng i để truy cập phần tử tương ứng trong mảng quiz).

        for (int j = 0; j < 4; j++) {
            cout << quiz[i].options[j] << endl;
        }
for (int j = 0; j < 4; j++): Vòng lặp này sẽ in ra tất cả các lựa chọn của câu hỏi hiện tại. j duyệt qua mảng options (có 4 phần tử).

cout << quiz[i].options[j] << endl;: In từng lựa chọn của câu hỏi.



        int playerAnswer;
        cout << "Nhập số câu trả lời (1-4): ";
        cin >> playerAnswer;
int playerAnswer;: Khai báo biến để lưu trữ lựa chọn của người chơi.

cin >> playerAnswer;: Nhận đầu vào từ người chơi (số từ 1 đến 4).


        if (playerAnswer - 1 == quiz[i].correctOption) {
if (playerAnswer - 1 == quiz[i].correctOption): Kiểm tra xem lựa chọn của người chơi có đúng không. Vì các chỉ số trong mảng bắt đầu từ 0, nên ta phải trừ đi 1 từ playerAnswer trước khi so sánh.


            cout << "Đúng rồi +1 điểm" << endl;
            score++;
Nếu người chơi chọn đúng, chương trình sẽ thông báo "Đúng rồi +1 điểm" và tăng điểm số (score++).


        } else {
            cout << "Sai rồi Câu trả lời đúng là: " << quiz[i].options[quiz[i].correctOption] << endl;
        }
Nếu người chơi chọn sai, chương trình sẽ thông báo đáp án đúng.


        cout << endl;
    }
Sau mỗi câu hỏi, chương trình sẽ xuống dòng để dễ nhìn.


    cout << "Trò chơi kết thúc Bạn đã trả lời đúng " << score << " trên " << totalQuestions << " câu hỏi" << endl;
Cuối cùng, chương trình sẽ in ra điểm số của người chơi sau khi kết thúc trò chơi.


    return 0;
}
return 0;: Kết thúc hàm main() và trả về giá trị 0, thông báo rằng chương trình đã chạy thành công.

Tóm lại:
Chương trình này tạo ra một trò chơi đố vui đơn giản, nơi người chơi trả lời 10 câu hỏi và nhận điểm dựa trên số câu trả lời đúng. Mỗi câu hỏi có 4 lựa chọn, và người chơi phải nhập số tương ứng với lựa chọn của mình. Sau khi hoàn thành trò chơi, chương trình sẽ hiển thị điểm số của người chơi.




