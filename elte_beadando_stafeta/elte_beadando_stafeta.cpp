#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

using namespace std;

class Futo
{
public:
	int sorszam;
	int mettol;
	int meddig;


	Futo(int s=0, int tol=0, int ig=0)
	{
		sorszam = s;
		mettol = tol;
		meddig = ig;
	}

	operator std::string() const { return to_string(sorszam) + ": " + to_string(mettol) + " -> " +to_string(meddig) +"\n"; }
	
	~Futo()
	{
	}

};

std::ostream& operator<<(std::ostream& Str, Futo const& f) {
	return Str << string(f);
}


int main()
{
	// Beolvasás

	int N, K;
	cin >> K >> N;
	vector<Futo> futok(N);
	for (int i = 0; i < N; i++)
	{
		int I, E;
		cin >> I >> E;
		futok[i] = Futo(i+1, I, E);
	}

	// Megoldas

	sort(futok.begin(), futok.end(), [](Futo f1, Futo f2) {return f1.mettol < f2.mettol; });

	/** /
	cerr << endl;
	int j = 0;
	for (auto& i : futok) { cout << j++ << ". " << i; }
	/**/
	
	vector<int> kivalasztottak;

	int meddigjutunk = 0;
	int max = futok[0].meddig;
	int maxi = 0;
	int i = 0;
	while (meddigjutunk < K)
	{
		while (i<N && futok[i].mettol <= meddigjutunk && max < K)
		{
			if (max < futok[i].meddig)
			{
				max = futok[i].meddig;
				maxi = i;
			}
			i++;
		}
		meddigjutunk = max;
		kivalasztottak.push_back(futok[maxi].sorszam);
	}

	// Kiiras

	cout << kivalasztottak.size() << endl;

	for (int& ix : kivalasztottak)
		cout << ix << " ";
	
}


/*
200 20
0 100
75 81
53 86
55 200
86 90
182 191
198 200
34 100
191 195
46 102
32 179
88 181
8 10
112 122
155 156
56 178
112 166
157 200
129 146
162 186


*/