#include <iostream>
#include <vector>
const int ssize = 1000;
const int climit = 1000;

using namespace std;

struct Range_error : out_of_range {
	int index;
    Range_error(int i) :out_of_range("Range error: " +to_string(i)), index(i) { }
};

struct Exit : runtime_error {
	Exit() : runtime_error("Exit") {}
};

inline void error(const string& s)
{
	throw runtime_error(s);
};

int main()
{
    char s[ssize];
    int c[climit];
    int T,N;
    cout << "Enter your case: ";
    cin >> T;
    if (T < 1 || T > 10) error("please input case between 1 and 10");
    vector<int> out;
    for (int b = 1; b <= T; b++)
    {
        vector <char> S;
        vector <int> C;
        cout << "Input friends: ";
        cin >> N;
        if (N < 1 || N > 1000) error("please input friend between 1 and 1000");
        ////////////////////////////input baju////////////////////////////////////
        for (int i = 0; i < N; i++)
        {
            cin >> s[i] >> c[i];
            S.push_back(s[i]);
            C.push_back(c[i]);
            if (s[i]!='S')
            {
                if (s[i]!='M')
                {
                    if (s[i]!='L')
                    {
                        error("please input S, M, or L");
                    }
                }
            }
            if (c[i] < 1 || c[i] > 1000) error("please input colour between 1 and 1000");
        }
        ///////////////////////mencari elemen yang sama///////////////////////////////
        /////////////////////lalu dimasukkan ke dalam vektor//////////////////////////

        vector<int> jml;
        for(int i=0; i<S.size(); i++)
        {
            for(int j=i+1;j<S.size();j++)
            {
                if(S[i]==S[j])
                {
                    if (C[i]==C[j])
                    {
                        jml.push_back(C[i]);
                        S.erase(S.begin()+j);
                        C.erase(C.begin()+j);
                        break;
                    }
                }
            }
        }
        
        //////////////////////////perhitungan diskon////////////////////////////////
        //////////////////dengan menghitung banyaknya elemen vektor/////////////////
        ////////////////////lalu dimasukkan ke vektor output////////////////////////
        if (jml.size()!=0)
        {
            int jum = jml.size()*10;
            out.push_back(jum);
        }
        else if (jml.size()==0)
        {
            int jum = 0;
            out.push_back(jum);
        }
    }
    /////////////////////////////////////output/////////////////////////////////////
    cout << endl;
    for(int i = 0; i < out.size(); i++)
    {
        int x = i + 1;
        cout << "Case #"<< x << ": " <<out[i]<< endl;
    }
    
    return 0;
}
/*
sumber:
http://www.nblognlife.com/2017/05/mengenal-vector-pada-c.html
http://www.cplusplus.com/reference/vector/vector/erase/
*/