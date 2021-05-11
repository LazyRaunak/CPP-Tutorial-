// #include <iostream>

// using namespace std;

// int main(){
//     int val;
//     for(int i=1; i<5; i++){
//         val = 10;
//         val *= i;
//         cout<<"Value inside for loop is: "<<val<<endl;
//     }
//     cout<<"Value outside for loop is: "<<val<<endl;

//     return 0;
// }
/*---------------------------------------------------------------------------------------------------------*/
// #include <stdio.h>
// extern int x = 32;
// int b = 8;
// int main() {
//    extern int b;
//    printf("The value of extern variables x and b : %d,%d\n",x,b);
//    x = 15;
//    printf("The value of modified extern variable x : %d\n",x);
//    return 0;
// }
/*---------------------------------------------------------------------------------------------------------*/
// #include <iostream>

// using namespace std;

// class Base{
//     protected:
//         int x;
//     public:
//         Base(){ cout<<"Base derived constructor"<<endl; }

//         Base(int i){ x = i; }

//         virtual void draw() = 0;
//         int getX(){ return x;}
// };

// class Derived:public Base{
//     private:
//         int y;
//     public:
//         Derived(){ cout<<"Default derived constructor"<<endl; }

//         Derived(int i, int j)
//             :Base(i){ y = j;}

//         void draw(){ cout<<"x = "<<x<<", y = "<<y<<endl; }
// };

// int main(){
//     //Base b; throws error since it is an abstract class
//     Base *b = new Derived(5, 6); //pointers of abstract class type
//     b->draw();

//     Derived d;
//     d.draw();

//     Derived d1(4, 6);
//     d1.draw();

//     return 0;
// }
/*---------------------------------------------------------------------------------------------------------*/
// #include <iostream>
// #include <string>

// using namespace std;

// class InValidExceptionError{
//     public:
//         InValidExceptionError(){
//             cout<<"Amount entered is invalid"<<endl;
//         }
//         ~InValidExceptionError(){};
// };

// class Account{
//     protected:
//         double balance;
//     public:
//         Account()
//             :balance{5000}{
//                 cout<<"Default Account constructor"<<endl;
//             }

//         virtual void withdraw(int amount){
//             if(amount<0)
//                 throw InValidExceptionError();

//             if(balance-amount>0){
//                 cout<<"The updated balance after withdrawl is: "<<(balance-amount)<<endl;
//             }
//             else{
//                 cout<<"Insufficient funds."<<endl;
//             }
//         }
// };

// class Saving:public Account{
//     private:
//         double amount;

//     public:
//         Saving(){
//             cout<<"Account balance from Savings class constructor: "<<balance<<endl;
//         }

//         virtual void withdraw(double amount, double balanceVal){
//             balanceVal = balance - amount;
//             cout<<"The updated balance after withdrawl in Savings account is: "<<balanceVal<<endl;
//         }

//         ~Saving(){
//             cout<<"Saving account destructor"<<endl;
//         }
// };

// int main(){
//     Account Raunak;

//     try{
//         Raunak.withdraw(2000);
//     }

//     catch(InValidExceptionError &ex){
//     }

//     return 0;
// }
/*---------------------------------------------------------------------------------------------------------*/
// #include <iostream>

// using namespace std;

// class Original{
//     private:
//         int balance;

//     public:
//         Original()
//             :balance{0}{
//                 cout<<"Account setup done! Your balance is: "<<balance<<endl;
//             }

//         virtual void Deposit(double amount){
//             if (amount<0)
//                 throw exception();
//             balance += amount;
//             cout<<"Balance after deposit is: "<<balance<<endl;
//         }

//         Original(Original &dupAcc){
//             dupAcc.Deposit(5000);
//         }

//         ~Original(){
//             cout<<"Thank you for using our services."<<endl;
//         }
// };

// int main(){
//     Original Raunak;
//     Raunak.Deposit(2000);

//     Original Shreya = Raunak;

//     return 0;
// }
/*---------------------------------------------------------------------------------------------------------*/

// #include <iostream>

// using namespace std;

// class A{
//     private:
//         int a;

//     public:
//         A(int i){
//             a = i;
//         }

//     void operator+ (A &);
// };

// void A:: operator+ (A &operA){
//     int m = a + operA.a;
//     cout<<"Result of the addition of two objects is : "<<m<<endl;
// }

// int main(){
//     A a1(50);
//     A a2(22);
//     a1 + a2;
// }
/*---------------------------------------------------------------------------------------------------------*/
// #include <iostream>

// using namespace std;

// void swap(int *, int *);

// int main(){
//     int a{40}, b{30};
//     swap(&a, &b);

//     cout<<"Swapped values of 40, 40 are: "<<a<<", "<<b<<endl;

//     return 0;
// }

// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
/*---------------------------------------------------------------------------------------------------------*/

// #include <iostream>
// #include <memory>

// using namespace std;

// class Data{
//     private:
//         int data;
//     public:
//         Data()
//             :data{0}{
//                 cout<<"Data constructor with no args: "<<data<<endl;
//             }

//         Data(int dataVal):
//             data{dataVal}{
//                 cout<<"Data constructor with 1 arg: "<<data<<endl;
//             }

//         int getData() const{
//             return data;
//         }

//         ~Data(){
//             cout<<"Data destructor with arg value: "<<data<<endl;
//         }
// };

// int main(){
//     unique_ptr<Data> p1 = make_unique<Data>(5000);
//     unique_ptr<Data> p2;
//     p2 = move(p1);
//     p2.reset();

//     shared_ptr<Data> p3 = make_shared<Data>(2000);
//     shared_ptr<Data> p5;
//     shared_ptr<Data> p4{p3};
//     p5 = p3;
//     //p4{p3};


//     return 0;
// }
/*---------------------------------------------------------------------------------------------------------*/

// #include <iostream>
// #include <fstream>
// #include <sstream>

// void Read(){
//     std::string line;
//     std::string word;
//     std::ifstream inFile("SampleReadFile.txt");
//     if(inFile){
//         while(std::getline(inFile, line)){
//             // std::cout<<line<<std::endl;
//             std::stringstream ss(line);
//             while(ss>>word){
//                 std::cout<<word<<std::endl;
//             }
//         }
//     }
// }

// int main(){
//     Read();

//     return 0;
// }

/*---------------------------------------------------------------------------------------------------------*/

// #include <iostream>
// #include <vector>

// using namespace std;

// int main(){
//     vector<vector<int>> a{{1, 2, 3, 4}, {8, 7, 6, 5}};
//     vector<vector<int>> b{{1, 2, 3, 4}, {8, 7, 6, 5}};
//     vector<vector<int>> c[a.size()][a[0].size()];
//     int s;

//     for(int i=0; i<a.size(); i++){
//         for(int j=0; j<a[0].size(); j++){
//             a[i][j] = a[i][j] + b[i][j];
//         // c.push_back(s);
//         }
//     }

//     // for(const auto elem:c)
//     //     cout<<elem<<" ";

//     cout<<a.size()<<endl;
//     cout<<a[0].size()<<endl;
// }

#include <iostream>
// #include <algorithm>
// #include <vector>

using namespace std;

// int foo()
// {
//     static int i=1;
//     i++;
//     return i;

// }
// int main()
// {int value;
// value = foo();
// value = foo();
// cout<< value;
// return 0;
// }




// constant MAXSIZE1 = 100;
// #define MAXSIZE2 100
// static final int MAXSIZE3 = 100;
// #define MAXSIZE4=100
// define("MAXSIZE5", 100);

// int main()
// {
//     cout<<endl<<MAXSIZE1;
//     cout<<endl<<MAXSIZE2;
//     cout<<endl<<MAXSIZE3;
//     cout<<endl<<MAXSIZE4;
//     cout<<endl<<MAXSIZE5;
// }


// C++ program to find minimum difference between
// any pair in an unsorted array
// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>

// using namespace std;

// // Returns minimum difference between any pair
// int findMinDiff(vector <int> arr)
// {
//     int n = arr.size();

// // Sort array in non-decreasing order
// sort(arr.begin(), arr.end());

// // Initialize difference as infinite
// int diff = INT_MAX;

// // Find the min diff by comparing adjacent
// // pairs in sorted array
// for (int i=0; i<n-1; i++)
// 	if (arr[i+1] - arr[i] < diff)
// 		diff = arr[i+1] - arr[i];

// // Return min diff
// return diff;
// }

// // Driver code
// int main()
// {
// vector <int> arr = {1, 5, 3, 19, 18, 25};
// int n = sizeof(arr)/sizeof(arr[0]);
// auto res = findMinDiff(arr);
// cout << "Minimum difference is " << res;
// return 0;
// }



// #include <iostream>
// using namespace std;
// int anagram(char str1[], char str2[])
// {
//     int i, flag = 0,  x[26] = {0}, y[26] = {0};
//     for(i = 0; str1[i] != '\0'; i++)
//         x[str1[i] - 'a']++;
//     for(i = 0; str2[i] != '\0'; i++)
//         y[str2[i] - 'a']++;
//     for (i = 0; i < 26; i++)
//     {
//         if (x[i] != y[i])
//             flag = 1; 
//     }
//     if (flag == 1)
//         cout << "Entered strings are not anagrams.";
//     else
//         cout << "Entered strings are anagrams.";
// }
 
// int main ()
// {
//     char str1[50], str2[50];
//     int flag;
//     cout << "Enter string 1 : ";
//     gets(str1);
//     cout << "Enter string 2 : ";
//     gets(str2);
//     anagram(str1, str2);
//     return 0;
// }


// #include <iostream>
// #include <string>
// #include<bits/stdc++.h>

// using namespace std;

// int check()
// {
//         //Initializing variables.
//     // char str1[100],str2[100];
//     string str1, str2;
//     int first[26]={0}, second[26]={0}, c=0, flag=0;
    
//     //Accepting inputs.
//     cout<<"Enter First String: ";
//     cin>>str1;
//     cout<<"Enter Second String: ";
//     cin>>str2;

//     transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
//     transform(str2.begin(), str2.end(), str2.begin(), ::tolower);    
    
//     //Calculating frequencies of characters in first string.
//     while(str1[c] != '\0')
//     {
//         first[str1[c]-'a']++;
//         c++;
//     }
     
//     c=0;
//     //Calculating frequencies of characters in second string. 
//     while(str2[c] != '\0')
//     {
//         second[str2[c]-'a']++;
//         c++;
//     }
//     //Checking if frequencies of both the strings are same or not.
//     for(c=0;c<26;c++)
//     {
//         if(first[c] != second[c])
//             flag=1;
//     }
//     //Priting result.
//     if(flag == 0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// int main()
// {
//     int val = check();
//     cout<<"val: "<<val;
//     return 0;
  
// }

// #include<iostream>

// using namespace std;

// int main()
// {
// 	for(int i=0; i<6; i++)
// 	{
// 		for(int j=i; j<6; j++)
// 		{
// 			if((j%2) == 0)
// 				cout<<"1";
// 			else
// 				cout<<"0";
// 		}
// 		cout<<endl;
// 	}
	
// 	return 0;
// }
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>

#define Cols 3
struct SplitLine {
    std::string fields[Cols];
};

enum rIndex {
    ID = 0,
    Sub,
    Marks
};

int processData(std::vector<struct SplitLine> data) {

    std::map<int, int> student; 

    for (auto mark : data) {
        int sId = stoi(mark.fields[ID]);
        int sMarks = stoi(mark.fields[Marks]);

        auto itr = student.find(sId);
        if (itr != student.end()) { 
            int tempMarks = sMarks + itr->second;
            itr->second = tempMarks;
        } else {
            student.insert(std::make_pair(sId, sMarks));
        }
    }

    int count = 0;
    for (auto s : student) {
        if (s.second >= 100) {
            count++;
        }
    }
    return count;
}

int main(void) {
    std::ifstream in("C:\\Users\\Raunak\\Desktop\\FlexTrade\\Data.txt");
    std::vector<struct SplitLine> input_data;
    while (in) {
        struct SplitLine line;
        for (int i = 0; i<Cols; i++) {
            if (i == Cols - 1)
                std::getline(in, line.fields[i]);
            else
                std::getline(in, line.fields[i], ',');
        }
        if (line.fields[0] != "")
            input_data.push_back(line);
    }
	cout<<"The total no. of students are: "<<processData(input_data)<<endl;
    // std::ofstream out("C:\\Users\\Raunak\\Desktop\\FlexTrade\\output.txt");
    // out << processData(input_data) << std::endl;
    // return 0;
}