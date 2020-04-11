#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int N1 = 1e5;
const long long N2 = 1e18;

class ProblemSpec : public BaseProblemSpec {
protected:
    long long N;
    int Q;
    vector<long long> U;
    vector<long long> res;

    void InputFormat() {
        LINE(N, Q);
        LINES(U) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(res);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N && N <= N2);
        CONS(1 <= Q && Q <= 100000);
        CONS(eachElementBetween(U, 1, N));
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
        	"5 3",
        	"1",
        	"2",
        	"3"
        });
        Output({
        	"1",
        	"2",
        	"3"
        });
    }

    void BeforeTestCase() {
        U.clear();
        res.clear();
    }

    void TestCases() {
    	CASE(N = 5, Q = 5, randomNumbers(N, Q, U));
    	for (int i = 0; i < 10; i++) {
    		CASE(N = rnd.nextLongLong(N1 / 2, N1), Q = rnd.nextInt(N1 / 2, N1), randomNumbers(N, Q, U));
    	}
    	for (int i = 0; i < 10; i++) {
    		CASE(N = rnd.nextLongLong(N2 / 2, N2), Q = rnd.nextInt(N1 / 2, N1), randomNumbers(N, Q, U));
    	}
    }
 
private:

	void randomNumbers(long long n, int q, vector<long long>& u) {
		for (int i = 1; i <= q; i++) {
			long long num = rnd.nextLongLong(1, n);
			u.push_back(num);
		}
	}
};