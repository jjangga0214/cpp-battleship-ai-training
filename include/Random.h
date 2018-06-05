//c++ BattleShip 프로젝트
//작성 일자 : 2018-06-02
//학번 : 20171636 이름 : 손현기


#include <iostream>
#include <cstdlib>

using namespace std;

class Make {
public:
    void Select_position(int arr_size, int left[], int right[], int c_arr[][8]) {

        int left_value;
        int right_value;
	char data;
	if (arr_size==5){
		data = 1;
	}
	else if (arr_size==4){
		data = 1;
	}
	else if (arr_size==3){
		data = 1;
	}
	else if (arr_size==2){
		data = 1;
	}


        for (int i = 0; i < arr_size; i++) {
            left_value = left[i];
            right_value = right[i];
            c_arr[left_value][right_value] = data;
        }
    }

    bool Boundary(int x, int y) {
        bool flag = true;
        if (x> 7 || x < 0 || y> 7 || y < 0) {
            flag = false;
        }
        return flag;
    }

    int Random_select_position(int le, int ri, int dir, int size, int check_arr[][8]) {
        int result = -1;
        int count = 0;
        int left_data[size];
        int right_data[size];
        int flag = 0;

        if (dir == 0) { // 북
            if (check_arr[le][ri] != 0 || Boundary(le, ri) == false) {
                return result;
            } else {
                left_data[count] = le;
                right_data[count] = ri;
                count++;

                for (int i = 0; i < size; i++) {
                    le = le - 1;
                    if (check_arr[le][ri] == 0 && Boundary(le, ri) == true) {
                        left_data[count] = le;
                        right_data[count] = ri;
                        count++;
                    } else {
                        flag = -1;
                        break;
                    }
                }
                if (flag == 0) {
                    Select_position(size, left_data, right_data, check_arr);
                    result = 0;
                }

            }
        } else if (dir == 1) { // 동

            if (check_arr[le][ri] != 0 || Boundary(le, ri) == false) {
                return result;
            } else {
                left_data[count] = le;
                right_data[count] = ri;
                count++;
                for (int i = 0; i < size; i++) {
                    ri = ri + 1;
                    if (check_arr[le][ri] == 0 && Boundary(le, ri) == true) {
                        left_data[count] = le;
                        right_data[count] = ri;
                        count++;
                    } else {
                        flag = -1;
                        break;
                    }
                }
                if (flag == 0) {
                    Select_position(size, left_data, right_data, check_arr);
                    result = 0;
                }
            }

        } else if (dir == 2) { // 남

            if (check_arr[le][ri] != 0 || Boundary(le, ri) == false) {
                return result;
            } else {
                left_data[count] = le;
                right_data[count] = ri;
                count++;
                for (int i = 0; i < size; i++) {
                    le = le + 1;
                    if (check_arr[le][ri] == 0 && Boundary(le, ri) == true) {
                        left_data[count] = le;
                        right_data[count] = ri;
                        count++;
                    } else {
                        flag = -1;
                        break;
                    }
                }
                if (flag == 0) {
                    Select_position(size, left_data, right_data, check_arr);
                    result = 0;
                }
            }

        } else if (dir == 3) {//서

            if (check_arr[le][ri] != 0 || Boundary(le, ri) == false) {
                return result;
            } else {
                left_data[count] = le;
                right_data[count] = ri;
                count++;
                for (int i = 0; i < size; i++) {
                    ri = ri - 1;
                    if (check_arr[le][ri] == 0 && Boundary(le, ri) == true) {
                        left_data[count] = le;
                        right_data[count] = ri;
                        count++;
                    } else {
                        flag = -1;
                        break;
                    }
                }
                if (flag == 0) {
                    Select_position(size, left_data, right_data, check_arr);
                    result = 0;
                }
            }
        }


        return result;

    }

   // void Print_arr() {
    //    for (int i = 0; i < 8; i++) {
      //      for (int i2 = 0; i2 < 8; i2++) {
     //           cout << check_arr[i][i2] << " ";
     //       }
       //     cout << "\n";
  //      }
   // }


};

