
#include <iostream>


using namespace std;


void maximum(double& max_num, double value) {

    if (value > max_num) {

        max_num = value;

    }

}

void minimum(double& min_num, double value) {

    if (value < min_num) {

        min_num = value;

    }

}


void receive_values() {

    int num_of_entries;
    double max = -2147483647;
    double min = 2147483647;
    double sum = 0;
    double user_value;

    cout << "Enter the number of entries you would like: ";
    cin >> num_of_entries;

    for (int entry = 0; entry < num_of_entries; entry++) {


        cin >> user_value;

        maximum(max, user_value);
        minimum(min, user_value);

        



  

    }

    cout << max;
    cout << min;

}




int main()
{


    receive_values();

}

