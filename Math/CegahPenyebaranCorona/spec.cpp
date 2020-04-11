#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAXKHN = 1e5;
const long long INF = 1e12;

class ProblemSpec : public BaseProblemSpec {
protected:
    int k, h, n, res;
    vector<long long> a;

    void InputFormat() {
        LINE(k, h, n);
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
        CONS(1 <= k && k <= 100000);
        CONS(1 <= h && h <= 100000);
        CONS(1 <= n && n <= 100000);
        CONS(eachElementBetween(a, 0, INF));
    }

private:
    bool eachElementBetween(const vector<long long>& v, long long lo, long long hi) {
        for (long long x : v) {
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
        	"2 4 3",
			"2 5 4"
        });
        Output({
        	"5"
        });
    }

    void SampleTestCase2() {
        Input({
        	"3 4 6",
			"2 6 12 26 10 36"
        });
        Output({
        	"14"
        });
    }

    void BeforeTestCase() {
        a.clear();
    }

    void TestCases() {
        CASE(k = 50000, h = 100000, n = 1, a = {0});
        CASE(k = 2, h = 5, n = 5, randomNumbers(0, 30, a));
        CASE(k = 5, h = 3, n = 10, randomNumbers(0, 30, a));
        CASE(k = 6, h = 8, n = 1000, randomNumbers(0, 335922, a));
        CASE(k = 2, h = 20, n = 500, randomNumbers(0, 1048574, a));
        CASE(k = 3, h = 17, n = 2000, randomNumbers(0, 64570080, a));
        CASE(k = 1, h = 100, n = 15, randomNumbers(0, 99, a));
        CASE(k = 1, h = 100000, n = 100000, randomNumbers(80000, 99999, a));
    	for (int i = 0; i < 10; i++) {
    		CASE(k = rnd.nextInt(1, 100000), h = rnd.nextInt(100, 100000), n = rnd.nextInt(1000, 100000), randomNumbers(0, INF, a));
    	}
    }
 
private:
	void randomNumbers(long long minn, long long maxn, vector<long long>& a) {
		for (int i = 1; i <= n; i++) {
			long long num = rnd.nextLongLong(minn, maxn);
			a.push_back(num);
		}
	}
};