#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;
using std::to_string;

template<typename It>  
bool my_next_permutation(It begin, It end)  
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
                        reverse(j, end);  
                        return true;  
                }  
  
                if (i == begin)  
                { 
						//cout << begin << " " << end << endl;
                        reverse(begin, end);
						//cout << "after reverse " << begin << " " << end << endl;				
                        return false;  
                }  
        }  
} 

int process(vector<string>& w) {
    int ans = 0;
	// sequence i through each letter in w[0]
    for (int i = 0; i < w[0].length(); i++)
		// sequence j through each letter in w[1]
		for (int j = 0; j < w[1].length(); j++) {
			if (w[0][i] == w[1][j]) {
				for (int k = j+2; k < w[1].length(); k++)
				// sequence h through each letter in w[2]
				for (int h = 0; h < w[2].length(); h++) {
					if (w[1][k] == w[2][h]) {
						for (int x = h+2; x < w[2].length(); x++)
						// sequence y through each letter in w[3]
						for (int y = 0; y < w[3].length(); y++) {
							if (w[2][x] == w[3][y]) {
								int width = k - j;
								int height = x - h;
								if (y - width >= 0 && i + height < w[0].length()) {
									if (w[3][y - width] == w[0][i + height]){
										ans++;
										//cout << "i=" << i << " j=" << j << " h=" << h << " y=" << y << endl;
									}
								}
							}
						}
					}
				}
			}
		}
    return ans;
}

int solution(vector<string> words) {
    sort(words.begin(), words.end());
    
    int cnt = 0, next_perm=1;
    do {
        cnt += process(words);
		next_perm=my_next_permutation(words.begin(), words.end());
    } while (next_perm);
    
    return cnt;
}

int main()
{
	
	vector<string> test={"","","",""};
	// array of array of strings
	vector<vector<string>>mystring={{"crossword", "square", "formation", "something"},	// 6
					{"anaesthetist", "thatch", "ethnics", "sabulous"},	// 0
					{"eternal", "texas", "chainsaw", "massacre"},		// 4
					{"africa", "america", "australia", "antarctica"},	// 62
					{"phenomenon", "remuneration", "particularly", "pronunciation"},	// 62
					{"onomatopoeia", "philosophical", "provocatively", "thesaurus"}};	// 20
	vector<int> myresult={6,0,4,62,62,20};

	int tally;
	for(int i=0; i<6; i++){
		tally=solution(mystring[i]);
		cout << "test[" << i << "] should be " << myresult[i] << " and is "<< tally << "\n";
	}
	
}
