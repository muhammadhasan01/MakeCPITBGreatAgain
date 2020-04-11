#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int NMax = 10;
const int MMax = 1e5;
const int KMax = 2e5;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, M, K;
    vector<int> U;
    vector<int> V;
    int res;

    void InputFormat() {
        LINE(N, M, K);
        LINES(U, V) % SIZE(K);
    }

    void OutputFormat() {
        LINE(res);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMax);
        CONS(1 <= M && M <= MMax);
        CONS(1 <= K && K <= KMax);
        CONS(eachElementBetween(U, 1, N));
        CONS(eachElementBetween(V, 1, M));
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
        	"1 4 4",
        	"1 2",
        	"1 2",
        	"1 1",
        	"1 1"
        });
        Output({
        	"0"
        });
    }

    void SampleTestCase2() {
    	Input({
    		"2 4 5",
    		"1 1",
    		"1 3",
    		"2 3",
    		"2 3",
    		"1 4"
    	});
    	Output({
    		"3"
    	});
    }

    void BeforeTestCase() {
        U.clear();
        V.clear();
    }

    void TestCases() {
    	for (int i = 0; i < 5; i++) {
    		CASE(N = rnd.nextInt(1, NMax / 2), M = rnd.nextInt(1, MMax / 2), K = rnd.nextInt(1, KMax / 2), randomQuery(N, M, K, U, V));
    	}
    	for (int i = 0; i < 5; i++) {
    		CASE(N = rnd.nextInt(NMax / 2, NMax), M = rnd.nextInt(MMax / 2, MMax), K = rnd.nextInt(KMax / 2, KMax), randomQuery(N, M, K, U, V));
    	}
    }
 
private:

	void randomQuery(int n, int m, int k, vector<int>&u, vector<int>& v) {
		for (int i = 0; i < k; i++) {
			int x = rnd.nextInt(1, n);
			int y = rnd.nextInt(1, m);
			u.push_back(x);
			v.push_back(y);
		}
	}
	
};