#include <iostream>
#include <time.h>
#include <cstdlib>
#include <random>
using namespace std;

constexpr int L = 1e6;

/* sito */
bool sito[L];
void eratostenes(int n) {
	/* generate arr */
	for (int i=2; i<n; i++) {
		if (sito[i]) continue;
		for (int j=2*i; j<n; j+=i) {
			sito[j] = 1;
		}

	}

	/* print arr */
	for (int i=1; i<n; i++)
		cout << i << (sito[i] ? " PRIME" : " NOT PRIME") << '\n';
}

/* nwd */
int nwd(int a, int b){
	int r = (a>b) ? a%b : b%a;
	if (!r) return (a>b) ? b : a;
	return (a>b) ? nwd(r,b) : nwd(r,a);
}

/* nww */
int nww(int a, int b){
	return a*b / nwd(a,b);
}
/* fib */ 
int fib[L];
void arrayFib(int n){
	fib[0] = 0;
	fib[1] = 1;

	for (int i=2; i<n; i++) 
		fib[i] = fib[i-1] + fib[i-2];

	for (int i=0; i<n; i++)
		cout << fib[i] << ' ';

} 

int recursiveFib(int n){
	if (n == 1) return 1;
	return recursiveFib(n-1) + recursiveFib(n-2);
}

/* pierwiastek */ 
float NewSqrt(float a){
	float px, x = a/2;

	do{
		px = x;
		x = (px + a/px) * 0.5;
	} while(x != px);

	return x;
}
/* lider */ 
int arr[L];
void lider(int n){
	int occurences = 0;
	int lead;

	for (int i=0; i<n; i++) {
		if (occurences == 0) {
			lead = arr[i];
			occurences = 1;
		} else {
			if (arr[i] == lead) occurences++;
			else occurences--;
		}
	}
	occurences = 0;
	for (int i=0; i<n; i++)
		if (arr[i] == lead) occurences++;

	if (occurences > n/2) cout << lead << '\n';
	else cout << "No lead\n";
}
/* rozklad na czynniki */ 
void rozklad(int x){
	int i=2;
	do{
		if (x%i == 0) {
			x = x/i;
			if (x != 1) cout << i << " * ";
			else cout << i << '\n';
		}
		else i++;
	} while(x != 1);

}
/* zamiana systemow */

// https://ostry.x25.pl/viewtopic.php?f=13&t=61
// partyswietlik
// skleroza

/* horner zamiana */
void zamianaHorner(string num, int sys){
	string t;
	int out;

	t = num[0];
	out = atoi(t.c_str());

	for (int i=1; i<=num.size(); i++){
		t = num[i];
		out = out * sys + atoi(t.c_str());
	}
	cout << out << '\n';
}
/* horner wielomiany */ 
float coef[L];
float polynomialVal(int deg, float x){
	float ans = coef[0];
	for (int i=1; i<=deg; i++)
		ans = ans * x + coef[i];
	return ans;
}
/* sort - long*/
void bubbleSort(int n){
	for (int i=0; i<n; i++)
		for (int j=0; j<n-i; j++)
			if(arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
}


int main() {
    int a, b;
    cin >> a >> b;

    cout << nwd(a,b);
    
}
