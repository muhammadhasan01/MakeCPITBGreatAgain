#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAXN = 1e5;
const int MINA = -1e9;
const int MAXA = 1e9;

class ProblemSpec : public BaseProblemSpec {
protected:
    int n;
    long long res;
    vector<int> a;

    void InputFormat() {
        LINE(n);
        LINE(a);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= n && n <= 100000);
        CONS(eachElementBetween(a, MINA, MAXA));
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"4",
			"2 5 4 2"
        });
        Output({
        	"13"
        });
    }

    void SampleTestCase2() {
        Input({
        	"5",
			"-5 2 3 -2 4"
        });
        Output({
        	"7"
        });
    }

    void BeforeTestCase() {
        a.clear();
    }

    void TestCases() {
    	for (int i = 0; i < 5; i++) {
    		CASE(n = rnd.nextInt(1, 1000), randomNumbers(MINA, MAXA, a));
    	}
    	CASE(n = rnd.nextInt(1, 1000), randomNumbers(MINA, -1, a));
    	CASE(n = rnd.nextInt(1, 1000), randomNumbers(MAXA / 2, MAXA, a));
        for (int i = 0; i < 5; i++) {
    		CASE(n = rnd.nextInt(10000, 100000), randomNumbers(MINA, MAXA, a));
    	}
    	CASE(n = rnd.nextInt(10000, 100000), randomNumbers(MINA, -1, a));
    	CASE(n = rnd.nextInt(10000, 100000), randomNumbers(MAXA / 2, MAXA, a));
    }
 
private:
	void randomNumbers(int minn, int maxn, vector<int>& a) {
		for (int i = 1; i <= n; i++) {
			int num = rnd.nextInt(minn, maxn);
			a.push_back(num);
		}
	}
};