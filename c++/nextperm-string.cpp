#include <vector>  
#include <iostream>  
#include <algorithm> 
#include <string> 
  
using namespace std;
 
template<typename It> 
void pswap(It l, It r) {
    It temp = l;
    l = r;
    r = temp;
}
  
template<typename It> 
bool next_permutation(It begin, It end)  
{  
        if (begin == end)  
                return false;  
  
        It i = begin;  
        ++i;  
        if (i == end)  
                return false;  
  
        i = end;  
        --i;  
  
        while (true)  
        {  
                It j = i;  
                --i;  
  
                if (*i < *j)  
                {  
                        It k = end;  
  
                        while (!(*i < *--k))  
                                /* pass */;  
  
                        iter_swap(i, k); 
						//pswap(i, k);						
                        reverse(j, end);  
                        return true;  
                }  
  
                if (i == begin)  
                {  
                        reverse(begin, end);  
                        return false;  
                }  
        }  
}  
  
int main()  
{  
        vector<int> v = { 1, 2, 3, 4 };
		vector<string>mystring={"crossword", "square", "formation", "something"};
  
        do  
        {  
                for (int i = 0; i < 4; i++)  
                {  
                        cout << mystring[i] << " ";  
                }  
                cout << endl;  
        }  
        while (::next_permutation(mystring.begin(), mystring.end()));  
} 