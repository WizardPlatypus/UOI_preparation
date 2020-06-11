#include <iostream>

using namespace std;

int main()
{
    int answer;
    cout<<"Hello. Choose task:\n\t1.  Enter an integer n and print 2^n.\n\t2.  Enter n and print a binary representation of it.\n\t3.  Enter n and find the number of repetitions of 1 in binary representation of n.\n\t4.  Enter n and find the number of the most significant bit in the binary representation of it.\n\t5.  Enter integers n and i and print an integer whose i-th bit set to 1, and all other bits match the bits of the number n on the same positions.\n\t6.  Enter integers n and i and print an integer whose i-th bit reset to 0, and all other bits match the bits of the number n on the same positions.\n\t7.  Enter integers n and i and print an integer that has the i-th bit differs from the i-th bit of n, and all other bits match the bits numbers n at the same positions.\n\t8.  Enter the integer n (byte) and print the resulting number of cyclic shift by one bit to the left, i.e., the most significant bit moves to the position of the least, and all other bits are shifted by one discharge to the left.\n\t9.  Enter the integer n and determine how many times 11 occurs in binary representation of it.\n\t10. Swap two bits with the given numbers in the binary representation of a positive integer.\n\t11. Cross out the ith bit from the binary representation of a positive integer numbers (the lower bits of the i-th bit remain in place, the highest bits are shifted by one bit to the right).\n";
    cin>>answer;
    switch (answer)
    {
        case 1:
        {
            unsigned short n; 
            cout<<"\n\t1.  Enter an integer n and print 2^n.\n";
            cin>>n;
            cout<<(1<<n);
            break;
        }
        case 2:
        {
            unsigned short n; 
            cout<<"\n\t2.  Enter n and print a binary representation of it.\n";
            cin>>n;
            unsigned char t = n;
            for(int i=7; i>=0; cout<<((t>>i)&1), --i);
            break;
        }
        case 3:
        {
            unsigned short n, count = 0; 
            cout<<"\n\t3.  Enter n and find the number of repetitions of 1 in binary representation of n.\n";
            cin>>n;
            unsigned char t = n;
            while (n!=0)
            {
                if(n&1==1)
                    count++;
                n>>=1;
            }
            cout<<count;
            break;
        }
        case 4:
        {
            unsigned short n, j;
            cout<<"\n\t4.  Enter n and find the number of the most significant bit in the binary representation of it.\n";
            cin>>n;
            unsigned char t = n;
            
            for(int i=0; i<8; t>>=1, ++i)
            {
                if(t&1==1)
                    j=i;
            }
            cout<<j;
            break;
        }
        case 5:
        {
            unsigned short n, i;
            cout<<"\n\t5.  Enter integers n and i and print an integer whose i-th bit set to 1, and all other bits match the bits of the number n on the same positions.\n";
            cin>>n>>i;
            cout<<(n|(1<<i));
            break;
        }
        case 6:
        {
            unsigned short n, i;
            cout<<"\n\t6.  Enter integers n and i and print an integer whose i-th bit reset to 0, and all other bits match the bits of the number n on the same positions.\n";
            cin>>n>>i;
            cout<<(n&~(1<<i));
            break;
        }
        case 7:
        {
            unsigned short n, i;
            cout<<"\n\t7.  Enter integers n and i and print an integer that has the i-th bit differs from the i-th bit of n, and all other bits match the bits numbers n at the same positions.\n";
            cin>>n>>i;
            cout<<(n^(1<<i));
            break;
        }
        case 8:
        {
            unsigned short n;
            cout<<"\n\t8.  Enter the integer n (byte) and print the resulting number of cyclic shift by one bit to the left, i.e., the most significant bit moves to the position of the least, and all other bits are shifted by one discharge to the left.\n";
            cin>>n;
            unsigned char t = n;
            unsigned char m = (n>>7)&1;
            cout<<((t<<1)|m);
            break;
        }
        case 9:
        {
            unsigned short n, count = 0;
            cout<<"\n\t9.  Enter the integer n and determine how many times 11 occurs in binary representation of it.\n";
            bool b = false;
            cin>>n;
            unsigned char t = n;
            while(t!=0)
            {
                if(t&1==1)
                {
                    if(b) 
                        count++;
                    else
                        b=true;
                }
                else 
                    b=false;
                n>>=1;
            }
            cout<<count;
            break;
        }
        case 10:
        {
            unsigned short n, i, j;
            unsigned char t, k, l;
            cout<<"\n\t10. Swap two bits with the given numbers in the binary representation of a positive integer.\n";
            cin>>n>>i>>j;
            t=n;
            k=(t<<i)&1;
            l=(t<<k)&1;
            if((k==0)&&(l==1))
            {
                t|=(1<<i);
                t^=~(1<<j);
            }
            else if((k==1)&&(l==0))
            {
                t^=~(1<<i);
                t|=(1<<j);
            }
            cout<<(unsigned short)t;
            break;
        }
        case 11:
        {
            unsigned short n, i, p=0;
            cout<<"\n\t11. Cross out the ith bit from the binary representation of a positive integer numbers (the lower bits of the i-th bit remain in place, the highest bits are shifted by one bit to the right).\n";
            cin>>n>>i;
            unsigned char t=n, m=0;
            for(; p<i; p++, n>>=1)
            {
                m|=(n&1)<<p;
            }
            n>>=1;
            for(; n!=0; p++, n>>=1)
            {
                m|=(n&1)<<p;
            }
            cout<<(unsigned short)m;
            break;
        }
    
    default:
        break;
    }
}