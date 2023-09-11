/*
    CS22B1088
    Rachit Chandekar
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class coordinate
{
    private:
    double xnum, ynum;
    void operator!()
    {
        if (xnum < 0)
        {
            this->xnum = -xnum;
        }
        if (ynum < 0)
        {
            this->ynum = -ynum;
        }
    }
    public:
    coordinate()
    {
        this->xnum = -1;
        this->ynum = -1;
    }
    void operator=(double arr[])
    {
        this->xnum = arr[0];
        this->ynum = arr[1];
        !(*this);
    }
    void displayPoint()
    {
        cout<<"( "<<this->xnum<<" , "<<this->ynum<<" )\n";
    }
    friend double operator-(coordinate, coordinate);
};

double operator-(coordinate A, coordinate B)
{
    double x = A.xnum - B.xnum;
    double y = A.ynum - B.ynum;
    return (x * x + y * y);
}

int operator%(coordinate Arr[], coordinate P)
{
    double distancePoint = (P - Arr[0]) + (P - Arr[1]) + (P - Arr[2]);
    double distanceSquare = (Arr[0] - Arr[1]) + (Arr[1] - Arr[2]) + (Arr[2] - Arr[0]);
    distanceSquare = distanceSquare - distancePoint;
    return (distancePoint == distanceSquare);
}

int main()
{
    coordinate Arr[3];
    int set[3] = {0, 0, 0};
    while(1)
    {
        int option;
        cout<<"\nRIGHT TRIANGLE CHECKER\n";
        cout<<"Press '1' to set the value of a point.\n";
        cout<<"Press '2' to display the value of a point.\n";
        cout<<"Press '3' to display the length between two points.\n";
        cout<<"Press '4' to check if the triangle formed by the three points is right-angled or not.\n";
        cout<<"Press '5' to exit the program.\n";
        cin>>option;
        if (option == 1)
        {
            int k = -1;
            while (k < 0 || k > 2)
            {
                cout<<"\nWhich point[1, 2, 3]'s value do you want to set?\n";
                cin>>k;
                k--;
                cout<<"\n";
                if (k < 0 || k > 2)
                {
                    cout<<"Please enter 1, 2 or 3 only.\n";
                }
            }
            double P[2];
            cout<<"Enter the x-coordinate.\n";
            cin>>P[0];
            cout<<"Enter the y-coordinate.\n";
            cin>>P[1];
            Arr[k] = P;
            set[k] = 1;
        } else if (option == 2)
        {
            int k = -1;
            while (k < 0 || k > 2)
            {
                cout<<"\nWhich point[1, 2, 3]'s value do you want to display?\n";
                cin>>k;
                k--;
                cout<<"\n";
                if (k < 0 || k > 2)
                {
                    cout<<"Please enter 1, 2 or 3 only.\n";
                }
            }
            if (set[k] == 0)
            {
                cout<<"\nNo value has been set for the point.\n";
                continue;
            } else
            {
                Arr[k].displayPoint();
            }
        } else if (option == 3)
        {
            int k1 = -1, k2 = -1;
            while (k1 < 0 || k1 > 2 || k2 < 0 || k2 >2)
            {
                cout<<"\nWhich two points'[1, 2, 3] distance do you want to display?\n";
                cin>>k1>>k2;
                k1--;
                k2--;
                if (k1 < 0 || k1 > 2 || k2 < 0 || k2 > 2)
                {
                    cout<<"Please enter 1, 2 or 3 only.\n";
                }
            }
            if (set[k1] == 0 || set[k2] == 0)
            {
                cout<<"\nNo value has been set for a point.\n";
            } else
            {
                cout<<"\nThe distance between the two points is "<<sqrt(Arr[k1] - Arr[k2])<<".\n";
            }
        } else if (option == 4)
        {
            if (set[0] == 0 || set[1] == 0 || set[2] == 0)
            {
                cout<<"\nNo value has been set for a point.\n";
            } else
            {
                if ((Arr % Arr[0] + Arr % Arr[1] + Arr % Arr[2]) == 0)
                {
                    cout<<"\nThe triangle is not right-angled.\n";
                } else
                {
                    cout<<"\nThe triangle is right-angled.\n";
                }
            }
        } else if (option == 5)
        {
            break;
        } else
        {
            cout<<"\nPlease choose one of the above mentioned choices only.\n";
        }
    }
    return 0;
}