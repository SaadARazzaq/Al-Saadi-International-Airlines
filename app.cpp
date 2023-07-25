#include <iostream>
#include <iomanip>
using namespace std;

namespace Color {
    const string RESET = "\033[0m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string BLUE = "\033[34m";
}

/*
COMMENTED BLOCK BELOW FOR GRID FUNCTION IMPLEMENTATION IS A DIFFERENT APPROACH YET UNSECCESSFUL 👇
*/

// void grid(int& row, int& col){
//     static char matrix[13][6];
//     if(matrix[row][col] == 'X'){
//         cout<<"\n\t\t***SEAT ALREADY OCCUPIED***\n\n";
//     }
//     else {
//         cout<<"\tA\tB\tC\tD\tE\tF\n\n";
//         for(int i = 0; i<13; i++){
//             cout<<"Row "<<i+1;
//             for(int j = 0; j<6; j++){
//                 if(matrix[i][j] == matrix[row][col]){
//                     matrix[row][col] = 'X';
//                     cout<<"\tX";
//                 }
//                 else{
//                     if(matrix[i][j] == 'X'){
//                         break;
//                     }
//                     else {
//                         matrix[i][j] = '*';
//                     }
//                     cout<<"\t*";
//                 }
//             }
//             cout<<endl<<endl;
//         }
//     }
// }


/*
BELOW GRID FUNCTION IMPLEMENTATION IS SUCCESSFUL APPROACH 👇 
*/

void grid(int& row, int& col){
    static char matrix[13][6];
    
    if(matrix[row][col] == 'X'){
        cout << "\n\t\t***SEAT ALREADY OCCUPIED***\n\n";
    }
    else {
        matrix[row][col] = 'X'; // Mark the seat as booked
        cout << "\n" << Color::YELLOW << "\tA\tB\tC\tD\tE\tF" << Color::RESET << "\n\n";
        for(int i = 0; i < 13; i++){
            cout << Color::YELLOW << "Row " << i + 1;
            for(int j = 0; j < 6; j++){
                if(matrix[i][j] == 'X'){
                    cout << Color::RED << '\t' << matrix[i][j] << Color::RESET;
                }
                else{
                    matrix[i][j] = '*';
                    cout << Color::GREEN << '\t' << matrix[i][j] << Color::RESET;
                }
            }
            cout << endl << endl;
        }
    }
}

int main(){
    int row, col, _class;
    cout << Color::GREEN <<"\n\t**WELCOME TO AL SAADI INTERNATIONAL AIRLINES**\n\n  " << Color::RESET;

    while (true){
        cout << Color::YELLOW;
        cout <<'\t'<< setw(40) << setfill('*') << "" << setfill(' ') << endl;
        cout <<'\t'<< "*"
             << setw(38) << ""
             << "*" << endl;
        cout <<'\t'<< "*"
             << setw(10) << "" << Color::BLUE << "To Book a seat" << Color::YELLOW << setw(14) << ""
             << "*" << endl;
        cout <<'\t'<< "*"
             << setw(38) << ""
             << "*" << endl;
        cout <<'\t'<< "*"
             << setw(38) << ""
             << "*" << endl;
        cout <<'\t'<< "*"
             << setw(9) << "" << Color::YELLOW << "1. First Class" << setw(15) << ""
             << "*" << endl;
        cout <<'\t'<< "*"
             << setw(9) << "" << Color::YELLOW << "2. Business Class" << setw(12) << ""
             << "*" << endl;
        cout <<'\t'<< "*"
             << setw(9) << "" << Color::YELLOW << "3. Economy Class" << setw(13) << ""
             << "*" << endl;
        cout <<'\t'<< "*"
             << setw(9) << "" << Color::YELLOW << "4. EXIT PROGRAM" << setw(14) << ""
             << "*" << endl;
        cout <<'\t'<< "*"
             << setw(38) << ""
             << "*" << endl;
        cout <<'\t'<< setw(40) << setfill('*') << "" << setfill(' ') << endl;
        cout << Color::RESET;
        cin>> _class;
        switch(_class){
            case 1:
                cout << "\033[2J\033[1;1H";  // to clear screen
                cout<<Color::YELLOW<<"\t---------------------";
                cout<<"\n\tYOU CHOSE FIRST CLASS\n";
                cout<<"\t---------------------\n\n"<<Color::RESET;
                cout<<"Enter row in which you want seat (row 1 or row 2): ";
                cin>>row;
                while(row!=1 && row!=2){
                    cout<<Color::RED<<"\n\tINVALID ROW IN FIRST CLASS!\n"<<Color::RESET;
                    cout<<"\nEnter row in which you want seat (row 1 or row 2): ";
                    cin>>row;
                    if(row == 1 || row == 2){
                        break;
                    }
                }
                cout<<"Enter which seat in row "<<row<<" you want (seat 1 to seat 6): ";
                cin>>col;
                while(col>6 || col<1){
                    cout<<Color::RED<<"\n\tINVALID SEAT IN FIRST CLASS!\n"<<Color::RESET;
                    cout<<"\nEnter which seat in row "<<row<<" you want (seat 1 to seat 6): ";
                    cin>>col;
                }
                row = row - 1;
                col = col - 1;
                grid(row, col);
            break;

            case 2:
                cout << "\033[2J\033[1;1H";  // to clear screen
                cout<<Color::YELLOW<<"\t------------------------";
                cout<<"\n\tYOU CHOSE BUSINESS CLASS\n";
                cout<<"\t------------------------\n\n"<<Color::RESET;
                cout<<"Enter row in which you want seat (row 3 - row 7): ";
                cin>>row;
                while(row!=3 && row!=4 && row!=5 && row!=6 && row!=7){
                    cout<<Color::RED<<"\n\tINVALID ROW IN BUSINESS CLASS!\n"<<Color::RESET;
                    cout<<"\nEnter row in which you want seat (row 3 - row 7): ";
                    cin>>row;
                    if(row == 3 || row == 4 || row == 5 || row == 6 || row == 7){
                        break;
                    }
                }
                cout<<"Enter which seat in row "<<row<<" you want (seat 1 to seat 6): ";
                cin>>col;
                while(col>6 || col<1){
                    cout<<Color::RED<<"\n\tINVALID SEAT IN BUSINESS CLASS!\n"<<Color::RESET;
                    cout<<"\nEnter which seat in row "<<row<<" you want (seat 1 to seat 6): ";
                    cin>>col;
                }
                row = row - 1;
                col = col - 1;
                grid(row, col);
            break;

            case 3:
                cout << "\033[2J\033[1;1H";  // to clear screen
                cout<<Color::YELLOW<<"\t-----------------------";
                cout<<"\n\tYOU CHOSE ECONOMY CLASS\n";
                cout<<"\t-----------------------\n\n"<<Color::RESET;
                cout<<"Enter row in which you want seat (row 8 - row 13): ";
                cin>>row;
                while(row!=8 && row!=9 && row!=10 && row!=11 && row!=12 && row!=13){
                    cout<<Color::RED<<"\n\tINVALID ROW IN ECONOMY CLASS!\n"<<Color::RESET;
                    cout<<"\nEnter row in which you want seat (row 8 - row 13): ";
                    cin>>row;
                    if(row == 8 || row == 9 || row == 10 || row == 11 || row == 12 || row == 13){
                        break;
                    }
                }
                cout<<"Enter which seat in row "<<row<<" you want (seat 1 to seat 6): ";
                cin>>col;
                while(col>6 || col<1){
                    cout<<Color::RED<<"\n\tINVALID SEAT IN ECONOMY CLASS!\n"<<Color::RESET;
                    cout<<"\nEnter which seat in row "<<row<<" you want (seat 1 to seat 6): ";
                    cin>>col;
                }
                row = row - 1;
                col = col - 1;
                grid(row, col);
            break;

            case 4:
                cout<<Color::BLUE<<"\t\t***YOU HAVE EXITED THE PROGRAM***\n\n"<<Color::RESET;
                exit(0);

            default:
                cout<<Color::RED<<"\t\t-- INVALID SET OF INPUTS :( !!! --\n\n"<<Color::RESET;
        }
        char ch;
        cout<<Color::GREEN<<"\n\n-> Do you want to register another seat? (y or n): "<<Color::RESET;
        cin>>ch;
        if (ch == 'y' || ch == 'Y'){
            cout << "\033[2J\033[1;1H";  // to clear screen
            continue;
        }
        else{
            break;
        }
    }
    return 0;
}
