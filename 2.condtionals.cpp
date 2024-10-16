#include <iostream>

using namespace std;

// conditional statements
// if
// else
// else if

//! example of if statem
// if the n == 10 then print "n is 10"
void print()
{
    int n = 10;
    if (n == 10)
    {
        cout << "n is 10" << endl;
    }
    
}

//! example of if else statement
// if the n == 10 then print "n is 10" else print "n is not 10"
void print2()
{
    int n = 10;
    if (n == 10)
    {
        cout << "n is 10" << endl;
    }
    else
    {
        cout << "n is not 10" << endl;
    }
}

//! example of if else if statement
// if the n == 10 then print "n is 10" else if n == 20 then print "n is 20" else print "n is not 10 or 20"
void print3()
{
    int n = 10;
    if (n == 10)
    {
        cout << "n is 10" << endl;
    }
    else if (n == 20)
    {
        cout << "n is 20" << endl;
    }
    else
    {
        cout << "n is not 10 or 20" << endl;
    }
}



int main()
{

    // sins
    // > greter then
    // <less then
    // >= greter then equal to
    // <= less then equal to

    // conditional statements
    // if
    // else
    // programming problem
    // wap that takes input as age and print you are
    // and adult or not

    // int age;
    // cin >> age;
    // if (age >= 18)
    // {
    //     cout << "you are an adult";
    // }
    // else{
    //     cout<<"you are not an adult";
    // }

    // problem:2 get marks from the use and
    // print grade according the marks
    // int marks;
    // cin >> marks;

    // if (marks < 25)
    // {
    //     cout << "Grade: F" << endl;
    // }
    // else if (marks >= 25 && marks <= 44)
    // {
    //     cout << "Grade: E" << endl;
    // }
    // else if (marks >= 45 && marks <= 49)
    // {
    //     cout << "Grade: D" << endl;
    // }
    // else if (marks >= 50 && marks <= 59)
    // {
    //     cout << "Grade: C" << endl;
    // }
    // else if (marks >= 60 && marks <= 69)
    // {
    //     cout << "Grade: B" << endl;
    // }
    // else if (marks >= 70)
    // {
    //     cout << "Grade: A" << endl;
    // }
    // else
    // {
    //     cout << "Invalid marks entered." << endl;
    // }

    // use of && for checking multiple conditon
    // (condition 1 && condition 2)

    /*
    take the age from the user and then decide accourding

    1. if age < 18
    print(not eligible for the job)

    2. if age >= gether then equal to 18 or <= less then eual to 54
    print(eligible for the job)

    3.if age >= 55 and >= 57
    print(aligible for job nut retirment soon)

    if age >57
    print (retirement soon)

    */

    // for this quation we use nested if else statements

    int age;
    cin >> age;
    if (age < 18)
    {
        cout << "not eligible for the job";
    }
    else if (age <= 57)
    {
        cout << "eligible for the job";
        if (age <= 57)
        {
            cout << "retirment soon";
        }
    }
    else
    {
        cout << "retirment time ";
    }

    return 0;
}