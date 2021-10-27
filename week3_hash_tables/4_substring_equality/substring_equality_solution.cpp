#include <iostream>
#include <stdlib.h>
#include<math.h>
#include<vector>

using namespace std;

class Solver {
	string s;
	long long m1,m2;
	vector<long long>h1;
	vector<long long>h2;
	long long x;
public:
	Solver(string s) : s(s) {
		// initialization, precalculation
		m1=1000000007;
		m2=1000000009;

        x=263;

		h1.resize(s.size()+1);
		h2.resize(s.size()+1);
		h1[0]=h2[0]=0;

		for(int i=1;i<h1.size(); i++) {
           h1[i]=((x*h1[i-1])%m1+s[i-1]%m1)%m1;
	       h2[i]=((x*h2[i-1])%m2+s[i-1]%m2)%m2;
		}
	}
	bool ask(int a, int b, int l) {
    unsigned long long x_l1=pow(x,l);
    x_l1%=m1;
	unsigned long long x_l2=pow(x,l);
	 x_l2%=m2;
	long long Ha1=(h1[a+l]%m1-(x_l1*h1[a])%m1)%m1;
	long long Ha2=(h2[a+l]%m2-(x_l2*h2[a])%m2)%m2;
	long long Hb1=(h1[b+l]%m1-(x_l1*h1[b])%m1)%m1;
	long long Hb2=(h2[b+l]%m2-(x_l2*h2[b])%m2)%m2;
	 if(Ha1==Hb1 && Ha2==Hb2) {
		return true;
	 }
	return false ;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
