

#include <iostream>

using namespace std;


void ra7_q1() {

    int user_value;
    int user_array[20];

    cout << "Enter a number: ";
    cin >> user_value;

    for (int i = 0; i < user_value; i++) {

        int num;
        cin >> num;
        user_array[i] = num + (rand() % 100);
    }

    for (int i = 0; i < user_value; i++) {

        cout << user_array[i] << " ";
    }


}

void swap(int& num1, int& num2){

    int num = num1;

    num1 = num2;
    num2 = num;

}


void ra7_q2_create_array() {

    int my_array[10];

    for (int i = 0; i < 10; i++) {
        my_array[i] = rand() % 99;
    }

    for (int i = 0; i < 10; i++) {

        bool not_sorted = (i > 0) && (my_array[i] < my_array[i - 1]);

        if (not_sorted) {
            
            int first_num = my_array[i - 1];
            int second_num = my_array[i];

            swap(first_num, second_num);

            my_array[i - 1] = second_num;
            my_array[i] = first_num;

            i = 0;

        }

    }


    for (int i = 0; i < 10; i++) {

        cout << my_array[i] << " ";
    }




    

}




int main()
{
    //ra7_q1();
    ra7_q2_create_array();
}

