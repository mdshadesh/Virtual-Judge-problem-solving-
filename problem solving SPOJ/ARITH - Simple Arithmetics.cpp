#include<bits/stdc++.h>

#define LL long long int

int eval(char *str, LL &n, char &op)
{
        n = 0;
        
        if(str[0]<'0' || str[0]>'9')
        {
                op = str[0];
                return 0;
        }
        
        for(int i=0; str[i]; i++)
                n = n*10 + (str[i]-'0');
        
        return 1;
}

int main()
{
        char s[100], op;
        LL  T;
        LL res, num;
        scanf("%lld", &T);
        while(T--)
        {
                res = 0;
                op = '+';
                while(scanf("%s",s)==1)
                {
                        if(eval(s, num, op))
                        {
                                switch(op)
                                {
                                        case '+': res += num; break;
                                        case '-': res -= num; break;
                                        case '*': res *= num; break;
                                        case '/': res /= num; break;
                                }
                        }
                        else if(op == '=')
                        {
                                printf("%lld\n", res);
                                break;
                        }
                }
        }
        return 0;
}
