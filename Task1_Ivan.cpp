#include <iostream>
#include <cmath>

int count_step_num(int m, int n);

int main()
{
    int lower,upper,pom;
    int solution=0;
    std::cout << "Type lower and upper limit:\n";
    std::cin >> lower;
    std::cin >> upper;
    std::cout << "lower = "<<lower<<'\n'<<"upper = "<<upper<<"\n";
    if(upper < lower)  // First argument must be smaller then second
    {
        pom = lower;
        lower = upper;
        upper = pom;
    }
    solution = count_step_num(lower,upper);
    std::cout << "There are "<<solution<<" stepping numbers between "<<lower<<" and "<<upper<<"\n";

    return 0;
}

int count_step_num(int m,int n)
{
    int pom,i;
    int isValid;
    int dig_l,dig_h;     // Lower and upper digit
    int cnt = 0;        // Count stepping numbers
    for(i=m;i<=n;i++)
    {
        pom=i;
        isValid = 1;
        while(pom >= 10)
        {
            dig_l = pom%10;
            dig_h = pom/10;
            dig_h =dig_h%10;
            if(std::abs(dig_l-dig_h)!=1)
            {
                isValid = 0;
                break;
            }
            pom /=10;

        }

        if((isValid == 1) || (i< 10))
            cnt++;
    }
    return cnt;
}
