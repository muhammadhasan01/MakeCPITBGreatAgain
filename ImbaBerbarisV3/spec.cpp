#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int N1 = 1e5;
const long long INF = 1e9;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<long long> U;
    vector<long long> res;

    void InputFormat() {
        LINE(N);
        LINE(U);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N && N <= 100000);
        CONS(eachElementBetween(U, 1, INF));
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
        	"10",
			"5 1 4 2 3 7 6 8 9 10"
        });
        Output({
        	"0 0 1 1 2 5 5 7 8 9"
        });
    }

    void BeforeTestCase() {
        U.clear();
        res.clear();
    }

    void TestCases() {
    	for (int i = 0; i < 10; i++) {
    		CASE(N = rnd.nextInt(500, 1000), randomPermutation(N, U));
    	}
    	for (int i = 0; i < 10; i++) {
    		CASE(N = rnd.nextInt(N1 / 2, N1), randomPermutation(N, U));
    	}
    	for (int i = 0; i < 10; i++) {
    		CASE(N = rnd.nextInt(N1 / 2, N1), randomNumbers(N, U));
    	}
    }
 
private:

	void randomPermutation(int n, vector<long long>& u) {
		for (int i = 1; i <= n; i++) {
			u.push_back(i);
		}
		rnd.shuffle(u.begin(), u.end());
	}

	void randomNumbers(int n, vector<long long>& u) {
		for (int i = 1; i <= n; i++) {
			long long num = rnd.nextInt(100000, 1000000000);
			u.push_back(num);
		}
	}
};