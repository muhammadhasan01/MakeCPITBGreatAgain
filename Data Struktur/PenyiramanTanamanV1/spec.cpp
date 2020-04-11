#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int N1 = 1e5;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, Q;
    vector<int> U;
    vector<vector<int>> V;
    vector<vector<long long>> res;

    void InputFormat() {
        LINE(N);
        LINE(U);
        LINE(Q);
        LINES(V) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(res);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N && N <= N1);
        CONS(1 <= Q && Q <= N1);
        CONS(eachElementBetween(U, 0, N1));
        for (auto v : V) {
        	CONS(eachElementBetween(v, 1, N1));
        }
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
        	"5",
			"1 3 5 0 1",
			"6",
			"2 1 4",
			"1 3",
			"2 1 4",
			"2 2 4",
			"1 5",
			"2 4 5"
        });
        Output({
        	"5 9",
        	"6 10",
        	"6 9",
        	"2 2"
        });
    }

    void BeforeTestCase() {
        U.clear();
        for (auto v : V) v.clear();
        V.clear();
    	for (auto e : res) e.clear();
        res.clear();
    }

    void TestCases() {
    	for (int i = 0; i < 10; i++) {
    		CASE(N = rnd.nextInt(500, 1000), Q = rnd.nextInt(500, 1000), randomNumber(N, U), randomAsk(N, Q, V));
    	}
    	for (int i = 0; i < 10; i++) {
    		CASE(N = rnd.nextInt(N1 / 2, N1), Q = rnd.nextInt(N1 / 2, N1), randomNumber(N, U), randomAsk(N, Q, V));
    	}
    }
 
private:

	void randomNumber(int n, vector<int>& u) {
		for (int i = 0; i < n; i++) {
			int num = rnd.nextInt(0, N1);
			u.push_back(num);
		}
	}

	void randomAsk(int n, int q, vector<vector<int>>& v) {
		v.push_back({2, 1, n});
		for (int i = 1; i < q; i++) {
			int tp = rnd.nextInt(1, 2);
			if (tp == 1) {
				int num = rnd.nextInt(1, n);
				v.push_back({1, num});
			} else {
				int l = rnd.nextInt(1, n);
				int r = rnd.nextInt(l, n);
				v.push_back({2, l, r});
			}
		}
	}
	
};